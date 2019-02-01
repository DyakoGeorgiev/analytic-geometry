

#include "DefaultMenu.h"
#include "StringsMenu.h"
#include <iostream>

int DefaultMenu::process() {
    int choice;
    StringsMenu::displayDefaultMenu(); //shows the default ui
    std::cin >> choice;
    return choice;
}