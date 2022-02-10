/**
 * Written by Hannah Faus Feb 2022
 * Contains methods for rectangle area, perimeter and errormessaage
 **/
#include "Shape.h"
#include "Rectangle.h"

// constructor
Rectangle::Rectangle(double length, double breadth) {
    length = length;
    breadth = breadth;
}

// calculates the area
double Rectangle::getArea(double length, double breadth) {
    return (length * breadth);
}

// calculates the perimeter
double Rectangle::getPerimeter(double length, double breadth) {
    return (2 * (length + breadth));
}

// calls for an error message if input is incorrect
double Rectangle::getErrorMessage(double length, double breadth) {
    if (length < 0 || breadth < 0) {  // negative input
        return 1.0;
    } else {
        return 0.0;
    }
}