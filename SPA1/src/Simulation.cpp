#include "Simulation.h"
using namespace Simulation;

constexpr int minVehicles = 1, maxPassengerVehicles = 100, maxCargoVehicles = 50;
// Pokretanje simulacije za putnicka vozila (passenger vehicles - PV)
void Simulation::RunPV(const int numVehicles, const short priorityAgeThreshold){
    if (numVehicles >= minVehicles && numVehicles <= maxPassengerVehicles)
    {    
        PVQueue queue;
        std::printf("Pokrecemo simulaciju sa %d putnickih vozila.\n", numVehicles);
        addVehiclesToPVQueue(queue, numVehicles, priorityAgeThreshold);
        clearPVQueue(queue);
    }
    else{
        std::printf("Broj vozila nije validan. Ocekuje se sa segmenta [%d, %d].\n",
        minVehicles, maxPassengerVehicles);
    }
}

// Pokretanje simulacije za teretna vozila (cargo vehicles - CV)
void Simulation::RunCV(const int numVehicles, const int numCargoTypes, 
    const std::string filename){
    if (numVehicles >= minVehicles && numVehicles <= maxCargoVehicles)
    {    
        CVQueue queue;
        std::printf("Pokrecemo simulaciju sa %d teretnih vozila.\n", numVehicles);
        if (addVehiclesToCVQueue(queue, numVehicles, numCargoTypes, filename))
            clearCVQueue(queue);
    }
    else {
        std::printf("Broj vozila nije validan. Ocekuje se sa segmenta [%d, %d].\n",
        minVehicles, maxCargoVehicles);
    }
}

// Sistematsko dodavanje numVehicles p. vozila sa nasumicnim brojem i godinama putnika
// u prioritetni red reprezentovan ulancanom listom:
//
// [PVQueue <- PVLinkedList <- PVListNode <- PassengerVehicle]
static void Simulation::addVehiclesToPVQueue(PVQueue& queue, const int numVehicles, 
    const short priorityAgeThreshold){
    for (int i = 0; i < numVehicles; i++){
        // generisemo nasumican broj putnika rucno,
        // dok konstruktor za PassengerVehicle svakom
        // od njih dodjeljuje nasumican broj godina
        // uz minimalno jednog sa >18
        int numPassengers = Utility::RandomInt(1, 5);
        PassengerVehicle newVehicle(numPassengers);

        std::printf("U red ");

        if (newVehicle.hasChild(priorityAgeThreshold)){
            queue.enqueuePriority(newVehicle);
            std::printf("prioritetno ");
        }
        else{
            queue.enqueue(newVehicle);
        }
        std::printf("ulazi vozilo [ID: %d] sa %d putnika.\n",
        newVehicle.getId(), numPassengers);
        newVehicle.displayAllPassengers();
    }
}

// Sistematsko pregledanje pasosa svakog putnika u putnickom vozilu:
// 1. izbacuje se prvo vozilo iz reda
// 2. svi putnici se smjestaju u odvojen red koji reprezentuje poredak po kom
//      predaju pasose cariniku
// 3. carinik ih skidanjem iz tog "reda" pregleda redoslijedom kojim su mu predati
// 4. putnici se pustaju preko granice
//
// [PVQueue <- PVLinkedList <- PVListNode <- PassengerVehicle]
// PVQueue destruktor dealocira PVLinkedList; sve operacije brisanja iz PVLL
// dealociraju pojedinacne PVListNode objekte; PVLL ce uvijek biti ispraznjena do kraja
static void Simulation::clearPVQueue(PVQueue& queue){

    // predavanje pasosa iz jednog vozila jedan po jedan i unosenje u novi red
    auto handOverPassports = [](PassengerVehicle& vehicle, 
                PassengerQueue& queue) -> void {
        std::vector<Passenger>& passengers = vehicle.getPassengersRef();
        for (Passenger p : passengers){
            queue.enqueue(p);
            std::printf("Putnik [ID: %d] (%d god) predaje pasos.\n", p.getId(), p.getAge());
        }
    };

    // uzimanje pasosa iz reda (redoslijedom koji su predati) i
    // provjera jedan po jedan, te pustanje vozila po zavrsetku
    auto checkPassports = [](PassengerQueue& queue, int vehicleId) -> void {
        Passenger p;
        while (queue.dequeue(p)){
            std::printf("Carinik pregleda i vraca pasos putniku [ID: %d]\n", p.getId());
        }
        std::printf("> Vozilo [ID: %d] se pusta preko granice.\n\n", vehicleId);
    };
    
    // sistematska provjera vozila jedno po jedno koristeci funkcije
    // definisane iznad
    PassengerVehicle current;
    while(queue.dequeue(current)){
        std::printf("> Novo vozilo na redu [ID: %d] sa %d putnika.\n", 
        current.getId(), current.getPassengersRef().size());

        PassengerQueue currentVehiclePassengers;
        handOverPassports(current, currentVehiclePassengers);
        checkPassports(currentVehiclePassengers, current.getId());
    }
}

