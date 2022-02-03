// written by hannah faus Jan 2022
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// function for reading in data
void read() {
    string input_filename = "data/input.txt";  // name of file to be parsed
    string output_filename = "data/output.txt";  // name of output file
    string input;  // word that comes in from file
    string firstName, lastName, nickName;  // parts of name
    string party, districtNum, districtCounty;  // policital information and affiliation
    string homeAdd, colaAdd, cellPhone, busPhone;  // addresses and phone numbers
    string personal;  // paragraph of personal information - will be sorted in next project

    // beginning of stream - taking in info
    ifstream in_myfile (input_filename);
    if (in_myfile.is_open()) {
        while (in_myfile >> input) {
            if (input == "Representative") {  // comes before the name portion
                in_myfile >> firstName >> nickName >> lastName;
            } else if ((input == "Republican") || (input == "Democrat") || (input == "Independent")) {  // the different affiliations
                party = input;
            } else if (input == "District") {  // comes beore the district number and county
                string ph1;  // placeholder, to skip over the "-"
                in_myfile >> districtNum >> ph1 >> districtCounty;
            } else if (input == "Columbia") {  // to check for Columbia address
                string ph1;  // placeholder
                in_myfile >> ph1;
                if (ph1 == "Address") {  // to check that it is "Columbia Address"
                    string ph2;
                    std::getline(in_myfile, ph2);  // to skip down line
                    std::getline(in_myfile, colaAdd);  // take in entire line for address
                }
            } else if (input == "Home") {  // to check for Home address
                 string ph1;  // placeholder
                 in_myfile >> ph1;
                 if (ph1 == "Address") {  // to check that it is "Home Address"
                    string ph2;
                    std::getline(in_myfile, ph2);  // to skip down line
                    std::getline(in_myfile, homeAdd);  // take in entire line for address
                 }
            } else if (input == "Business") {  // to check for Business Phone
                 string ph1;  // placeholder
                 in_myfile >> ph1;
                 if (ph1 == "Phone") {  // to check that it is "Business Phone"
                     std::getline(in_myfile, busPhone);  // take in entire line for phone
                 }
            } else if (input == "Cell") {  // to check for Cell Phone
                 string ph1;  // placeholder
                 in_myfile >> ph1;
                 if (ph1 == "Phone") {  // to check that it is "Cell Phone"
                     std::getline(in_myfile, cellPhone);  // take in entire line for phone
                 }
            } else if (input == "Personal") {  // to check for Personal Information
                 string ph1;  // placeholder
                 in_myfile >> ph1;
                 if (ph1 == "Information") {  // to check that it is "Personal Information"
                     string p2;
                     in_myfile >> p2;
                     while (p2 != "Committee") {  // will keep going until the "Committee" portion
                         personal += p2;  // adding to personalInfo string
                         personal += " ";
                         in_myfile >> p2;
                         if (p2 == "") {  // go down a line when bulletpoint is found
                             personal += "\n";
                         }  // endif
                     }  // endwhile
                 }  // endif
             }
        }  // endwhile
    } else {
        cout << "Cannot open file." << endl;
    }

    // beginning of stream - outputting info
    ofstream out_myfile (output_filename);
    if (out_myfile.is_open()) {
        out_myfile << "Name: " << firstName << " " << nickName << " "<< lastName << endl;
        out_myfile << "Political Party: " << party << "\nDistrict number: " << districtNum << "\nDistrict county: "<< districtCounty << endl;
        out_myfile << "Home addy: " << homeAdd << "\nCola addy: " << colaAdd << endl;
        out_myfile << "Cell phone: " << cellPhone << "\nBusiness phone: " << busPhone << endl;
        out_myfile << "Personal info: \n" << personal << endl;
    } else {
        cout << "File cannot be opened." << endl;
    }
}  //endfunct


// function for obtaining the statistics - number of chars, words, lines
void extract() {
    string input_filename = "data/SCLegislature.txt";  // name of file to be parsed
    string output_filename = "data/output.txt";
    string input;  // counting by char
    int numChars, numWords, numLines;  // for keeping track of stats
    
    // beginning of stream - taking in info
    ifstream in_myfile (input_filename);
    if (in_myfile.is_open()) {
        while(std::getline(in_myfile, input)) {
            ++numLines;
            for (int i = 0; i < input.length(); ++i) {  // looping through the line (input)
                ++numChars;
                if (input.at(i) == ' ') {  // seaching for words separated by a space
                    ++numWords;
                }  // endif
            }  // endfor
            numWords += 1;  // to account for words at the end of line
        }  // endwhile
    } else {
        cout << "File cannot be opened." << endl;
    }  // endelse

    // beginning of stream - for outputting info
    ofstream out_myfile (output_filename, ios::app);
    if (out_myfile.is_open()) {
        out_myfile << "\n" << endl;
        out_myfile << "Statistics for " << input_filename << ":" << endl;
        out_myfile << "Number of characters: " << numChars << endl;
        out_myfile << "Number of words: " << numWords << endl;
        out_myfile << "Number of lines: " << numLines << endl;
    } else {
        cout << "File cannot be opened." << endl;
    }
}  // end funct

// main function
int main(int argc, char* argv[]) {
    cout << "Welcome to the SC district chatbot!" << endl;
    cout << "This chatbot currently only answers questions about SC District 115." << endl;
    cout << "Please enter the number of the district that you would like to ask questions about today." << endl;

    // getting the district number
    int inputDistrict;
    cin >> inputDistrict;

    // checking for correct district
    if (inputDistrict == 115) {  // extracts and reads data
        read();
        extract();
    } else {
        cout << "Sorry! We only have the content for district 115 at this time." << endl;
    }
}