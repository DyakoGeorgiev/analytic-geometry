
#include "StringsMenu.h"


void StringsMenu::displayDefaultMenu() {
    std::cout << "Please choose the type of the object:  " << std::endl;
    std::cout << "1 - Point\n"
                 "2 - Vector\n"
                 "3 - Line\n"
                 "4 - Triangle\n" << std::endl;
}

void StringsMenu::displayPoint() {
    std::cout << "Please choose operation for the object :" << std::endl;
    std::cout << "1 - Print coordinates : " << std::endl
              << "2 - Check if Point 1 is equal to Point 2: " << std::endl;
}

void StringsMenu::displayVector() {
    std::cout << "Please choose operation for the object :" << std::endl;
    std::cout << std::endl << "1 - Vector length: "<<
              std::endl<< "2 - Vector direction: " <<
              std::endl << "3 - Vector projection over other vector:" <<
              std::endl << "4 - Check if the vector is Null Vector: " <<
              std::endl << "5 - Check if two vectors are parallel: " <<
              std::endl << "6 - Two vectors perpendicularity: " <<
              std::endl << "7 - Vector 1 + Vector 2: " <<
              std::endl << "8 - Multiplication of vector * number: " <<
              std::endl << "9 - Skalarno proizvedenie na dva vektora: " <<
              std::endl << "10 - Vektorno proizvedenie na dva vektora: " <<
              std::endl << "11 - Smeseno proizvedenie na dva vektora: " << std::endl;
}

void StringsMenu::displayTriangle() {
    std::cout << "Please choose operation for the object :" << std::endl;
    std::cout << "1 - Triangle type " << std::endl
              << "2 - Triangle Area " << std::endl
              << "3 - Triangle Perimeter " << std::endl
              << "4 - Triangle Medicentre " << std::endl;
}