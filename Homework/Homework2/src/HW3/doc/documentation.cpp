Commands to execute:
g++ src/OOGeometricPropertyCalculator.cpp src/Rectangle.cpp src/Shape.cpp src/Triangle.cpp src/Circle.cpp
./a.out

This code takes in an input from the user, 1 or 2. And then calculates the area(1) or perimeter(2) for a list of shapes 
and sizes listed in input.txt. These shapes then access their respective .cpp class to calculate the area, perimeter, and
possibly the erroMessage if an invalid input was put in. After all of the shapes have been read through, the shape name is
read out along with either the area or perimeter to output.txt with a note at the top saying what was being displayed.
