#include "Point.h"

Point Point::invalidPoint = Point(-999, -999);

Point::Point(int x, int y) : x(x), y(y) {

}

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}