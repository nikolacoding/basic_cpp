#ifndef CVLISTNODE_H
#define CVLISTNODE_H

#include "../cargo/CargoVehicle.h"

class CVListNode{
public:
    CargoVehicle m_passengerVehicleData;
    CVListNode* m_next;

    CVListNode(const CargoVehicle& data);
};

#endif