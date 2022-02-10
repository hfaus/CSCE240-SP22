/**
 * Written by Hannah Faus Feb 2022
 * header file for Triangle.cpp
 **/

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : Shape { 
    public:
        // methods
        Triangle(double side1, double side2, double side3);
        double getArea(double side1, double side2, double side3);
        double getPerimeter(double side1, double side2, double side3);
        double getErrorMessage(double side1, double side2, double side3);

    private:
        // variables
        double side1, side2, side3;
};

#endif