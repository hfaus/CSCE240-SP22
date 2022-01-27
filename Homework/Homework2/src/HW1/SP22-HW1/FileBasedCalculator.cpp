/**
* HW1 - Jan 18 2022
* Written by Hannah Faus
**/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void readAndWrite(string operation, int num1, int num2, int answer) {
    // name of file to be read from is input.txt
    string input_file_name = "input.txt";
	string output_file_name = "output.txt";
	
    // input stream for getting the operation and number variables
	ifstream in_myfile (input_file_name);
	if (in_myfile.is_open()) {
	    while ( in_myfile >> operation >> num1 >> num2 ) {
            cout << operation << endl;
            cout << num1 << endl;
            cout << num2 << endl;
	    }
	    in_myfile.close();
	} else 
		cout << "Unable to open file - " << input_file_name << endl;
    
    // doing the operation listed to the provided numbers
    if (operation == "add") {
        answer = num1 + num2;
    } else if (operation == "subtract") {
        answer = num1 - num2;
    } else if (operation == "divide") {
        answer = num1 / num2;
    } else if (operation == "multiply") {
        answer = num1 * num2;
    } else {
        cout << "This operation cannot be found or is not valid. Please try again." << endl;
    }

    // converting ints to strings
    string sNum1 = to_string(num1);
    string sNum2 = to_string(num2);
    string sAnswer = to_string(answer);

    // output file stream
    ofstream out_myfile (output_file_name);
    if (out_myfile.is_open()) {
        string out_line = "The result of "+operation+" on "+sNum1+" and "+sNum2+" is below ";
        out_myfile << out_line << endl;
        out_myfile << answer;
    }
}

int main(int argc, char* argv[]) {
    
    // three empty variables for the three lines to be read in from input.txt
    string operation;
    int num1;
    int num2;
    // empty answer variable
    int answer;

    // calling function to be ran
    readAndWrite(operation, num1, num2, answer);
}

