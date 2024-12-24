#include "Simulation.hpp"
void Simulation::Run(const string inputFolderName){
    using std::ifstream;

    // otvaranje datoteka
    const string prefix = "..\\input\\";

    string adjacencyMatrixFilePath = prefix + inputFolderName + "\\matricaGrada.csv";
    string tripsFilePath = prefix + inputFolderName + "\\upitiKorisnika.csv";
    string vehiclesFilePath = prefix + inputFolderName + "\\vozila.txt";

    ifstream adjacencyMatrixFile(adjacencyMatrixFilePath);
    ifstream tripsFile(tripsFilePath);
    ifstream vehiclesFile(vehiclesFilePath);

    if (!adjacencyMatrixFile.is_open() || !tripsFile.is_open() || !vehiclesFile.is_open())
        throw ClosedStreamException();

    // smjestanje podataka iz njih u memoriju i zatvaranje
    Graph graph(adjacencyMatrixFile);
    vector<Trip> trips = Utility::getTripsFromCSVFile(tripsFile);
    vector<Vehicle> vehicles = Utility::getVehiclesFromCSVFile(vehiclesFile);

    // inicijalizacija pomocnih struktura
    Time time(vehicles, graph);
    Stats stats(vehicles);

    adjacencyMatrixFile.close();
    tripsFile.close();
    vehiclesFile.close();

    CheckForInputExceptions(graph, trips, vehicles);
    MainLoop(graph, trips, vehicles, time, stats);
    stats.logAllStats();
}

// glavna petlja simulacije koja u sustini samo prolazi kroz svaki korisnicki upit redom kako su zadani u datoteci
void Simulation::MainLoop(Graph& graph, vector<Trip>& trips, vector<Vehicle>& vehicles, Time& time, Stats& stats){
    int tripsRemaining = trips.size();
    graph.getAllPathsAndDistances();
    for (const auto& trip : trips){
        const int userLocation = trip.from;
        const int userDestination = trip.to;

        BST distanceTree;

        if (allVehiclesBusy(vehicles))
            passTime(time, vehicles, graph, stats, tripsRemaining);
    
        constructVehicleTree(userLocation, userDestination, distanceTree, vehicles, graph);
        invokeVehicle(userLocation, userDestination, distanceTree, graph, stats);
        tripsRemaining--;
    }

    // teoretski nedostizan vremenski skok koji mora da zavrsi sve preostale voznje
    time.jump(INT_MAX / 2, stats);
}

#pragma region Secondary

// provjera potencijalnih funkcionalnih ogranicenja sa ulaznim podacima
void Simulation::CheckForInputExceptions(Graph& graph, vector<Trip>& trips, vector<Vehicle>& vehicles){
    if (graph.getNumNodes() == 0) 
        throw EmptyGraphException();

    if (trips.size() == 0) 
        throw NoTripsException();

    if (vehicles.size() == 0) 
        throw NoVehiclesException();

    if (Utility::getSmallestVehicleLocation(vehicles) < 0 || Utility::getLargestVehicleLocation(vehicles) >= graph.getNumNodes()) 
        throw VehicleOutOfBoundsException();

    if (Utility::getSmallestTripLocation(trips) < 0 || Utility::getLargestTripLocation(trips) >= graph.getNumNodes()) 
        throw UserOutOfBoundsException();

    if (Utility::checkForVehicleStartLocationOverlaps(vehicles))
        throw VehicleOverlapException();
}

// provjera da li je svako vozilo zauzeto - koristi se kao uslov za vremenski skok
bool Simulation::allVehiclesBusy(const vector<Vehicle>& vehicles){
    for (const auto& v : vehicles)
        if (!v.busy)
            return false;
    return true;
}

// trazenje vozila sa najkracim preostalim putem do destinacije
Vehicle& Simulation::getShortestTravelTime(vector<Vehicle>& vehicles, Graph& g){
    int min_i = 0;

    for (int i = 1; i < vehicles.size(); i++){
        const Vehicle& currVehicle = vehicles[i];
        const Vehicle& minVehicle = vehicles[min_i];
        int current = 
            g.getDistanceFromTo(currVehicle.location, currVehicle.destination) - currVehicle.elapsed;

        int min = 
            g.getDistanceFromTo(minVehicle.location, minVehicle.destination) - minVehicle.elapsed;

        if (current < min)
            min_i = i;
    }

    return vehicles[min_i];
}

// vrijeme da vozilo iz argumenta dodje do destinacije
inline int Simulation::getTimeUntilArrival(const Vehicle& vehicle, Graph& g){
    int base = g.getDistanceFromTo(vehicle.location, vehicle.destination);
    int specific = base - vehicle.elapsed;

    return specific;
}

// konstrukcija BST-a ciji je kljuc udaljenost svakog vozila od korisnicke destinacije
// cvorovi BST-a takodje uzimaju i reference na odgovarajuca vozila
void Simulation::constructVehicleTree(int userLocation, int userDestination, BST& tree, 
    vector<Vehicle>& vehicles, Graph& graph){

    for (auto& vehicle : vehicles){
        const int vehicleLocation = vehicle.location;
        int distance = graph.getDistanceFromTo(userLocation, vehicleLocation);

        BSTNode* newNode = new BSTNode(distance, vehicle);
        tree += newNode;
    }
}

// trazimo vozilo koje najskorije dolazi do destinacije i vrsimo vremenski skok vrijednosti
// njegovog preostalog vremena do destinacije
void Simulation::passTime(Time& time, vector<Vehicle>& vehicles, Graph& graph, Stats& stats, int numTripsRemaining){
    Vehicle& soonestToArrive = getShortestTravelTime(vehicles, graph);
    int timeUntilArrival = getTimeUntilArrival(soonestToArrive, graph);
    
    stats.totalUserWaitTime += timeUntilArrival * numTripsRemaining;
    stats.incrementTotalDistance(soonestToArrive, timeUntilArrival);

    time.jump(timeUntilArrival, stats);
}

// dodjela konkretnog vozila nekom korisniku (tacnije korisnickom upitu)
void Simulation::invokeVehicle(int userLocation, int userDestination, BST& tree, Graph& graph, Stats& stats){
    // zagarantovano je da cemo naici na nezauzeto vozilo
    int i = 0;
    while(true){
        BSTNode* current = tree.getMin(i++);
        if (current->m_vehicle.busy)
            continue;
        
        auto selectVehicle = [userLocation, userDestination, current]() -> const Vehicle& {
            Vehicle& sv = current->m_vehicle;
            sv.userLocation = userLocation;
            sv.destination = userDestination;
            sv.busy = true;
            sv.elapsed = 0; 

            return sv;
        };

        const Vehicle& selectedVehicle = selectVehicle();
        
        int distance = graph.getDistanceFromTo(selectedVehicle.location, userLocation);
        string path = graph.getPathFromTo(selectedVehicle.location, userLocation);

        std::printf("> %s [ID: %d] krece po korisnika putanjom: %s [dist: %d]\n",
            selectedVehicle.name.c_str(), selectedVehicle.id, path.c_str(), distance);
        
        stats.totalUserWaitTime += distance;

        break;
    }
}

#pragma endregion