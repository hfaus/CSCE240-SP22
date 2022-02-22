/**
 * written by hannah faus Feb 2022
 **/
#include "personalInformation.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// constructor
personalInformation::personalInformation(string inputInfo, string personal) {
    inputInfo = inputInfo;
    // the personal information
    personal = personal;
}

// to obtain the personal information
string personalInformation::getPersonalInfo(string inputInfo, string personal) {
    string output;  // to hold answer
    output = personal;  // to get answer
    cout << output << endl;  // print to command line
    return output;
}