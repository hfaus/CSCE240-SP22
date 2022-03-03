// written by hannah faus March 2022
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


// main function
int main(int argc, char* argv[]) {
    // read from input file
    read();
        
    // ask for what the desired information is
    cout << "Hello! Welcome to the district chatbot!" << endl;
    cout << "If you would like to exit the chatbot at any time please type Quit, quit or q" << endl;
    cout << "What can I help you with today?" << endl;
    
    // what the desired information is
    string inputInfo;
    getline(cin, inputInfo);

    // infinite loop for user query
    while (inputInfo != "Quit" && inputInfo != "q" && inputInfo != "quit") {
        // what the user asked
        cout << "You asked: " + inputInfo << endl;

        // creating a contact information and personal information object
        contactInformation contact(inputInfo, firstName, nickName, lastName, party, districtNum, districtCounty, homeAdd, colaAdd, cellPhone, busPhone);
        personalInformation pi(inputInfo, personal);

        // looking for common phrases that could be used
        if(strcasestr(inputInfo.c_str(),"name")) {  // if input is name related
            contact.getNameInfo(inputInfo, firstName, nickName, lastName);
        } else if((strcasestr(inputInfo.c_str(),"live")) || (strcasestr(inputInfo.c_str(),"address"))) {  // if input is address related
            contact.getAddressInfo(inputInfo, homeAdd, colaAdd);
        } else if((strcasestr(inputInfo.c_str(),"party")) || (strcasestr(inputInfo.c_str(),"district")) || (strcasestr(inputInfo.c_str(),"politic"))) {
            contact.getPoliticalInfo(inputInfo, party, districtNum, districtCounty);
        } else if((strcasestr(inputInfo.c_str(),"contact")) || (strcasestr(inputInfo.c_str(),"phone"))) {  // if input is district related
            contact.getPhoneInfo(inputInfo, cellPhone, busPhone);
        } else if((strcasestr(inputInfo.c_str(),"personal")) || (strcasestr(inputInfo.c_str(),"school")) || (strcasestr(inputInfo.c_str(),"college")) 
            || (strcasestr(inputInfo.c_str(),"born")) || (strcasestr(inputInfo.c_str(),"birth")) || (strcasestr(inputInfo.c_str(),"parent")) 
            || (strcasestr(inputInfo.c_str(),"married")) || (strcasestr(inputInfo.c_str(),"about the rep"))) {  // if input is related to personal info
            pi.getPersonalInfo(inputInfo, personal);
        } else if(strcasestr(inputInfo.c_str(),"everything")) {  // if user wants to know everything
            contact.getNameInfo(inputInfo, firstName, nickName, lastName);
            contact.getAddressInfo(inputInfo, homeAdd, colaAdd);
            contact.getPhoneInfo(inputInfo, cellPhone, busPhone);
            contact.getPoliticalInfo(inputInfo, party, districtNum, districtCounty);
            pi.getPersonalInfo(inputInfo, personal);
        } else {  // not able to figure out what user is asking
            cout << "I do not know this information." << endl;
        }

        // to keep the loop going or allow the user to quit
        cout << "What else would you like to know about the representative?" << endl;
        getline(cin, inputInfo);
    }

    // closing remark
    cout << "Thank you for using the chatbot. Have a nice day!" << endl;
}