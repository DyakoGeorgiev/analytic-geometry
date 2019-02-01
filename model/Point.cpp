
#include "Point.h"
#include <iostream>

Point::Point(double x, double y, double z) : x(x), y(y), z(z){}

Point::Point(const Point& rhs):x(rhs.x),y(rhs.y),z(rhs.z){}

Point& Point::operator=(const Point& rhs) {
    if (this != &rhs) {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
    }
    return *this;
}


bool Point::isEqual(const Point& rhs) const {
    bool isEqual = (x == rhs.x && y == rhs.y && z == rhs.z);
    return isEqual;
}

bool operator==(const Point& lhs, const Point& rhs)
{
    return lhs.isEqual(rhs);
}

//set
int Point::setX(double x) { this->x = x; return 0; }
int Point::setY(double y) { this->y = y; return 0; }
int Point::setZ(double z) { this->z = z; return 0; }

//get
double Point::getX() const { return x; }
double Point::getY() const { return y; }
double Point::getZ() const { return z; }


std::ostream& Point::inserter(std::ostream& out)const {
    out << std::endl << "Point [ " << x << "," << y << "," << z << "]" << std::endl;
    return out;
}
std::istream& Point::extractor(std::istream& in) {
    std::cout << "Type x: "; in >> x;
    std::cout << "Type y: "; in >> y;
    std::cout << "Type z: "; in >> z;
    return in;
}

std::ostream& operator << (std::ostream& lhs, const Point& rhs){
    return rhs.inserter(lhs);
}
std::istream& operator >> (std::istream& lhs , Point& rhs){
    return rhs.extractor(lhs);
}