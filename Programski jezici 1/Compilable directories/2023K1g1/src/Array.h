#include "Vector2D.h"

class Array{
private:
    int capacity;
    int size;
    Vector2D *vectors;

public:
    Array();
    ~Array();
    void append(Vector2D object);
};