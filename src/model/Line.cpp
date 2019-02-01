
#include "Vector.h"
#include "Line.h"
#include <iostream>
#include <cmath>
#include "../exceptions/EqualPointException.h"
#include "Line.h"
#include<cmath>

Line::Line(Point & lhs, Vector& rhs) :p2(lhs)
{
    lhs.setX(rhs.getX());
    lhs.setY(rhs.getY());
    lhs.setZ(rhs.getZ());
}

Line::Line(Point & lhs, Point & rhs) :p1(lhs), p2(rhs){}

Line::Line(const Line &rhs) : Vector(rhs){}

Line & Line::operator=(const Line& rhs)
{
    if (this != &rhs)
    {
        p1 = rhs.p1;
        p2 = rhs.p2;
    }
    return *this;
}

ostream& Line::inserter(ostream& out) const
{
    cout << p1;
    cout << p2;
    return out;
}


int Line::setA(const Point& lhs)
{
    p1 = lhs;
    return 0;
}

int Line::setB(const Point& lhs)
{
    p2 = lhs;
    return 0;
}

Point Line::getA()const
{
    return p1;
}

Point Line::getB()const
{
    return p2;
}

Vector Line::direction()const
{
    return Vector(p2.getX() - p1.getX(), p2.getY() - p1.getY(), p2.getZ() - p1.getZ());
}

Vector Line::normal()const
{
    Vector temp(p1, p2);
    return temp.vectorDirection();
}


bool Line::operator +(const Point& rhs)const
{
    double newX = (rhs.getX() - p1.getX()) / (p2.getX() - p1.getX());
    double newY = (rhs.getY() - p1.getY()) / (p2.getY() - p1.getY());
    double newZ = (rhs.getZ() - p1.getZ()) / (p2.getZ() - p1.getZ());
    bool res = (newX == newY == newZ);
    return res;
}
