#ifndef PVListNode_H
#define PVListNode_H

#include "../passenger/PassengerVehicle.h"

class PVListNode{
public:
    PassengerVehicle m_passengerVehicleData;
    PVListNode* m_next;

    PVListNode(const PassengerVehicle& data);
};

#endif