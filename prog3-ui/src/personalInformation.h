/**
 * written by hannah faus Feb 2022
 * header file for personalInformation.cpp
 **/

#ifndef PERSONALINFORMATION_H
#define PERSONALINFORMATION_H
#include <string>
using namespace std;

class personalInformation { 
    public:
        // constructor method
        personalInformation(string inputInfo, string personal);
        // other method
        string getPersonalInfo(string inputInfo, string personal);
        // variables
        string inputInfo, personal;
};

#endif  // PERSONALINFORMATION_H