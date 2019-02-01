
#ifndef PROJECTLINEARALGEBRA_TRIANGLE_H
#define PROJECTLINEARALGEBRA_TRIANGLE_H

#include "Point.h"
#include <iostream>

class Triangle :public Point {
public:
    Triangle();
    Triangle(const Point&, const Point&, const Point&);
    virtual ~Triangle();
    int typeTriangle() const;
    double areaTriangle() const;
    double perimeterTriangle() const;
    Point centroid(const Point& , const Point& , const Point& ) const;

    std::ostream& inserter(std::ostream&) const override;
    std::istream& extractor(std::istream&) override;


    friend std::ostream& operator << (std::ostream&, const Triangle&);
    friend std::istream& operator >> (std::istream&, Triangle&);
};

#pragma once
#endif //PROJECTLINEARALGEBRA_TRIANGLE_H
