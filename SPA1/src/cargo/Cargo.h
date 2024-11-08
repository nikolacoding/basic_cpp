#ifndef CARGO_H
#define CARGO_H

#include <string>

class Cargo{
private:
    std::string m_name;

public:
    Cargo(std::string name = "unnamed");
    std::string getName() const;
};

#endif