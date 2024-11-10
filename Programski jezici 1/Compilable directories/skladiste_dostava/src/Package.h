#ifndef PACKAGE_H
#define PACKAGE_H

#include "Receiver.h"
#include <string>

class Package{
private:
    static int _count;
    int _id;
    int _mass;
    int _mpc;
    int _vpc;
    const int _margin;
    Receiver _receiver;
public:
    explicit Package(int margin = 10);
    explicit Package(int id, int mass, int mpc, int vpc, int margin);
    ~Package();

    static Package emptyPackage;
    int getId() const;
    int getMass() const;
    int getMpc() const;
    int getVpc() const;
    Receiver getReceiver();
    Receiver& getReceiverRef();

    void debugLog();
};

#endif