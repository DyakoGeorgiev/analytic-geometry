
#include "../model/Vector.h"
#include "../exceptions/VectorLengthException.h"

#include "VectorMenu.h"
#include "DefaultMenu.h"
#include "StringsMenu.h"

#include <iostream>

int VectorMenu::process() {
    int choice;
    do{
        StringsMenu::displayVector(); //shows the string ui for the vector class
        std::cin >> choice;
        if(choice < 1 || choice > 11) { std::cout << "The number has to be between 1 and 11" << std::endl; }
    } while(choice < 1 || choice > 11);

    doTheChoiceOperations(choice);

    return 0;
};

void VectorMenu::doTheChoiceOperations(int choice) {
    vectorInput();

    system("cls");
    switch(choice) {
        case 1:
            getVectorLength(vector);
            break;
        case 2:
            getVectorDirection(vector);
            break;
        case 3:
            getVectorProjection(vector);
            break;
        case 4:
            checkIfNullVector(vector);
            break;
        case 5:
            checkVectorParallelism(vector);
            break;
        case 6:
            checkVectorPerpendicularity(vector);
            break;
        case 7:
            getVectorAddition(vector);
            break;
        case 8:
            getVectorAdditionWithNumber(vector);
            break;
        case 9:
            getScalarMultiplication(vector);
            break;
        case 10:
            getVectorMultiplication(vector);
            break;
        case 11:
            getVectorExpression(vector);
            break;
        default:
            break;
    }
}

class Vector VectorMenu::vectorInput(){
    std::cout <<  std::endl << "Vector 1 input: " <<  std::endl;
    std::cin >> vector;
}
class Vector VectorMenu::vectorInputSecondVector(){
    std::cout <<  std::endl << "Vector 2 input: " <<  std::endl;
    std::cin >> vectorSecond;
}
void VectorMenu::setIntByConsole(){
    cout << endl << "Type number: " << endl;
    cin >> num;
}
double VectorMenu::getInt(){
    return num;
}

//case 1
void VectorMenu::getVectorLength(class Vector vector) {
    std::cout << std::endl << "Vector length: " << vector << " e: " << vector.vectorLength() << std::endl;
}

//case 2
void VectorMenu::getVectorDirection(class Vector v) {
    try {
        cout << endl << "Vector direction: " << v << " is: " << v.vectorDirection() << endl;
    }
    catch (VectorLengthException &ex) {
        cerr << ex.what() << " by " << typeid(ex).name() << endl;
        return;
    }
}

//case 3
void VectorMenu::getVectorProjection(class Vector v) {
    vectorInputSecondVector();
    std::cout << std::endl << "Projection of the vector" << v << " over vector: " << vectorSecond << " = " << v.vectorProjection(vectorSecond) << std::endl;
}

//case 4
void VectorMenu::checkIfNullVector(class Vector v) {
    cout << endl << "Null vector : " << boolalpha << v.nullVector() << endl;
}

//case 5
void VectorMenu::checkVectorParallelism(class Vector v) {
    try {
        vectorInputSecondVector();
        std::cout << std::endl << "Is the vector" << v << " parallel to vector: " << vectorSecond << " = " << boolalpha
                  << v.vectorParallelism(vectorSecond) << endl;
    }
    catch (VectorLengthException &ex) {
        cerr << ex.what() << " by " << typeid(ex).name() << endl;
        return;
    }
}

//case 6
void VectorMenu::checkVectorPerpendicularity(class Vector v) {
    try {
        vectorInputSecondVector();
        cout << endl << "Is Vector" << v << " perpendicular to vector: " << vectorSecond << " = " << boolalpha << v.vectorPerpen(vectorSecond) << endl;
    }
    catch (VectorLengthException &ex) {
        cerr << ex.what() << " by " << typeid(ex).name() << endl;
        return;
    }
}

//case 7
void VectorMenu::getVectorAddition(class Vector v){
    vectorInputSecondVector();
    std::cout << std::endl << "Vector 1: " << v << " + Vector 2: " << vectorSecond << " = " << v + vectorSecond << std::endl;
}

//case 8
void VectorMenu::getVectorAdditionWithNumber(class Vector v) {
    setIntByConsole();
    std::cout << std::endl << "Vector 1" << v << " * Vector 2: " << getInt() << " = " << v * getInt() << std::endl;
}

//case 9
void VectorMenu::getScalarMultiplication(class Vector v) {
    vectorInputSecondVector();
    std::cout << std::endl << "Scalar multiplication of Vector 1" << v << " to Vector 2: " << vectorSecond << " = " << v * vectorSecond << std::endl;
}

//case 10
void VectorMenu::getVectorMultiplication(class Vector v){
    vectorInputSecondVector();
    class Vector temp = v ^ vectorSecond;
    std::cout << std::endl << "Vector multiplication of vector 1" << v << " to Vector 2: " << vectorSecond << " = " << temp << std::endl;
}

//case 11
void VectorMenu::getVectorExpression(class Vector v) {
    vectorInputSecondVector();
    Vector temp = vectorInput();
    num = (v  * (vectorSecond ^ temp));
    std::cout << std::endl << "Vektorno proizvedenie na vektor" << v << " s vektor: " << vectorSecond << " =  v*(v2^v3): " << num << std::endl;
}
