

#include "LineMenu.h"
#include "PointMenu.h"
#include "../exceptions/EqualPointException.h"
#include "StringsMenu.h"

int LineMenu::process() {
    int choice;
    do{
        StringsMenu::displayLine(); //shows the string ui for the line class
        std::cin >> choice;
        if(choice < 1 || choice > 3) { std::cout << "The number has to be between 1 and 3" << std::endl; }
    } while(choice < 1 || choice > 3);

    doTheChoiceOperations(choice);

    return 0;
};

void LineMenu::doTheChoiceOperations(int choice) {

    Line line = initializeLine();

    switch(choice) {
        case 1:
            getLineDirection(line);
            break;
        case 2:
            getLineNormalVector(line);
            break;
        case 3:
            getOperatorPointLine(line);
            break;
        default:
            break;
    }
}

Line LineMenu::initializeLine(){

    std::cout << "To initialize line, you need two points." << std::endl;

    try {
        std::cout << "Point 1: " << std::endl;
        std::cin >> p1;
        std::cout << "Point 2: " << std::endl;
        std::cin >> p2;
        if (p1 == p2) {
            throw EqualPointException("Point A and Point B are equal!");
        }
    }
    catch (EqualPointException &e) {
        std::cerr << e.what() << typeid(e).name() << std::endl;
    }
    return Line(p1,p2);
}

//case 1
void LineMenu::getLineDirection(Line line) {
    std::cout << std::endl << "The Line direction is: " << line.direction() << std::endl;
}

//case 2
void LineMenu::getLineNormalVector(Line line) {
    std::cout << std::endl << "The Normal Vector is: " << line.normal() << std::endl;
}

//case 3
void LineMenu::getOperatorPointLine(Line line) {
    std::cout << "Type the point you want to check if it lies on the line." << std::endl;
    cin >> p1;
    std::cout << std::endl << "Does the point lies on the line? " << boolalpha << line + p1 << std::endl;
}
