
#ifndef PROJECTLINEARALGEBRA_LINEMENU_H
#define PROJECTLINEARALGEBRA_LINEMENU_H


#include "Menu.h"
#include "OperationsMenu.h"
#include "../model/Line.h"

class LineMenu : public Menu, OperationsMenu, protected Line {
public:

    LineMenu() = default;

    Line initializeLine();

    int process() override;
    void doTheChoiceOperations(int choice) override;

    void getLineDirection(Line);
    void getLineNormalVector(Line);
    void getOperatorPointLine(Line);

private:
    Point p1;
    Point p2;
};

#endif //PROJECTLINEARALGEBRA_LINEMENU_H
