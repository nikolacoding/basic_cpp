#include "CVListNode.h"

CVListNode::CVListNode(const CargoVehicle& data){
    this->m_next = nullptr;
    this->m_passengerVehicleData = data;
}