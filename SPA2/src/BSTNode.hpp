#ifndef BSTNODE_H
#define BSTNODE_H

#include "Vehicle.hpp"

#include <string>
#include <vector>

class BSTNode final {
public:
    Vehicle& m_vehicle;
    int m_distance;

    BSTNode* m_left;
    BSTNode* m_right;
    BSTNode* m_next;
    
    BSTNode(int distance, Vehicle& vehicle) : 
        m_distance(distance), m_vehicle(vehicle), m_left(nullptr), m_right(nullptr), m_next(nullptr) {}
};

#endif