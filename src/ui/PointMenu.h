
#ifndef PROJECTLINEARALGEBRA_POINTMENU_H
#define PROJECTLINEARALGEBRA_POINTMENU_H

#include "Menu.h"
#include "../model/Point.h"
#include "OperationsMenu.h"
#include <iostream>

class PointMenu :public Menu, OperationsMenu, protected Point {
public:

    PointMenu() = default;

    int process() override;
    void doTheChoiceOperations(int choice) override;

    void getPointCoordinates(Point);
    void getIfTwoPointAreEqual (Point);

    Point pointInput();
    Point pointSecondInput();
private:
    Point point;
    Point pointSecond;
};
#endif //PROJECTLINEARALGEBRA_POINTMENU_H
