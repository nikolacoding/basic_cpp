#include "../passenger/PVListNode.h"

PVListNode::PVListNode(const PassengerVehicle& data){
    this->m_next = nullptr;
    this->m_passengerVehicleData = data;
}