// written by hannah faus Jan 2022
#include "contactInformation.h"
// #include "committeeAssignments.h"
#include "personalInformation.h"
// #include "serviceInOffice.h"
// #include "sponsoredBills.h"
// #include "votingRecord.h"

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// global variables to be used throughout class
string firstName, lastName, nickName;  // parts of name
string party, districtNum, districtCounty;  // policital information and affiliation
string homeAdd, colaAdd, cellPhone, busPhone;  // addresses and phone numbers
string personal;  // paragraph of personal information - will be sorted in next project
string inputInfo;  // what the user will ask for
vector<string> inputVector;  // to keep track on inputInfo
vector<string> outputVector;  // to keep track of outputs from other classes

// function for reading in data
void read() {
    string input_filename = "data/input.txt";  // name of file to be parsed
    string input;  // the string taken in from input file

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
}  //endfunct

void write() {
    string output_filename = "data/test_output.txt";  // name of output file
    
    // beginning of stream - outputting info
    ofstream out_myfile (output_filename);
    if (out_myfile.is_open()) {
        // looping through vector
        for (int i = 0; i < inputVector.size(); ++i) {
            // printing out what the user inputted
            out_myfile << "Input->" << inputVector.at(i);
            for (int j = 0; j < outputVector.size(); ++j) {
                // printing out the output
                out_myfile << " Output->" << outputVector.at(i);
            }
        }
    } else {
        cout << "File cannot be opened." << endl;
    }
}

// main function
int main(int argc, char* argv[]) {
    // greeting and ask for the desired district number
    cout << "Welcome to the SC district chatbot!" << endl;
    cout << "This chatbot currently only answers questions about SC District 115." << endl;
    cout << "Please enter the number of the district that you would like to ask questions about today." << endl;
    // getting the district number
    int inputDistrict;
    cin >> inputDistrict;

    // checking for correct district
    if (inputDistrict == 115) {  // extracts and reads data
        // read from input file
        read();
        // ask for what the desired information is
        cout << "Please ask what kind of information you would like to know!" << endl;
        cout << "For example, if you want to know the name, please use the format:" << endl;
        cout << "contactInformation:name" << endl;
        // what the desired information is
        string inputInfo;
        cin >> inputInfo;

        // to search through inputInfo for corresponding strings
        if(strcasestr(inputInfo.c_str(),"contact")) {  // for contactInformation
            // creating an object
            contactInformation contact(inputInfo, firstName, nickName, lastName, party, districtNum, districtCounty, homeAdd, colaAdd, cellPhone, busPhone);
            if(strcasestr(inputInfo.c_str(),"name")) {  // if contact and name
                // adding input info and calling object to get name
                inputVector.push_back(inputInfo);
                outputVector.push_back(contact.getNameInfo(inputInfo, firstName, nickName, lastName));
            } else if(strcasestr(inputInfo.c_str(),"district")) {  // if contact and district
                // adding input info and calling object to get district info
                inputVector.push_back(inputInfo);
                outputVector.push_back(contact.getPoliticalInfo(inputInfo, party, districtNum, districtCounty));
            } else if(strcasestr(inputInfo.c_str(),"address")) {  // if contact and address
                // adding input info and calling object to get address               
                inputVector.push_back(inputInfo);
                outputVector.push_back(contact.getAddressInfo(inputInfo, homeAdd, colaAdd));
            } else if(strcasestr(inputInfo.c_str(),"phone")) {  // if contact and phone
                // adding input info and calling object to get phone number
                inputVector.push_back(inputInfo);
                outputVector.push_back(contact.getPhoneInfo(inputInfo, cellPhone, busPhone));
            } else {  // if just contact
                // adding input info
                inputVector.push_back(inputInfo);
                // calling all methods because type was not specified, just contact information
                outputVector.push_back(contact.getNameInfo(inputInfo, firstName, nickName, lastName));
                outputVector.push_back(contact.getPoliticalInfo(inputInfo, party, districtNum, districtCounty));
                outputVector.push_back(contact.getAddressInfo(inputInfo, homeAdd, colaAdd));
                outputVector.push_back(contact.getPhoneInfo(inputInfo, cellPhone, busPhone));
            }
        } else if (strcasestr(inputInfo.c_str(),"committee")) {  // for committeAssignments
            cout << "Currently working on code for obtaining committee assignments." << endl;
        } else if (strcasestr(inputInfo.c_str(),"personal")) {  // for personalInformation
            // creating an object
            personalInformation pi(inputInfo, personal);
            // adding info to input vector
            inputVector.push_back(inputInfo);
            // calling class to obtain personal information... will get more specific in next portion
            outputVector.push_back(pi.getPersonalInfo(inputInfo, personal));
        } else if (strcasestr(inputInfo.c_str(),"service")) {  // for serviceInOffice
            cout << "Currently working on code for obtaining service in office." << endl;
        } else if (strcasestr(inputInfo.c_str(),"sponsor")) {  // for sponsoredBill
            cout << "Currently working on code for obtaining sponsored bills." << endl;
        } else if (strcasestr(inputInfo.c_str(),"vot")) {  // for votingRecord
            cout << "Currently working on code for obtaining voting record." << endl;
        } else {
            cout << "Matching unsuccessful" << endl;
        }
    } else {
        cout << "Sorry! We only have the content for district 115 at this time." << endl;
    }
    // writing to output file
    write();
}