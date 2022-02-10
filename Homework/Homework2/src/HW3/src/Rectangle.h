/**
 * Written by Hannah Faus Feb 2022
 * header file for Rectangle.cpp
 **/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <string>

class Rectangle : public Shape { 
    public:
       // methods
       Rectangle(double length, double breadth);
        double getArea(double length, double breadth);
        double getPerimeter(double length, double breadth);
        double getErrorMessage(double length, double breadth);
    
    private:
        // variables
        double length, breadth;
};

#endif  // RECTANGLE_H