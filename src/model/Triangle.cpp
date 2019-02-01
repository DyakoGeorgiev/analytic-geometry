

#include "Triangle.h"

#include "Point.h"
#include "Triangle.h"
#include <cmath>
#include <iostream>
#include "../exceptions/EqualPointException.h"
#include <exception>
#include <stdexcept>


Triangle::Triangle() {
}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) {
    setX(sqrt(((p3.getX() - p2.getX())*(p3.getX() - p2.getX())) + (p3.getY() - p2.getY())*(p3.getY() - p2.getY()) + (p3.getZ() - p2.getZ())*(p3.getZ() - p2.getZ()))); //P2 & P3
    setY(sqrt(((p1.getX() - p3.getX())*(p1.getX() - p3.getX())) + (p1.getY() - p3.getY())*(p1.getY() - p3.getY()) + (p1.getZ() - p3.getZ())*(p1.getZ() - p3.getZ()))); //P3 & P1
    setZ(sqrt(((p2.getX() - p1.getX())*(p2.getX() - p1.getX())) + (p2.getY() - p1.getY())*(p2.getY() - p1.getY()) + (p2.getZ() - p1.getZ())*(p2.getZ() - p1.getZ()))); //P1 & P2

    if (p1 == p2) {
        throw EqualPointException("Point A and Point B are equal!");
    }
    else if (p1 == p3) {
        throw EqualPointException("Point A and Point C are equal!");

    }
    else if (p2 == p3) {
        throw EqualPointException("Point B and Point C are equal!");
    }
}


Triangle::~Triangle() = default;


int Triangle::typeTriangle() const {
    if (getX() == getY() && getX()== getZ() && getY()==getZ()) { cout << "������������ � ������������ " << endl; }
    else if (getX() == getY() || getX() == getZ() || getY() == getZ()) { cout << "������������� � �����������" << endl; }
    else { std::cout << "������������ � ������������" << endl; }

    double a2 = getX()*getX();
    double b2 = getY()*getY();
    double c2 = getZ()*getZ();

    if (a2 >= b2 && a2 >= c2)
    {
        if (a2 == (b2 + c2)) { cout << endl << "����������� � �����������" << endl; }
        else if (a2 > (b2 + c2)) { cout << "����������� � ����������" << endl; }
        else { cout << "����������� � �����������" << endl; }
    }

    if (b2>= a2 && b2 >= c2)
    {
        if (b2 == (a2 + c2)) { cout << endl << "����������� � �����������" << endl; }
        else if (b2 > (a2 + c2)) { cout << endl << "����������� � ����������" << endl; }
        else { cout << "����������� � �����������" << endl; }
    }

    if (c2 >= a2 && c2 >= b2) {
        if (c2 == (b2 + a2)) { cout << endl << "����������� � �����������" << endl; }
        else if (c2 > (b2 + a2)) { cout << endl <<  "����������� � ����������" << endl; }
        else { cout << "����������� � �����������" << endl; }
    }
    return 0;
}

double Triangle::areaTriangle() const {
    double s = (getX() + getY() + getZ()) / 2;
    double area = abs(sqrt(s*(s - getX())*(s - getY())*(s - getZ())));
    cout << "Area: ";
    return area;
}

double Triangle::perimeterTriangle() const {
    cout << "Perimeter: ";
    return (getX() + getY() + getZ());
}


Point Triangle::medicentre(const Point& p1,const Point& p2, const Point& p3) const {
    double ma = (p1.getX() + p2.getX() + p3.getX()) / 3;
    double mb = (p1.getY() + p2.getY() + p3.getY()) / 3;
    double mc = (p1.getZ() + p2.getZ() + p3.getZ()) / 3;
    return Point(ma, mb, mc);
}

ostream& Triangle::inserter(ostream& out) const {
    out << getX() << " , " << getY() << " , " << getZ() << endl;
    return out;
}
istream& Triangle::extractor(istream& in) {
    cout << "Coordinates for Point 1:";
    Point p1;
    cin >> p1;
    cout << endl << "Coordinates for Point 2: ";
    Point p2;
    cin >> p2;
    cout << endl << "Coordinates for Point 3: ";
    Point p3;
    cin >> p3;
    setY(sqrt(((p3.getX() - p2.getX())*(p3.getX() - p2.getX())) + (p3.getY() - p2.getY())*(p3.getY() - p2.getY()) + (p3.getZ() - p2.getZ())*(p3.getZ() - p2.getZ()))); //P2 & P3
    setX(sqrt(((p1.getX() - p3.getX())*(p1.getX() - p3.getX())) + (p1.getY() - p3.getY())*(p1.getY() - p3.getY()) + (p1.getZ() - p3.getZ())*(p1.getZ() - p3.getZ()))); //P3 & P1
    setZ(sqrt(((p2.getX() - p1.getX())*(p2.getX() - p1.getX())) + (p2.getY() - p1.getY())*(p2.getY() - p1.getY()) + (p2.getZ() - p1.getZ())*(p2.getZ() - p1.getZ()))); //P1 & P2
    if (p1 == p2) {
        throw EqualPointException("Point A and Point B are equal!");
    }
    else if (p1 == p3) {
        throw EqualPointException("Point A and Point C are equal!");

    }
    else if (p2 == p3) {
        throw EqualPointException("Point B and Point C are equal!");
    }
    return in;
}
ostream& operator << (ostream& lhs, const Triangle& rhs) {
    return rhs.inserter(lhs);
}
istream& operator >> (istream& lhs, Triangle& rhs) {
    return rhs.extractor(lhs);
}
