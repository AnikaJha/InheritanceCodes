//
// Created by Eddie on 20.02.2020.
//

#ifndef GEOMETRYINHERITANCE_FIGURE_H
#define GEOMETRYINHERITANCE_FIGURE_H

#include <iostream>
#include <cmath>
#include <vector>

class Figure
{
public:
    virtual double calcArea() const = 0;
    virtual ~Figure();
    virtual void print() const = 0;
};

class Rectangle : public Figure
{

public:
    Rectangle (double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0)
        :_x1(x1),_x2(x2),_y1(y1),_y2(y2)
    {}

    virtual ~Rectangle(){}

public:
    virtual double calcArea() const override;
    virtual void print() const override ;

protected:
    double _x1, _y1;
    double _x2, _y2;
};


class Circle : public Figure
{

public:
    Circle (double x1 = 0, double y1 = 0, double r = 0)
            :_x1(x1), _y1(y1), _r(r)
    {}

    virtual ~Circle(){}

public:
    virtual double calcArea() const override;
    virtual void print() const override ;

public:
    double getX1() const { return _x1; }
    double getY1() const { return _y1; }
    double getR() const { return _r; }

protected:
    double _x1, _y1;
    double _r;
};

class Triangle : public Figure
{
public:
    Triangle (double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0, double x3 = 0, double y3 = 0)
        :_x1(x1), _y1(y1), _x2(x2), _y2(y2), _x3(x3), _y3(y3)
    {}

    virtual ~Triangle(){}

public:
    virtual double calcArea() const override;
    virtual void print() const override ;
    double calcPerimeter() const;

    double getLenghtA() const
    {
        return sqrt(pow(_x1 - _x2, 2) + pow(_y1 - _y2, 2));
    }

    double getLenghtB() const
    {
        return sqrt(pow(_x2 - _x3, 2) + pow(_y2 - _y3, 2));
    }
    double getLenghtC() const
    {
        return sqrt(pow(_x1 - _x3, 2) + pow(_y1 - _y3, 2));
    }

protected:
    double _x1, _y1, _x2, _y2,_x3, _y3;
};


class GeometryStore
{
public:
    //GeometryStore() {}; //will be added by the compiler by default
    ~GeometryStore();
public:
    typedef std::vector<Figure*> Storage;

    Rectangle* addRectangle (double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0);
    Circle* addCircle (double x1 = 0, double y1 = 0, double r = 0);
    Triangle* addTriangle(double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0, double x3 = 0, double y3 = 0);
    double calcTotalArea() const;
//    double getPtrs();

    void printFigures() const;
    void printFigures2() const;
    void printAlt1() const;
    void printAlt2() const;
    void printAlt3() const;

    static void printFig(const Figure* fig);

protected:
    Storage _figures;
};

#endif //GEOMETRYINHERITANCE_FIGURE_H