// Sistematsko dodavanje numVehicles t. vozila sa nasumicnom i jedinstvenom robom
// zanemarljive kolicine numCargoTypes vrsta
//
// [CVQueue <- CVLinkedList <- CVListNode <- CargoVehicle <- CargoStack]
static bool Simulation::addVehiclesToCVQueue(CVQueue& queue, 
    const int numVehicles, const int numCargoTypes, const std::string filename){

    // prije svega pokusavamo otvoriti datoteku na adresi:
    // {workspace}/../cargo_files/{filename}
    const std::string path_prefix = "../cargo_files/";
    const std::string filepath = path_prefix + filename;

    std::cout << "Trazimo robu u datoteci na putanji '" << filepath << "'..." << std::endl;
    std::ifstream file(filepath);
    if (!file.is_open()){
        std::printf("Datoteka sa robom se ne moze otvoriti. Prekidanje...\n");
        return false;
        // ^ ako ne uspijemo otvoriti datoteku, vracamo false cime se 
        // onemogucava nastavak CV simulacije jer predstojeca funkcija
        // Simulation::clearCVQueue zavisi od rezultata izvrsavanja ove
    }
    std::cout << "Datoteka '" << filename << "' uspjesno pronadjena i otvorena." << std::endl;

    // ucitavanje robe u memoriju u obliku vektora stringova
    auto getAllCargoNames = [](std::ifstream& stream) -> std::vector<std::string> {
        std::vector<std::string> ret;

        std::string currentLine;
        while (std::getline(stream, currentLine))
            ret.push_back(currentLine);   

        stream.close();
        return ret;
    };

    // kreiranje vektora sa n nasumicne jedinstvene robe, inicijalizacija
    // novog vozila sa stekom te robe i formalno dodavanje u CVQueue
    auto createAndEnqueue = [](const std::vector<std::string> cargoNames,
        const int numCargoTypes, CVQueue& queue) -> void {

        std::vector<std::string> randomPickedCargoNames = 
            Utility::RandomUnique(cargoNames, numCargoTypes);

        std::vector<Cargo> randomCargo;
        for (std::string s : randomPickedCargoNames)
            randomCargo.push_back(Cargo(s));
    
        CargoVehicle newVehicle(randomCargo);

        std::printf("\nU red ulazi teretno vozilo [ID: %d]\n", newVehicle.getId());
        std::printf("Roba:\n");
        newVehicle.logCargo();
        queue.enqueue(newVehicle);
    };

    // primjena svih funkcija definisanih iznad
    std::vector<std::string> cargoNames = getAllCargoNames(file);
    for (int i = 0; i < numVehicles; i++)
        createAndEnqueue(cargoNames, numCargoTypes, queue);

    return true;
}

// Sistematsko pregledanje svakog teretnog vozila: 
// 1. izbacuje se prvo vozilo iz reda
// 2. njegova roba se skida sa CargoStacka (prikolica) i stavlja na odvojen CargoStack (tableStack)
//      kojim se logicki reprezentuje sto za provjeru robe
// 3. po zavrsetku, roba se skida sa tableStacka i vraca u prikolicu; prebacivanje sa steka na stek i nazad
//      garantuje finalni poredak robe identican onom sa kojim se teretno vozilo pojavilo na granici
// 4. teretno vozilo se pusta preko granice u prvobitnom stanju
// (sve ovo se radi operacijama nad stekom, cime dobijamo trazenu logiku i finalni poredak)
//
// [CVQueue <- CVLinkedList <- CVListNode <- CargoVehicle <- CargoStack]
// CVQueue destruktor dealocira CVLinkedList; sve operacije brisanja iz CVLL
// dealociraju pojedinacne CVListNode objekte; CVLL ce uvijek biti ispraznjena do kraja;
// dealokacijom pojedinacnih CVLN objekata se unistava i njihov CargoVehicle,
// sa njim i njegov vlastiti CargoStack ciji destruktor dealocira dinamicki
// niz koji ga sacinjava
static void Simulation::clearCVQueue(CVQueue& queue){
    queue.displayAll();

    CargoVehicle currentVehicle;
    CargoStack tableStack;
    while (queue.dequeue(currentVehicle)){
        std::printf("> Pocinje proces pregleda robe za vozilo [ID: %d]\n",
        currentVehicle.getId());

        CargoStack& currentStack = currentVehicle.m_cargoStack;
        Cargo currentCargo;
        while (currentStack.pop(currentCargo)){
            std::cout << "Iz prikolice istovaramo " << currentCargo.getName() <<
            " i stavljamo na sto." << std::endl;
            tableStack.push(currentCargo);
        }
        std::printf("> Uspjesno pregledanje robe za vozilo [ID: %d]\n",
        currentVehicle.getId());

        while (tableStack.pop(currentCargo)){
            std::cout << "Vracamo " << currentCargo.getName() <<
            " sa stola nazad u prikolicu." << std::endl;

            currentStack.push(currentCargo);
        }

        std::printf("> Teretno vozilo [ID: %d] je pusteno preko granice.\n\n",
        currentVehicle.getId());
    }
}

// Nikola Markovic (2024)
// ETFBL, Strukture podataka i algoritmi, 2024/25.