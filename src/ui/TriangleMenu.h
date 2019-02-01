//
// Created by Diakoff on 1.2.2019 г..
//

#ifndef PROJECTLINEARALGEBRA_TRIANGLEMENU_H
#define PROJECTLINEARALGEBRA_TRIANGLEMENU_H

#include "Menu.h"
#include "OperationsMenu.h"
#include "../model/Triangle.h"

class TriangleMenu : public Menu, OperationsMenu, protected Triangle {
public:

    int process() override;
    void doTheChoiceOperations(int choice) override;
    Triangle initializeTriangle();

    void getTriangleType(Triangle);
    void getTriangleArea(Triangle);
    void getTrianglePerimeter(Triangle);
    void getTriangleMedicentre(Point,Point,Point);

private:
    Point p1;
    Point p2;
    Point p3;
};

#endif //PROJECTLINEARALGEBRA_TRIANGLEMENU_H
