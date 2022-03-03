#include "contactInformation.h"
// #include "committeeAssignments.h"
// #include "personalInformation.h"
// #include "serviceInOffice.h"
// #include "sponsoredBills.h"
// #include "votingRecord.h"
#include "section.h"

#include <iostream>
#include <string>
using namespace std;

// constructor
section::section() {
    output = "";
}

// returns the output statement
string section::getOutput() {
    return output;
}