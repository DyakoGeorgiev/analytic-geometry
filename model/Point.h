
#ifndef PROJECTLINEARALGEBRA_POINT_H
#define PROJECTLINEARALGEBRA_POINT_H
#include <iostream>

class Point {
public:
    explicit Point(double x = 0., double y = 0., double z = 0.);
    Point(const Point&);
    Point& operator=(const Point&);
    bool isEqual(const Point&) const;
    //set
    virtual int setX(double);
    virtual int setY(double);
    virtual int setZ(double);
    //get
    double getX() const;
    double getY() const;
    double getZ() const;
    //ostream and istream

    virtual std::ostream& inserter(std::ostream&) const;

    virtual std::istream& extractor(std::istream&);

    friend bool operator==(const Point&,const Point&);
    friend std::ostream& operator << (std::ostream& lhs, const Point& p1);
    friend std::istream& operator >> (std::istream& lhs, Point& p1);
private:
    double x;
    double y;
    double z;
};



#pragma once
#endif //PROJECTLINEARALGEBRA_POINT_H
