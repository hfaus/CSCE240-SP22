/**
 * written by hannah faus Feb 2022
 * header file for contactInformation.cpp
 **/

#ifndef CONTACTINFORMATION_H
#define CONTACTINFORMATION_H
#include <string>
using namespace std;

class contactInformation { 
    public:
        // constructor methods
        contactInformation(string inputInfo, string firstName, string nickName, string lastName, 
            string party, string districtNum, string districtCounty, 
            string homeAdd, string colaAdd, string cellPhone, string busPhone);
        // other methods
        string getNameInfo(string inputInfo, string firstName, string nickName, string lastName);
        string getPoliticalInfo(string inputInfo, string party, string districtNum, string districtCounty);
        string getAddressInfo(string inputInfo, string homeAdd, string colaAdd);
        string getPhoneInfo(string inputInfo, string cellPhone, string busPhone);
        // variables
        string inputInfo, firstName, nickName, lastName, party, districtNum, districtCounty, homeAdd, colaAdd, cellPhone, busPhone;
};

#endif  // CONTACTINFORMATION_H