//
// Created by Diakoff on 1.2.2019 г..
//


#include "TriangleMenu.h"
#include "../exceptions/EqualPointException.h"
#include "StringsMenu.h"

int TriangleMenu::process() {
    int choice;
    do{
        StringsMenu::displayTriangle(); //shows the string ui for the triangle class
        std::cin >> choice;
        if(choice < 1 || choice > 4) { std::cout << "The number has to be between 1 and 4" << std::endl; }
    } while(choice < 1 || choice > 4);

    doTheChoiceOperations(choice);

    return 0;
};

Triangle TriangleMenu::initializeTriangle(){

    std::cout << "To initialize triangle, you need three points." << std::endl;

    try {
        std::cout << "Point 1: " << std::endl;
        cin >> p1;
        cin.ignore();
        std::cout << "Point 2: " << std::endl;
        cin >> p2;
        cin.ignore();
        std::cout << "Point 3: " << std::endl;
        cin >> p3;
        cin.ignore();

        if (p1 == p2) {
            throw EqualPointException("Point A and Point B are equal!");
        }
        if (p1 == p3) {
            throw EqualPointException("Point A and Point C are equal!");
        }
        if (p2 == p3) {
            throw EqualPointException("Point B and Point C are equal!");
        }
    }
    catch (EqualPointException &e) {
        std::cerr << e.what() << typeid(e).name() << std::endl;
    }
    return Triangle(p1,p2,p3);
}

void TriangleMenu::doTheChoiceOperations(int choice) {

    Triangle triangle = initializeTriangle();

    system("cls");
    switch(choice) {
        case 1:
            getTriangleType(triangle);
            break;
        case 2:
            getTriangleArea(triangle);
            break;
        case 3:
            getTrianglePerimeter(triangle);
            break;
        case 4:
            getTriangleMedicentre(p1,p2,p3);
            break;
        default:
            break;
    }
}

//case 1
void TriangleMenu::getTriangleType(Triangle triangle) {
    std::cout << std::endl << "The triangle type is: " << triangle.typeTriangle() << std::endl;
}

//case 2
void TriangleMenu::getTriangleArea(Triangle triangle) {
    std::cout << std::endl << "The triangle Area is: " << triangle.areaTriangle() << std::endl;
}

//case 3
void TriangleMenu::getTrianglePerimeter(Triangle triangle) {
    std::cout << std::endl << "The triangle Perimeter is: " << triangle.perimeterTriangle() << std::endl;
}

//case 4
void TriangleMenu::getTriangleMedicentre(Point p1, Point p2, Point p3) {
    std::cout << std::endl << "The Triangle centroid is: " << Triangle::centroid(p1, p2, p3) << std::endl;
}
