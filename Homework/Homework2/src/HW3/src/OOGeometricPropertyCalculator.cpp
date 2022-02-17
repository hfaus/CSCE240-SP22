/**
 * Written by Hannah Faus Feb 2022
 * The main file to read, write and access
 **/

#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// reads, writes, calls
void readAndWrite(int option, vector<string> nameVector, vector<double> perimeterVector, vector<double> areaVector, vector<double> errorVector) {
    // strings for the input file
    string input_filename = "data/input.txt";
    
    // variables to be used and read in throughout function
    string name;
    double length, breadth, side1, side2, side3, radius;

    // beginning of the input file
    ifstream in_myfile (input_filename);
    if (in_myfile.is_open()) {
        // takes in the name of the shape
        while (in_myfile >> name) {
            // checking for the correct name of shape
            if (name == "RECTANGLE") {
                // takes in the dimensions
                in_myfile >> length >> breadth;
                // rectangle object - get info from rectangle class
                Rectangle rect(length, breadth);
                double a = rect.getArea(length, breadth);
                double p = rect.getPerimeter(length, breadth);
                double e = rect.getErrorMessage(length, breadth);
                // add to vector
                areaVector.push_back(a);
                perimeterVector.push_back(p);
                errorVector.push_back(e);
                nameVector.push_back(name);
            } else if (name == "CIRCLE") {
                // takes in the dimension              
                in_myfile >> radius;
                // circle object - get info from circle class
                Circle circ(radius, 3.14);
                double a = circ.getArea(radius, 3.14);
                double p = circ.getPerimeter(radius, 3.14);
                double e = circ.getErrorMessage(radius, 3.14);
                // add to vector
                areaVector.push_back(a);
                perimeterVector.push_back(p);
                errorVector.push_back(e);
                nameVector.push_back(name);
            } else if (name == "TRIANGLE") {
                // takes in dimensions
                in_myfile >> side1 >> side2 >> side3;
                // triangle object - get info from triangle class
                Triangle tri(side1, side2, side3);
                double a = tri.getArea(side1, side2, side3);
                double p = tri.getPerimeter(side1, side2, side3);
                double e = tri.getErrorMessage(side1, side2, side3);
                // add to vector
                areaVector.push_back(a);
                perimeterVector.push_back(p);
                errorVector.push_back(e);
                nameVector.push_back(name);
            } else {
                // if an invalid shape name is entered / incorrect formatting
                cout << "The shape listed is invalid." << endl;
            }
        }
        in_myfile.close();  // closing input file
    } else {
            // if input file cannot be opened
            cout << "Unable to open file - " << input_filename << endl;
    }

    // beginning of output file
    string output_filename = "data/output.txt";
    // beginning of output file
    ofstream out_myfile (output_filename);
    if (out_myfile.is_open()) {
        if (option == 1) {  // area
            out_myfile << "The areas for the provided shapes are below." << endl;
            // for loop for obtaining name and areas
            for (int i = 0; i < nameVector.size(); ++i) {
                out_myfile << nameVector[i] << " " << areaVector[i] << endl;
                if (errorVector[i] == 1.0) {
                    out_myfile << "ERROR: Area above contains illegal inputs." << endl;
                }
            }
        } else {  // perimeter
            out_myfile << "The perimeters for the provided shapes are below." << endl;
            // for loop for obtaining name and perimeters
            for (int i = 0; i < nameVector.size(); ++i) {
                out_myfile << nameVector[i] << " " << perimeterVector[i] << endl;
                if (errorVector[i] == 1.0) {
                    out_myfile << "ERROR: Perimeter above contains illegal inputs." << endl;
                }
            }
        }
    }
}

// void write(int option, vector<string> nameVector, vector<double> areaVector, vector<double> perimeterVector) {
//     string output_filename = "data/output.txt";
//     // beginning of output file
//     ofstream out_myfile (output_filename);
//     if (out_myfile.is_open()) {
//         if (option == 1) {
//             for (int i = 0; i < nameVector.size(); ++i) {
//                 out_myfile << "The areas for the provided shapes are below." << endl;
//                 out_myfile << nameVector[i] << " " << areaVector[i] << endl;
//             }
//         } else {
//             for (int i = 0; i < nameVector.size(); ++i) {
//                 out_myfile << "The perimeters for the provided shapes are below." << endl;
//                 out_myfile << nameVector[i] << " " << perimeterVector[i] << endl;
//             }
//         }
//     }
// }

int main(int argc, char* argv[]) {
    // vectors for storing name, area, perimeter
    vector<string> nameVector;
    vector<double> perimeterVector;
    vector<double> areaVector;
    vector<double> errorVector;

    cout << "Welcome to the Geometric Property Calculator! Here you can ";
    cout << "decide whether you would like to know the area or perimeter for an ";
    cout << "assortment of RECTANGLEs, CIRCLEs, or TRIANGLES." << endl;
    cout << "Be aware that the area of a TRIANGLE will be ";
    cout << "calculated with the first and second side of " << endl;
    cout << "the TRIANGLE." << endl;
    cout << " " << endl;

    // getting the option
    int option;
    cout << "Please enter number 1 for AREA or 2 for PERIMETER." << endl;
    cin >> option;

    // checking for correct option
    if (option != 1 && option != 2) {  // invailid option
        cout << "The number inputted was invalid. Please try again with either 1 or 2." << endl;
    } else {  // valid option
        readAndWrite(option, nameVector, perimeterVector, areaVector, errorVector);
        // write(option, nameVector, areaVector, perimeterVector);
    }
}
