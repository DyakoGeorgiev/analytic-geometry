

#ifndef PROJECTLINEARALGEBRA_LINE_H
#define PROJECTLINEARALGEBRA_LINE_H

#include <iostream>
#include "Vector.h"

class Line : public Vector
{
public:
    Line(Point &, Vector&);

    Line(Point &, Point &);

    Line(const Line&); //copy constructor

    Line & operator=(const Line&); //operator =

    ~Line() override = default; //destructor

    Vector normal()const;

    Vector direction()const;


    //OPERATORS
    bool operator +(const Point&)const;


    //GET
    Point getA() const;
    Point getB() const;

    //SET
    int setA(const Point&);
    int setB(const Point&);

    std::ostream & inserter(std::ostream&)const override;
private:
    Point p1;
    Point p2;
};

#endif //PROJECTLINEARALGEBRA_LINE_H
