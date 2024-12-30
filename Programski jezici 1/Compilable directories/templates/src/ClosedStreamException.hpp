#ifndef CLOSEDSTREAMEXCEPTION_H
#define CLOSEDSTREAMEXCEPTION_H

#include <exception>
#include <string>
using std::string;

class ClosedStreamException final : std::exception {
private:
    string m_message;

public:
    ClosedStreamException(){
        // privremeno
        m_message = "Izuzetak: Potrebni tok nije otvoren";
    }

    const char* what() const noexcept override {
        return this->m_message.c_str();
    }
};

#endif