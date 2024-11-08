#ifndef CVLISTNODE_H
#define CVLISTNODE_H

#include "../cargo/CargoVehicle.h"

class CVListNode{
public:
    CargoVehicle m_cargoVehicleData;
    CVListNode* m_next;

    CVListNode(const CargoVehicle& data);
};

#endif