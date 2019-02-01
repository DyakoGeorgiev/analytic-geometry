#include <iostream>

#include "exceptions/EqualPointException.h"
#include "exceptions/VectorLengthException.h"
#include "ui/DefaultMenu.h"
#include "ui/Menu.h"
#include "ui/PointMenu.h"
#include "ui/VectorMenu.h"
#include "ui/OperationsMenu.h"
#include "model/Point.h"
#include "model/Vector.h"
#include "model/Line.h"
#include "model/Triangle.h"
#include "ui/TriangleMenu.h"

int main(int argc, char *argv[])
{
    DefaultMenu defaultMenu;
    PointMenu pointMenu;
    VectorMenu vectorMenu;
    TriangleMenu triangleMenu;

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
                break;
            case 4:
                triangleMenu.process();
                break;
            default:
                break;
        }
    } while(opinion != 'n');

    return 0;
}