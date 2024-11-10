#include "Vector2DStack.h"

Vector2DStack::Vector2DStack() {
    
}

void Vector2DStack::push(const Vector2D& vector){
    this->m_stackArray.append(vector);
}

bool Vector2DStack::pop(Vector2D& ret){
    bool success;
    int topIndex = this->m_stackArray.getSize() - 1;
    Vector2D r = this->m_stackArray.at(topIndex, success);
    if (success){
        ret = r;
        m_stackArray.remove(topIndex);
    }

    return success;
}