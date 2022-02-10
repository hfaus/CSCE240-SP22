/**
 * Written by Hannah Faus Feb 2022
 * Contains methods for triagle area, perimeter and errormessaage
 **/

#include "Shape.h"
#include "Triangle.h"
#include <iostream>

// constructor
Triangle::Triangle(double side1, double side2, double side3) {
    side1 = side1;
    side2 = side2;
    side3 = side3;
}

// calculates the area
double Triangle::getArea(double side1, double side2, double side3) {
    return (0.5 * (side1 + side2));
}

// calculates the perimeter
double Triangle::getPerimeter(double side1, double side2, double side3) {
    return (side1 + side2 + side3);
}

// calls for an error message if input is incorrect
double Triangle::getErrorMessage(double side1, double side2, double side3) {
    if (side1 < 0 || side2 < 0 || side3 < 0) {  // negative input
        return 1.0;
    } else {
        return 0.0;
    }
}