#include "../cargo/Cargo.h"

Cargo::Cargo(std::string name) : m_name(name) { }

std::string Cargo::getName() const {
    return this->m_name;
}