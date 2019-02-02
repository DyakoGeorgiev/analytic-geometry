
#include "PointMenu.h"
#include "DefaultMenu.h"
#include "StringsMenu.h"
#include <iostream>

int PointMenu::process() {
    int choice;
    do {
        StringsMenu::displayPoint(); //shows the string ui for the point class
        std::cin >> choice;
        if(choice < 1 || choice > 2) { std::cout << "The number has to be between 1 or 2" << std::endl; }
    }while(choice < 1 || choice > 2);

    doTheChoiceOperations(choice);
    return choice;
};

void PointMenu::doTheChoiceOperations(int choice){
    pointInput();
    system("cls");
    switch(choice) {
        case 1:
            getPointCoordinates(point);
            break;
        case 2:
            getIfTwoPointAreEqual(point);
            break;
        default:
            break;
    }
}

Point PointMenu::pointInput(){
    std::cout <<  std::endl << "Point 1: " <<  std::endl;
    std::cin >> point;
    return point;
}

Point PointMenu::pointSecondInput() {
    std::cout <<  std::endl << "Point 2: " <<  std::endl;
    std::cin >> pointSecond;
    return pointSecond;
}

//case 1
void PointMenu::getPointCoordinates(class Point point) {
    std::cout << point;
}

//case 2
void PointMenu::getIfTwoPointAreEqual (class Point point) {
    pointSecondInput();
    bool isEqual = (point == pointSecond);
    std::cout << std::endl << "Is Point 1 equal to Point 2: " << std::boolalpha << isEqual << std::endl;
}
