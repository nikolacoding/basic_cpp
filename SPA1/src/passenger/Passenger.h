#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>

class Passenger{
private:
    static int m_totalInstances;
    int m_id;
    short m_age;

public:

    Passenger(short age = 20);
    short getAge() const;
    int getId() const;
    
    void debugLog();
};

#endif