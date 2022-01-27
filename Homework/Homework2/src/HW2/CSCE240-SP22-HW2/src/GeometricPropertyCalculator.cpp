/**
 * Spring 2022 CSCE 240
 * Written by Hannah Faus
 **/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


void readAndWrite(vector<string> shapeName, vector<double> shapeArea, vector<double> shapePerimeter, int option) {
    // strings for the input file
    string input_filename = "data/input.txt";
    string output_filename = "data/output.txt";
    
    // variables to be used and read in throughout function
    string name;
    double num1, num2, num3, area, perimeter;
    double pi = 3.1415;

    // beginning of the input file
    ifstream in_myfile (input_filename);
    if (in_myfile.is_open()) {
        // takes in the name of the shape
        while (in_myfile >> name) {
            // checking for the correct name of shape
            if (name == "RECTANGLE") {
                // takes in the dimensions
                in_myfile >> num1 >> num2;
                // calculating area and perimeter
                area = num1 * num2;
                perimeter = 2 * (num1 + num2);
                // adding information to appropiate vector
                shapeName.push_back(name);
                shapeArea.push_back(area);
                shapePerimeter.push_back(perimeter);
            } else if (name == "CIRCLE") {
                // takes in the dimension              
                in_myfile >> num1;
                // calculating area and perimeter
                area = pi * (num1 * num1);
                perimeter = 2 * pi * num1;
                // adding information to appropiate vector
                shapeName.push_back(name);
                shapeArea.push_back(area);
                shapePerimeter.push_back(perimeter);
            } else if (name == "TRIANGLE") {
                // takes in dimensions
                in_myfile >> num1 >> num2 >> num3;
                // calculating perimeter, area is 0 bc we don't have enough info to calculate area
                area = 0;
                perimeter = num1 + num2 + num3;
                // adding information to appropiate vector
                shapeName.push_back(name);
                shapeArea.push_back(area);
                shapePerimeter.push_back(perimeter);
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
    ofstream out_myfile (output_filename);
    if (out_myfile.is_open()) {
        // for the size of the name vector
        for(int i = 0; i < shapeName.size(); i++){
            // send name of shape to output file
            out_myfile << shapeName[i];
            // if area was selected
            if (option == 1) {
                out_myfile << " AREA " << shapeArea[i] << endl;  // send area of shape to output file
            } else if (option == 2) {  // if perimeter was selected
                out_myfile << " PERIMETER " << shapePerimeter[i] << endl;  // send perimeter of shape to output file
            }
        }
    }
}

// void write(vector<string> shapeName, vector<int> shapeArea, vector<int> shapePerimeter, int option) {
//     string output_filename = "data/output.txt";
    
//     ofstream out_myfile (output_filename);
//     if (out_myfile.is_open()) {
//         for(int i = 0; i < shapeName.size(); i++){
//             out_myfile << shapeName[i];
//             if (option == 1) {
//                 out_myfile << " AREA " << shapeArea[i] << endl;
//             } else if (option == 2) {
//                 out_myfile << " PERIMETER " << shapePerimeter[i] << endl;
//             }
//         }
//     }
//     out_myfile.close();
// }

int main(int argc, char* argv[]) {
    vector<string> shapeName;
    vector<double> shapeArea;
    vector<double> shapePerimeter;

    cout << "Welcome to the Geometric Property Calculator! Here you can ";
    cout << "decide whether you would like to know the area or perimeter for an ";
    cout << "assortment of RECTANGLEs, CIRCLEs, or TRIANGLES." << endl;
    cout << "Be aware that the area of a TRIANGLE cannot be ";
    cout << "calculated with the current, limited information. " << endl;
    cout << "Therefore, a 0 will be listed as the TRIANGLE's area." << endl;
    cout << " " << endl;

    int option;
    cout << "Please enter number 1 for AREA or 2 for PERIMETER." << endl;
    cin >> option;

    if (option != 1 && option != 2) {
        cout << "The number inputted was invalid. Please try again with either 1 or 2." << endl;
    } else {
        readAndWrite(shapeName, shapeArea, shapePerimeter, option);
        // write(shapeName, shapeArea, shapePerimeter, option);
    }
}
