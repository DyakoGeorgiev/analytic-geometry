

#include "Vector.h"
#include <iostream>
#include <cmath>
#include "../exceptions/VectorLengthException.h"


Vector::Vector(double x, double y, double z):Point(x,y,z) {}
Vector::Vector(const Point& A, const Point& B){
    setX(B.getX() - A.getX());
    setY(B.getY() - A.getY());
    setZ(B.getZ() - A.getZ());
}
Vector::Vector(const Vector& rhs): Point(rhs){}

Vector::~Vector() = default;

ostream& Vector::inserter(ostream& out) const {
    Point::inserter(out); //Point with 3 coordinates
    return out;
}

istream& Vector::extractor(istream& in) {
    Point::extractor(in);
    return in;
}

ostream& operator << (ostream& lhs, const Vector& rhs) {
    return rhs.inserter(lhs);
}
istream& operator >> (istream& lhs, Vector& rhs) {
    return rhs.extractor(lhs);
}


double Vector::vectorLength() {
    return sqrt(getX()*getX() + getY()*getY() + getZ()*getZ());
}


bool Vector::nullVector() const {
    return getX() == 0 && getY() == 0 && getZ() == 0;
    //Point with 3 coordinates
}


Vector Vector::vectorDirection() {
    if (this->vectorLength() == 0) {
        throw VectorLengthException("Cannot be done!! Vector length is 0!");
    }
    double dir = sqrt(getX()*getX() + getY()*getY() + getZ()*getZ());
    return Vector(getX() / dir, getY() / dir, getZ() / dir);
}


Vector Vector::vectorProjection(Vector& rhs) {
    return Vector::operator*((Vector::operator*(rhs)) / pow(this->vectorLength(),2));
}


bool Vector::vectorParallelism(Vector& rhs) {
    if (this->vectorLength() == 0) {
        throw VectorLengthException("Parallelism cant be done! Vector length is 0!");
    }
    else if (rhs.vectorLength() == 0) {
        throw VectorLengthException("Parallelism cant be done! Vector length is 0!");
    }
    else {
        std::cout << std::endl;
        double res1 = getX() / rhs.getX();
        double res2 = getY() / rhs.getY();
        double res3 = getZ() / rhs.getZ();
        return res1 == res2 && res1 == res3 && res2 == res3;
    }
}


bool Vector::vectorPerpen(Vector& rhs) {
    if (this->vectorLength() == 0) {
        throw VectorLengthException("Perpendicularity cant be done! Vector length is 0!");
    }
    else if (rhs.vectorLength() == 0) {
        throw VectorLengthException("Perpendicularity cant be done! Vector length is 0!");
    }
    std::cout << std::endl;
    double sum = getX() * rhs.getX() + getY() * rhs.getY() + getY() *rhs.getZ();
    return sum == 0;
}


Vector Vector::operator+(const Vector& c2)
{
    /*
     * (x + v1, y + v2, z + v3)
     * */
    return Vector(getX() + c2.getX(), getY() + c2.getY(), getZ() + c2.getZ());
}


Vector operator-(const Vector& c1, const Vector& c2)
{

    //(x + v1, y + v2, z + v3)
    return Vector(c1.getX() - c2.getX(), c1.getY() - c2.getY(), c1.getZ() - c2.getZ());
}


Vector Vector::operator * (double r) {
    return Vector(r*this->getX(), r * this->getY(), r * this->getZ());
}


double Vector::operator*(const Vector& c2){
    double res = this->getX()*c2.getX() + this->getY() * c2.getY() + this->getZ() * c2.getZ();
    return res;
}


Vector Vector::operator ^(const Vector& c2) {

    //(x,y,z)x(a,b,c) = (y*c - z*b,  z*a - x*c,  x*b - y*a)
    return Vector((this->getY()*c2.getZ()) - this->getZ()*c2.getY(),
                  this->getZ()*c2.getX() - this->getX()*c2.getZ(),
                  this->getX()*c2.getY() - this->getY()*c2.getX());
}



double Vector::operator()(const Vector  & lhs, const Vector & rhs) {

    //(AxB)*C
    return Vector::operator*(Vector::operator^(lhs));
}

