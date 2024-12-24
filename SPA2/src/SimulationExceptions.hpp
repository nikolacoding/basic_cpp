#ifndef SIMULATIONEXCEPTIONS_H
#define SIMULATIONEXCEPTIONS_H

#include <exception>
#include <string>
using std::string;

class ClosedStreamException final : public std::exception {
private:
    string m_message;
public:
    ClosedStreamException(
        string message = "Exception: Jedan od potrebnih tokova nije otvoren."
    ) : m_message(message) {}
    
    const char* what() const throw() override {
        return m_message.c_str();
    }
};

class EmptyGraphException final : public std::exception {
private:
    string m_message;
public:
    EmptyGraphException(
        string message = "Exception: Graf je prazan."
    ) : m_message(message) {}
    
    const char* what() const throw() override {
        return m_message.c_str();
    }
};

class NoTripsException final : public std::exception {
private:
    string m_message;
public:
    NoTripsException(
        string message = "Exception: Nema korisnickih zahtjeva."
    ) : m_message(message) {}
    
    const char* what() const throw() override {
        return m_message.c_str();
    }
};

class NoVehiclesException final : public std::exception {
private:
    string m_message;
public:
    NoVehiclesException(
        string message = "Exception: Nema vozila."
    ) : m_message(message) {}
    
    const char* what() const throw() override {
        return m_message.c_str();
    }
};

class VehicleOutOfBoundsException final : public std::exception {
private:
    string m_message;
public:
    VehicleOutOfBoundsException(
        string message = "Exception: Postoje vozila definisana van opsega grafa grada."
    ) : m_message(message) {}
    
    const char* what() const throw() override {
        return m_message.c_str();
    }
};


class UserOutOfBoundsException final : public std::exception {
private:
    string m_message;
public:
    UserOutOfBoundsException(
        string message = "Exception: Postoje korisnicki zahtjevi van opsega grafa grada."
    ) : m_message(message) {}
    
    const char* what() const throw() override {
        return m_message.c_str();
    }
};

class VehicleOverlapException final : public std::exception {
private:
    string m_message;
public:
    VehicleOverlapException(
        string message = "Exception: Neka vozila su na istim startnim lokacijama."
    ) : m_message(message) {}
    
    const char* what() const throw() override {
        return m_message.c_str();
    }
};

#endif