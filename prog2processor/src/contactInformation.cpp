/**
 * written by hannah faus Feb 2022
 **/
#include "contactInformation.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// constructor
contactInformation::contactInformation(string inputInfo, string firstName, string nickName, string lastName, 
            string party, string districtNum, string districtCounty, 
            string homeAdd, string colaAdd, string cellPhone, string busPhone) {
    inputInfo = inputInfo;
    // name
    firstName = firstName;
    nickName = nickName;
    lastName = lastName;
    // political
    party = party;
    districtNum = districtNum;
    districtCounty = districtCounty;
    // address
    homeAdd = homeAdd;
    colaAdd = colaAdd;
    // phone
    cellPhone = cellPhone;
    busPhone = busPhone;
}

// can grab full name or parts of name    
string contactInformation::getNameInfo(string inputInfo, string firstName, string nickName, string lastName) {
    string output;  // to hold answer
    if(strcasestr(inputInfo.c_str(),"first")) {  // first name
        output = firstName;
    } else if(strcasestr(inputInfo.c_str(),"last")) {  // last name
        output = lastName;
    } else if(strcasestr(inputInfo.c_str(),"nick")) {  // nick name
        output = nickName;
    } else {  // full name
        output = firstName + " " + nickName + " " + lastName;
    }
    cout << output << endl;  // print to command line
    return output;
}

// can grab all info or party, disctrict number, district county
string contactInformation::getPoliticalInfo(string inputInfo, string party, string districtNum, string districtCounty) {
    string output;  // to hold answer
    if(strcasestr(inputInfo.c_str(),"num")) {  // for district number
        output = districtNum;
    } else if(strcasestr(inputInfo.c_str(),"county")) {  // for district county
        output = districtCounty;
    } else if(strcasestr(inputInfo.c_str(),"party")) {  // for political party
        output = party;
    } else {  // for all
        output = party + " " + districtNum + " " + districtCounty;
    }
    cout << output << endl;  // print to command line
    return output;
}

// can grab both addresses or either home or columbia
string contactInformation::getAddressInfo(string inputInfo, string homeAdd, string colaAdd) {
    string output;  // to hold answer
    if(strcasestr(inputInfo.c_str(),"home")) {  // home address
        output = homeAdd;
    } else if(strstr(inputInfo.c_str(),"col")) {  // columbia address
        output = colaAdd;
    } else {  // both addresses
        output = homeAdd + " " + colaAdd;
    }
    cout << output << endl;  // print to command line
    return output;
}

// can grab both phone numbers or either cell or business
string contactInformation::getPhoneInfo(string inputInfo, string cellPhone, string busPhone) {
    string output;  // to hold answer
    if(strcasestr(inputInfo.c_str(),"cell")) {  // cell phone
        output = cellPhone;
    } else if(strcasestr(inputInfo.c_str(),"bus")) {  // business phone
        output = busPhone;
    } else {  // both phone numbers
        output = cellPhone + " " + busPhone;
    }
    cout << output << endl;  // print to command line
    return output;
}