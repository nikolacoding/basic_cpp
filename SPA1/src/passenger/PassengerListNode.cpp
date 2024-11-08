#include "../passenger/PassengerListNode.h"

PassengerListNode::PassengerListNode(const Passenger& data){
    this->m_next = nullptr;
    this->getPassengerData() = data;
}

Passenger& PassengerListNode::getPassengerData(){
    return this->m_passengerData;
}