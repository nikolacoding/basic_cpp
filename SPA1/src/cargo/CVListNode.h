#ifndef CVLISTNODE_H
#define CVLISTNODE_H

#include "../cargo/CargoVehicle.h"

class CVListNode{
private:
    CargoVehicle m_cargoVehicleData;

public:
    CVListNode* m_next;

    CVListNode() = delete;
    explicit CVListNode(const CargoVehicle& data);
    
    CargoVehicle& getCargoVehicleData();
};

#endif