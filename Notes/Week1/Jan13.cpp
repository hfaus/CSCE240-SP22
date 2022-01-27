/*
* Class 2
* Working on pointers and concept
*/
#include <iostream>
using namespace std;

// // & holds the address
// a = 12;  // variable is a, value is 12
// b = &a;  // b has the address of a, i.e, 0 here. Is is called a pointer
// // * refers to the value
// c = a;  // c has value of a, 12
// d = *b;  // will reefer to a. That is, d will be equal to value pointed by b, i.e., 12

// // iteration
// for(int i = 0; i < 10; i++) {
//     cout << i << endl;  // print 0 to 9
// }
// while(true) {
//     // do nothing - infinite loop
// }

// CODE FROM GITHUB
// Add the two numbers at the first location
int addNumbersAtFirstLocation(int *a, int *b) {
	
	int sum = *a + *b;  // *a=10 and *b=20
	*a = sum;  // *a=30

	return sum;
}

// Add the numbers and return the value
int addNumbers(int a, int b) {
	return a + b;
}


int main() {

	int x = 10;
	int y = 20;
	int result = -1;


	cout << "Testing adding of numbers:" << endl;
	cout << "\t x: " << x << endl;
	cout << "\t y: " << y << endl;
	result = addNumbers(x, y);
	cout << "\t add: " <<  result << endl;


	cout << "Testing adding of numbers by pointers:" << endl;
	cout << "\t x: " << x << endl;
	cout << "\t y: " << y << endl;
	result = addNumbersAtFirstLocation(&x, &y);
	cout << "\t add: " <<  result << endl;
	cout << "\t updated x value: " <<  x << endl;

	return 0;
}





// CODE FROM GITHUB - in C++
// Global variable
int swap_count = 0;

// Switching two numbers using a temp variable
void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;

	swap_count++;

}

// Bubble sort implementation
void bubbleSort(int arr[], int n) {
	int i, j;

	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}


/* Function to print an array */
void printArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++)
		cout << " " << arr[i];
	cout << " \n";
}

int main() {
	cout << "Program to sort numbers" << endl; // prints !!!Hello World!!!



	int arr[] = { 10, 5, 72, 100, 22, 11, 1, 23, 25 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Print input
	cout << "Input array: \n";
	printArray(arr, n);

	// Do sorting
	swap_count = 0;
	bubbleSort(arr, n);
	cout << "Number of swaps: \n";
	cout << swap_count;
	cout << " \n";

	// Print output
	cout << "Sorted output array: \n";
	printArray(arr, n);


	return 0;
}
