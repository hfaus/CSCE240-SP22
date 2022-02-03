/** Written by Hannah Faus
* Jan 2022 - Project 1 - CSCS 240
**/

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// function for reading in data
void read() {
    string filename = "data/SCLegislature.txt";  // name of file to be parsed
    string input;  // word that comes in from file
    string firstName, lastName, nickName;  // parts of name
    string party, districtNum, districtCounty;  // policital information and affiliation
    string homeAdd, colaAdd, cellPhone, busPhone;  // addresses and phone numbers
    string personalInfo;  // paragraph of personal information - will be sorted in next project

    // beginning of stream - taking in info
    ifstream in_myfile (filename);
    if (in_myfile.is_open()) {
        while (in_myfile >> input) {
            if (input == "Representative") {  // comes before the name portion
                in_myfile >> firstName >> nickName >> lastName;
                cout << "First name is: " << firstName << endl;
                cout << "Nick name is: " << nickName << endl;
                cout << "Last name is: " << lastName << endl;
            } else if ((input == "Republican") || (input == "Democrat") || (input == "Independent")) {  // the different affiliations
                party = input;
                cout << "Political party is: " << party << endl;
            } else if (input == "District") {  // comes beore the district number and county
                string ph1;  // placeholder, to skip over the "-"
                in_myfile >> districtNum >> ph1 >> districtCounty;
                cout << "District number is: " << districtNum << endl;
                cout << "District county is: " << districtCounty << endl;
            } else if (input == "Columbia") {  // to check for Columbia address
                string ph1;  // placeholder
                in_myfile >> ph1;
                if (ph1 == "Address") {  // to check that it is "Columbia Address"
                    string ph2;
                    std::getline(in_myfile, ph2);  // to skip down line
                    std::getline(in_myfile, colaAdd);  // take in entire line for address
                    cout << "Cola add is: " << colaAdd << endl;
                }
            } else if (input == "Home") {  // to check for Home address
                 string ph1;  // placeholder
                 in_myfile >> ph1;
                 if (ph1 == "Address") {  // to check that it is "Home Address"
                    string ph2;
                    std::getline(in_myfile, ph2);  // to skip down line
                    std::getline(in_myfile, homeAdd);  // take in entire line for address
                    cout << "Home add is: " << homeAdd << endl;
                 }
            } else if (input == "Business") {  // to check for Business Phone
                 string ph1;  // placeholder
                 in_myfile >> ph1;
                 if (ph1 == "Phone") {  // to check that it is "Business Phone"
                     std::getline(in_myfile, busPhone);  // take in entire line for phone
                     cout << "Bus phone is: " << busPhone << endl;
                 }
            } else if (input == "Cell") {  // to check for Cell Phone
                 string ph1;  // placeholder
                 in_myfile >> ph1;
                 if (ph1 == "Phone") {  // to check that it is "Cell Phone"
                     std::getline(in_myfile, cellPhone);  // take in entire line for phone
                     cout << "Cell phone is: " << cellPhone << endl;
                 }
            } else if (input == "Personal") {  // to check for Personal Information
                 string ph1;  // placeholder
                 in_myfile >> ph1;
                 if (ph1 == "Information") {  // to check that it is "Personal Information"
                     string p2;
                     in_myfile >> p2;
                     while (p2 != "Committee") {  // will keep going until the "Committee" portion
                         personalInfo += p2;  // adding to personalInfo string
                         personalInfo += " ";
                         in_myfile >> p2;
                         if (p2 == "*") {  // go down a line when bulletpoint is found
                             personalInfo += "\n";
                         }  // endif
                     }  // endwhile
                     cout << "Personal info is: " << personalInfo << endl;
                 }  // endif
             }
        }  // endwhile
    }  // endif
}  //endfunct

// main function
int main() {
    read();  // calling read function
}
