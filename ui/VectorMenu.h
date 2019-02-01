
#ifndef PROJECTLINEARALGEBRA_VECTORMENU_H
#define PROJECTLINEARALGEBRA_VECTORMENU_H

#include "Menu.h"
#include "OperationsMenu.h"
#include "..\model\Vector.h"
#include <iostream>

class VectorMenu :public Menu, OperationsMenu, protected Vector {
public:

    Vector vectorInput();
    Vector vectorInputSecondVector();

    int process() override;
    void doTheChoiceOperations(int choice) override;

    void getVectorLength(Vector);
    void getVectorDirection(Vector);
    void getVectorProjection(Vector);
    void checkIfNullVector(Vector);
    void checkVectorParallelism(Vector);
    void checkVectorPerpendicularity(Vector);
    void getVectorAddition(Vector);
    void getVectorAdditionWithNumber(Vector);
    void getScalarMultiplication(Vector);
    void getVectorMultiplication(Vector);
    void getVectorExpression(Vector);
    void setIntByConsole();
    double getInt();

private:
    Vector vector;
    Vector vectorSecond;
    double num;
};

#endif //PROJECTLINEARALGEBRA_VECTORMENU_H
