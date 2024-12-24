#include "Utility.hpp"
#include <algorithm>
// za obradjivanje pojedinacnih CSV linija se pretpostavlja da su zadate korektno, tj.
// pretpostavlja se da ulazna CSV linija ne pocinje i ne zavrsava zarezom, da nema razmaka itd.
// besmislene ulazne podatke bi trebalo da pokrivaju izuzeci unutar Simulation::Run()

int Utility::getLargestVehicleLocation(const vector<Vehicle>& vehicles){
    int max = -INT_MAX;

    for (const auto& v : vehicles)
        if (v.location > max)
            max = v.location;
    
    return max;
}

int Utility::getSmallestVehicleLocation(const vector<Vehicle>& vehicles){
    int min = INT_MAX;

    for (const auto& v : vehicles)
        if (v.location < min)
            min = v.location;
    
    return min;
}

int Utility::getLargestTripLocation(const vector<Trip>& trips){
    int max = -INT_MAX;

    for (const auto& t : trips){
        if (t.from > max)
            max = t.from;
        if (t.to > max)
            max = t.to;
    }
    
    return max;
}

int Utility::getSmallestTripLocation(const vector<Trip>& trips){
    int min = INT_MAX;

    for (const auto& t : trips){
        if (t.from < min)
            min = t.from;
        if (t.to < min)
            min = t.to;
    }
    
    return min;
}

bool Utility::checkForVehicleStartLocationOverlaps(const vector<Vehicle>& vehicles){
    vector<int> startLocations;
    for (const auto& vehicle : vehicles)
        startLocations.push_back(vehicle.location);
    
    std::sort(startLocations.begin(), startLocations.end());
    
    for (int i = 0; i < startLocations.size() - 1; i++)
        if (startLocations[i] == startLocations[i + 1])
            return true;
    return false;
}

// broj elemenata u datoj CSV liniji
int Utility::getCSVLineIntCount(const string line){
    int count = 0;
    for (int i = 0; i < line.length(); i++)
        if (line[i] == ',')
            count++;
    
    return count + 1;
}

// obrada CSV linija sazdanih iskljucivo od intova i vracanje u obliku int vektora
vector<int> Utility::parseCSVLineToIntVector(const string line){
    vector<int> res;
    string current;
    for (int i = 0; i < line.length(); i++){
        if (line[i] == ','){
            int toAdd = std::stoi(current);
            res.push_back(toAdd);
            current = "";
            continue;
        }

        current += line[i];
    }
    res.push_back(std::stoi(current));
    return res;
}

// vracanje svih linija iz CSV datoteke u obliku inta stringova
// gdje i-ti string vektora predstavlja i-tu liniju u datoteci
// (0-indeksirano)
vector<string> Utility::getAllCSVLinesFromFile(std::ifstream& file){
    vector<string> res;
    string current;

    while (std::getline(file, current))
        res.push_back(current);
    
    return res;
}

// obrada datoteke sa upitima korisnika i vracanje u obliku vektora istih
vector<Trip> Utility::getTripsFromCSVFile(std::ifstream& file) {
    // poziva se sa pretpostavkom da se vektor sastoji od iskljucivo i samo 2 clana
    auto intVectorToTrip = [](vector<int> v) -> Trip {
        return {v[0], v[1]};
    };

    vector<Trip> res;
    vector<string> allLines = getAllCSVLinesFromFile(file);
    
    for (int i = 0; i < allLines.size(); i++){
        vector<int> current = parseCSVLineToIntVector(allLines[i]);
        Trip trip = intVectorToTrip(current);
        res.push_back(trip);
    }
    return res;
}

// obrada datoteke sa vozilima i vracanje u obliku vektora istih
vector<Vehicle> Utility::getVehiclesFromCSVFile(std::ifstream& file){
    vector<Vehicle> res;

    vector<string> allLines = getAllCSVLinesFromFile(file);
    
    int id = 1;
    for (string s : allLines){
        string currentVehicleName = "";
        string currentVehicleLocationString = "";
        int i = 0;

        for (; i < s.length(); i++){
            if (s[i] == ','){
                i++;
                break;
            }
            currentVehicleName += s[i];
        }

        for (; i < s.length(); i++)
            currentVehicleLocationString += s[i];

        Vehicle newVehicle(id++, currentVehicleName, std::stoi(currentVehicleLocationString));
        res.push_back(newVehicle);
    }
    return res;
}