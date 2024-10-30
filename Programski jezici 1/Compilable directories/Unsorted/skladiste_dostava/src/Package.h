#ifndef PACKAGE_H
#define PACKAGE_H

#include "Receiver.h"

class Package{
private:
    int _id;
    int _mass;
    int _mpc;
    int _vpc;
    Receiver _receiver;
public:
    Package(int margin = 10);
    ~Package();

    int getId() const;
    int getMass() const;
    int getMpc() const;
    int getVpc() const;
    Receiver& getReceiverRef() const;
};

#endif