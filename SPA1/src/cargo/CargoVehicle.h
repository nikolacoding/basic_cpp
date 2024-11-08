#ifndef CARGOVEHICLE_H
#define CARGOVEHICLE_H

#include "../cargo/Cargo.h"
#include "../cargo/CargoStack.h"
#include "../shared/Utility.h"
#include <vector>

class CargoVehicle{
private:
    static int m_numInstances;
    int m_id;
public:
    CargoStack m_cargoStack;
    CargoVehicle();
    CargoVehicle(std::vector<Cargo>& cargo);

    int getId() const;
    void logCargo() const;
};

#endif