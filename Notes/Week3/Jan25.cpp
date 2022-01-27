/**
 * When we start solving real world problems, we often use a set of info
 * Ex - 
 *      Name = {title, first-name, middle-name, last-name, suffix};
 *      Address = {street-name, number, city, state, zip code};
 * 
 * Why user defined types?
 * -easier to understand
 * -easier to test
 * -abstraction helps in communication
 * 
 * C++ concepts:
 * struct and class (object oriented programming)
 * 
 * User defined types:
 * -Encapsulation (cognitive)
 * -Security
 * -Separation of concern
 * 
 * -------------------------------------------------
 * Types of memory allocation:
 * -Static - when size is known at compile time
 *      -Basic data types
 *      -Arrays
 * -Dynamic - when size is not known ahead of time
 *      -User defined types
 *      -Linked lists
 **/

//CODE FROM GITHUB
#include <iostream>
#include <string>
using namespace std;

// A declaration for person's name
struct PersonName
{
   string firstName;
   string lastName;
};

// A declaration for person's important vitals
struct PersonVitals
{
   int height; // Heights in cms
   int weight; // Weight in kgs
};

// A declaration for person's important vitals
struct PersonInfo
{
   PersonName name; // Person's name
   PersonVitals vitals; // Person's viatls
};



int demoStruct() {
	cout << "\n*** DEMO of struct ***\n\n";

	cout << "\tInitializing for a person's name";
	PersonName pn = {"John", "Doe"} ;
	cout << "\t -" << pn.firstName << " / " << pn.lastName << endl;
	
	cout << "\tInitializing for a person's vitals";
	PersonVitals pv = {150, 50} ;
	cout << "\t -" << pv.height << " / " << pv.weight << endl;
	
	cout << "\tInitializing for first person's information - name and vitals";
	PersonInfo p1 = {pn, pv};
	cout << "\t -" << p1.name.firstName << " / " << p1.vitals.weight << endl;

	cout << "\tInitializing for second person's information - name and vitals";
	PersonInfo p2 = {"Jane", "Doe", 200, 100};
	cout << "\t -" << p2.name.firstName << " / " << p2.vitals.height << endl;

	cout << "\tInitializing for third person's information - name and vitals";
	PersonInfo p3 = {{"First", "Second"}, {300, 150}};
	cout << "\t -" << p3.name.firstName << " / " << p3.name.lastName << " / " << p3.vitals.height << " / " << p3.vitals.weight << endl;

	return 0;
}

int demoStaticMemoryAllocation() {
	cout << "\n*** DEMO of static memory allocation ***\n\n";

	// Problem: find the average of a random set of random numbers
	
	// Static case - will have to assume an upper bound of 100 numbers to be stored
	
	// Credits: https://www.cplusplus.com/reference/cstdlib/rand/
    
	// initialize random seed: 
	srand (time(NULL));
	
	  // Actual code from below  
	int UPPER_BOUND = 100;
	int a[UPPER_BOUND];
	
	int times = rand() % UPPER_BOUND; // Numbers between 0 to 99
	int i, sum = 0;
	
	// Store random numbers
	for(i=0;i<times;i++) {
		a[i] = rand() % (10 * UPPER_BOUND);// Store a random number between 0 to 999
		sum += a[i]; // Store the cummulative sums
	}
	
	// Give the average
	cout << "Average of " << times << " random numbers is - " << 
(sum / times) << endl;
	cout << "Wasted memory = " << (UPPER_BOUND - times) << " spaces in the array." << endl;
	cout << "Numbers are: " << endl;
	for(i=0;i<times;i++) {
			cout << "\t i = " << i << ": " << a[i] << endl; // Print each number
		}
	
	
	return 0;
}

int demoDynamicMemoryAllocation() {
	cout << "\n*** DEMO of dynamic memory allocation ***\n\n";

	// Problem: find the average of a random set of random numbers
	
	// Static case - will have to assume an upper bound of 100 numbers to be stored
	
	// Credits: https://www.cplusplus.com/reference/cstdlib/rand/
    
	// initialize random seed: 
	srand (time(NULL));
	
	  // Actual code from below  
	int UPPER_BOUND = 100;
	int times = rand() % UPPER_BOUND; // Numbers between 0 to 99
	

	int *a = new int[times];

	int i, sum = 0;
	
	// Store random numbers
	for(i=0;i<times;i++) {
		a[i] = rand() % (10 * UPPER_BOUND);// Store a random number between 0 to 999
		sum += a[i]; // Store the cummulative sums
	}
	
	// Give the average
	cout << "Average of " << times << " random numbers is - " << 
(sum / times) << endl;
	cout << "Wasted memory = " << (times - times) << " spaces in the array." << endl;
	cout << "Numbers are: " << endl;
	for(i=0;i<times;i++) {
			cout << "\t i = " << i << ": " << a[i] << endl; // Print each number
		}
	
	// Free a
	delete[](a); // Alternatively delete(a)
	
	
	return 0;
}

// --- Main ---

int main(int argc, char *argv[]) {

	char command = 0;
	string str = "";

	// First argument is program name
	cout << "Program name : " << argv[0] << endl;

	if (argc == 1) {
		printf("\nNo command passed. By default, will be demoing struct.");
		demoStruct();
	} else {
		// argc >= 2
		command = *argv[1];

		cout << "Command to run is - " << command << endl;
	}

	// Now execute based on command

	if (command == '0') {
		// Show data types
		demoStruct();
	} else if (command == '1') {
		// Demo static memory allocation
		demoStaticMemoryAllocation();
		
	} else if (command == '2') {
		// Demo reading of file
		demoDynamicMemoryAllocation();
		
	} 

	return 0;
}