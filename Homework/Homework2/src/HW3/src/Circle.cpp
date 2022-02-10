/**
 * Written by Hannah Faus Feb 2022
 * Contains methods for circle area, perimeter and errormessaage
 **/

#include "Shape.h"
#include "Circle.h"
#include <iostream>

// constructor
Circle::Circle(double radius, double pi) {
    radius = radius;
    pi = pi;
}

// calculates the area
double Circle::getArea(double radius, double pi) {
    return (pi * (radius * radius));
}

// calculates the perimeter
double Circle::getPerimeter(double radius, double pi) {
    return (2 * pi * radius);
}

// calls for an error message if input is incorrect
double Circle::getErrorMessage(double radius, double pi) {
    if (radius < 0) {  // negative input
        return 1.0;
    } else {
        return 0.0;
    }
}