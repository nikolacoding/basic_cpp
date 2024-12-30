#include "Sale.hpp"

std::ostream& operator<<(std::ostream& stream, Sale& object){
    for (int i = 0; i < object.getSize(); i++){
        stream << object.at(i)->toString();
    }
    return stream;
}

double Sale::totalPrice() const {
    double total = 0;
    
    for (int i = 0; i < this->getSize(); i++)
        total += this->at(i)->m_price;

    return total;
}