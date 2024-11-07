#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>

namespace Simulation{
    enum Types{
        PUTNICKO = 1,
        TERETNO = 2
    };

    void Run(int numVehicles, int type);
    void End();
}

#endif