
#ifndef PROJECTLINEARALGEBRA_STRINGSMENU_H
#define PROJECTLINEARALGEBRA_STRINGSMENU_H

#include <iostream>

class StringsMenu {
public:
    static void displayVector();
    static void displayPoint();
    static void displayDefaultMenu();
    static void displayTriangle();
    //void displayLine();
    //static std::string defaultMenu = "Please choose the type of the object: ";
private:
    StringsMenu();
};

#endif //PROJECTLINEARALGEBRA_STRINGSMENU_H
