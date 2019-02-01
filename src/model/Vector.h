
#ifndef PROJECTLINEARALGEBRA_VECTOR_H
#define PROJECTLINEARALGEBRA_VECTOR_H


#include "Point.h"
#include <iostream>


class Vector :public Point {
public:

    //Vector();
    explicit Vector(double = 0., double= 0., double = 0.);//default constructor with parameters
    Vector(const Point&, const Point&);
    virtual ~Vector(); //destructor
    Vector(const Vector&);

    Vector vectorProjection(Vector&); //vector projection
    bool vectorParallelism(Vector&); // vector parallelism
    bool vectorPerpen(Vector&); //vector perpendicularity

    double vectorLength(); //vector length
    bool nullVector() const; //nullVector
    Vector vectorDirection(); //vector direction


    double operator * (const Vector&);
    Vector operator + (const Vector &);
    friend Vector operator - (const Vector&, const Vector &);
    Vector operator *(double);
    Vector operator^ (const Vector&);
    double operator()(const Vector&, const Vector&);

    std::ostream& inserter(std::ostream&) const override;
    std::istream& extractor(std::istream&) override;

    friend std::ostream& operator << (std::ostream&, const Vector&);
    friend std::istream& operator >> (std::istream&, Vector&);
};



#pragma once

#endif //PROJECTLINEARALGEBRA_VECTOR_H
