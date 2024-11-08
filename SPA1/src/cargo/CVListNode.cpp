#include "../cargo/CVListNode.h"

CVListNode::CVListNode(const CargoVehicle& data){
    this->m_next = nullptr;
    this->getCargoVehicleData() = data;
}

CargoVehicle& CVListNode::getCargoVehicleData() {
    return this->m_cargoVehicleData;
}