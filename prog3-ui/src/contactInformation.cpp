/**
 * written by hannah faus March 2022
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
        output = "The first name of the representative is: " + firstName;
    } else if(strcasestr(inputInfo.c_str(),"last")) {  // last name
        output = "The last name of the representative is: " + lastName;
    } else if(strcasestr(inputInfo.c_str(),"nick")) {  // nick name
        output = "The nick-name of the representative is: " + nickName;
    } else {  // full name
        output = "The full name of the representative is: " + firstName + " " + nickName + " " + lastName;
    }
    cout << output << endl;  // print to command line
    return output;
}

// can grab all info or party, disctrict number, district county
string contactInformation::getPoliticalInfo(string inputInfo, string party, string districtNum, string districtCounty) {
    string output;  // to hold answer
    if(strcasestr(inputInfo.c_str(),"num")) {  // for district number
        output = "The representative's district number is: " + districtNum;
    } else if(strcasestr(inputInfo.c_str(),"county")) {  // for district county
        output = "The representative's district county is: " + districtCounty ;
    } else if(strcasestr(inputInfo.c_str(),"party")) {  // for political party
        output = "The representative's political affiliation is: " + party;
    } else {  // for all
        output = "The representative is politically affiliated as a " + party + " within the district number " + districtNum + " and the district county " + districtCounty;
    }
    cout << output << endl;  // print to command line
    return output;
}

// can grab both addresses or either home or columbia
string contactInformation::getAddressInfo(string inputInfo, string homeAdd, string colaAdd) {
    string output;  // to hold answer
    if((strcasestr(inputInfo.c_str(),"home")) || (strcasestr(inputInfo.c_str(),"live"))) {  // home address
        output = "The home address of the representative is: " + homeAdd;
    } else if(strstr(inputInfo.c_str(),"work")) {  // columbia address
        output = "The work address of the representative is: " + colaAdd;
    } else {  // both addresses
        output = "The home address of the representative is "+ homeAdd + " and the work address is " + colaAdd;
    }
    cout << output << endl;  // print to command line
    return output;
}

// can grab both phone numbers or either cell or business
string contactInformation::getPhoneInfo(string inputInfo, string cellPhone, string busPhone) {
    string output;  // to hold answer
    if((strcasestr(inputInfo.c_str(),"cell")) || (strcasestr(inputInfo.c_str(),"mobile")) || (strcasestr(inputInfo.c_str(),"home"))) {  // cell phone
        output = "The cell phone number of the representative is: " + cellPhone;
    } else if((strcasestr(inputInfo.c_str(),"bus")) || (strcasestr(inputInfo.c_str(),"work"))) {  // business phone
        output = "The business phone number of the representative is: " + busPhone;
    } else {  // both phone numbers
        output = "You can reach the representative by cell at: " + cellPhone + " or on their business phone at: " + busPhone;
    }
    cout << output << endl;  // print to command line
    return output;
}