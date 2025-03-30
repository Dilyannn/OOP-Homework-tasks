#include "Point.h"
#include <iostream>

Point::Point() {
    x = 0;
    y = 0;
    z = 0;
}

Point::Point(double x, double y, double z): x(x), y(y), z(z) {
}

Point::Point(const Point & rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
}

Point::~Point() {
}

Point & Point::operator=(const Point & rhs) {
    if (this != & rhs) {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
    }
    return *this;
}

void Point::setCoordinateX(double x) {
    this->x = x;
}
void Point::setCoordinateY(double y) {
    this->y = y;
}
void Point::setCoordinateZ(double z) {
    this->z = z;
}

double Point::getCoordinateX() const {
    return x;
}
double Point::getCoordinateY() const {
    return y;
}
double Point::getCoordinateZ() const {
    return z;
}

void Point::scaling(double a, double b, double c) {
    x *= a;
    y *= b;
    z *= c;
}

void Point::translation(double dx, double dy, double dz) {
    x += dx;
    y += dy;
    z += dz;
}

std::ostream & Point::ins(std::ostream & out) const {
    out << "(" << x << ", " << y << ", " << z << ")";
    return out;
}

std::ostream & operator<<(std::ostream & out, const Point & rhs) {
    return rhs.ins(out);
}
