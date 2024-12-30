#ifndef INTERFACE_STRINGCONVERTIBLE_HPP
#define INTERFACE_STRINGCONVERTIBLE_HPP

#include <string>

class IStringConvertible {
public:
    virtual std::string toString() const = 0;
    virtual operator std::string() const {
        return this->toString();
    }
};

#endif