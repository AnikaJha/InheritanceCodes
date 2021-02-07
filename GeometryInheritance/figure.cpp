//
// Created by Eddie on 20.02.2020.
//
#include "figure.h"

#include <iostream>
#include <cmath>
#include <algorithm>

Figure::~Figure()
{

}

double Rectangle::calcArea() const
{
    return abs(_x1 - _x2) * abs(_y1 - _y2);
}

void Rectangle::print() const
{
    std::cout << "Rectangle: " <<_x1 << ", " << _y1 << ", " <<_x2 << ", " << _y2 << std::endl;
}

double Circle::calcArea() const
{
    return M_PI * pow(_r,2);
}

void Circle::print() const {
    std::cout << "Circle: " <<_x1 << ", " << _y1 << ", " <<_r << std::endl;

}

double Triangle::calcPerimeter() const
{
    double  perimeter =
            sqrt(pow(_x1 - _x2, 2) + pow(_y1 - _y2, 2))
            + sqrt(pow(_x2 - _x3, 2) + pow(_y2 - _y3, 2))
            + sqrt(pow(_x1 - _x3, 2) + pow(_y1 - _y3, 2));
    return perimeter;
                    //pow((abs(_x1 - _x2) + abs(_y1 - _y2)), 2))
}


double Triangle::calcArea() const
{
    double s = calcPerimeter() / 2;
    double area = sqrt(s * (s - getLenghtA()) *
                       (s - getLenghtB()) *
                       (s - getLenghtC()));
    return area;
}

void Triangle::print() const {
    std::cout << "Triangle: " <<_x1 << ", " << _y1 << ", " <<_x2 << ", "
    << _y2 << ", " <<_x3 << ", " << _y3 << std::endl;

}


Circle* GeometryStore::addCircle(double x1, double y1, double r)
{
    Circle* cirPtr = new Circle(x1, y1, r);
    _figures.push_back(cirPtr);
    return cirPtr;
}

Rectangle* GeometryStore::addRectangle(double x1, double y1, double x2, double y2)
{
    Rectangle* recPtr = new Rectangle(x1, y1, x2, y2);
    _figures.push_back(recPtr);
    return recPtr;
}

Triangle* GeometryStore::addTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    Triangle* triPtr = new Triangle(x1, y1, x2, y2, x3, y3);
    _figures.push_back(triPtr);
    return triPtr;
}

double GeometryStore::calcTotalArea() const
{
    double total = 0;
    for (auto _figure : _figures) 
    {
        total += _figure->calcArea();
    }
    return total;
}

GeometryStore::~GeometryStore()
{
    for(Figure* fig: _figures)
        delete fig;
    _figures.clear();
}


void GeometryStore::printFigures() const
{
    //Get individual getter methods for all figures.
    for (Figure* el : _figures)
    {
        if (Rectangle* pRectangle = dynamic_cast<Rectangle*>(el))
        {
            std::cout << "Rectangle" << "\n";
        }

        else if (Triangle* pTriangle = dynamic_cast<Triangle*>(el))
        {
            std::cout << "Triangle" << "\n";
        }

        else if (Circle* pCircle = dynamic_cast<Circle*>(el))
        {
            std::cout << "Circle with coordinates (" ;
            std::cout << pCircle->getX1() << ", " << pCircle ->getY1() << "). R is equal: " << pCircle ->getR() << std::endl;
        }
        else
        {
            std::cout << "Other figure" << "\n";
        }

    }
}

void GeometryStore::printFigures2() const {

    for(Figure* el: _figures) {
        el->print();
    }

}

void GeometryStore::printAlt1() const
{
    std::for_each(
            _figures.cbegin(),
            std::cend(_figures),
            printFig                        // an applicator in the form of functional ptr
            );

}

void GeometryStore::printFig(const Figure* fig)
{
    fig->print();
}
struct Printer
{
    void operator() (const Figure* fig1)
    {
        std::cout << "Figure Num: " << counter++ << "\n";
        fig1->print();
    }
    int counter = 0;
};

void GeometryStore::printAlt2() const
{
    Printer printer;
    std::for_each(
            _figures.cbegin(),
            std::cend(_figures),
            printer                     // an functor in the form of functional ptr
    );


}

void GeometryStore::printAlt3() const
{
    size_t counter = 42;
    std::for_each(
            _figures.cbegin(),
            std::cend(_figures),
            [&](const Figure* el) mutable
            {
                std::cout << counter++ << "\n";
                el->print();
            }                     // an functor in the form of functional ptr
    );

}
