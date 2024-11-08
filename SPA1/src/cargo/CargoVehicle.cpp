#include "../cargo/CargoVehicle.h"

int CargoVehicle::m_numInstances = 1;

CargoVehicle::CargoVehicle(){ }

CargoVehicle::CargoVehicle(const std::vector<Cargo>& cargo) : m_id(m_numInstances){
    m_numInstances++;
    for (Cargo c : cargo){
        m_cargoStack.push(c);
    }
}

int CargoVehicle::getId() const {
    return this->m_id;
}

void CargoVehicle::logCargo() const {
    this->m_cargoStack.displayAll();
}