/**
 * Written by Hannah Faus Feb 2022
 * Header file to Shape.cpp
 **/

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
    public:
        // methods
        Shape();
        double getArea();
        double getPerimeter();
        double getErrorMessage();
        
    private:
        // variables
        double area, perimeter, errorMessage;
};

#endif  // SHAPE_H