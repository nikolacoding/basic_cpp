#ifndef RECEIVER_H
#define RECEIVER_H

#include <string>

class Receiver{
private:
    std::string _name;
    int _eta; // estimated time of arrival
    int _waitTime;
    int _distanceFromStorage;
public:
    Receiver(std::string name = "UnnamedReceiver");
    ~Receiver();

    std::string getName() const;
    int getEta() const;
    int getWaitTime() const;
    int getDistance() const;
};

#endif