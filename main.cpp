#include <iostream>

#include "src\exceptions\EqualPointException.h"
#include "src\exceptions\VectorLengthException.h"
#include "src\ui\DefaultMenu.h"
#include "src\ui\Menu.h"
#include "src\ui\PointMenu.h"
#include "src\ui\VectorMenu.h"
#include "src\ui\OperationsMenu.h"
#include "src\model\Point.h"
#include "src\model\Vector.h"
#include "src\model\Line.h"
#include "src\model\Triangle.h"

int main(int argc, char *argv[])
{
    DefaultMenu defaultMenu;
    PointMenu pointMenu;
    VectorMenu vectorMenu;

    int choice = 0;
    char opinion = ' ';

    do {
        if (choice == 0) {
                choice = defaultMenu.process();
            } else if(choice > 4 || choice < 1) {
                std::cout<< "Type correct number!";
                std::cin >> choice;
            } else {
                do{
                    std::cout << "Do you want other operation y/n?";
                    std::cin >> opinion;
                } while(opinion != 'y' && opinion != 'n');
                if(opinion == 'n'){ break; }
                else choice = defaultMenu.process();
        }
        switch(choice) {
            case 1:
                pointMenu.process();
                break;
            case 2:
                vectorMenu.process();
                break;
            case 3:
                //lineMenu.process();
                cout << "Goodbye!";
                break;
            default:
                break;
        }
    } while(opinion != 'n');

    return 0;
}