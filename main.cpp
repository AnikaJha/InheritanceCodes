#include <iostream>

#include "figure.h"

void test1()
{
//    Figure a; //not possible to create an abstract figure
    Rectangle a(5, 10, 15, 20);
    std::cout << a.calcArea() << "\n";
    Circle b(5,10,15);
    std::cout << b.calcArea() << "\n";
}

void test2()
{
    GeometryStore container;
    double areaBef = container.calcTotalArea();
    container.addCircle(2, 33, 12);
    container.addRectangle(69,69,69, 69);
    container.addTriangle(69,69,69,69,69,69);
    double areaAft = container.calcTotalArea();
    double dummy = 0;
}
void demo3()
{
    GeometryStore container;
    double areaBef = container.calcTotalArea();
    container.addCircle(2, 33, 12);
    container.addRectangle(69,69,69, 69);
    container.addTriangle(69,69,69,69,69,69);
    container.addCircle(1, 2, 3);
    container.printAlt3();

}

int main()
{
//   test1();
//   test2();
    demo3();
   return 0;
}

