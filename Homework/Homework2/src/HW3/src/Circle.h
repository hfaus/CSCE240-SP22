/**
 * Written by Hannah Faus Feb 2022
 * header file for Circle.cpp
 **/

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : Shape { 
    public:
        // methods
        Circle(double radius, double pi);
        double getArea(double radius, double pi);
        double getPerimeter(double radius, double pi);
        double getErrorMessage(double radius, double pi);
    
    private:
        // variables
        double radius, pi;
};

#endif  // CIRCLE_H