#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
public:
    Point();
    Point(double x, double y, double z);
    Point(const Point &);
    virtual ~Point();
    Point & operator=(const Point &);

    void setCoordinateX(double x);
    void setCoordinateY(double y);
    void setCoordinateZ(double z);

    double getCoordinateX() const;
    double getCoordinateY() const;
    double getCoordinateZ() const;

    void scaling(double a, double b, double c);
    void translation(double dx, double dy, double dz); //d for delta;

    std::ostream & ins(std::ostream &) const;

private:
    double x, y, z;
};

std::ostream & operator<<(std::ostream &, const Point &);

#endif //POINT_H
