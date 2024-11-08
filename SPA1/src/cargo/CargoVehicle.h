#ifndef CARGOVEHICLE_H
#define CARGOVEHICLE_H

#include "../cargo/Cargo.h"
#include "../cargo/CargoStack.h"
#include "../shared/Utility.h"
#include <vector>

class CargoVehicle{
private:
    CargoStack m_cargoStack;

public:
    CargoVehicle(int numCargo = 3);
};

#endif