/**
 * Written by Hannah Faus Feb 2022
 * Parent class to Triangle, Circle, Rectangle
 * Has three members: getArea, getPerimeter, getErrorMessage
 **/
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include <iostream>

// constructor
Shape::Shape() {
    area = 0.0;
    perimeter = 0.0;
    errorMessage = 0.0;
}

// returns area
double Shape::getArea() {
    return area;
}

// returns perimeter
double Shape::getPerimeter() {
    return perimeter;
}

// returns call for error message
double Shape::getErrorMessage() {
    return errorMessage;
}