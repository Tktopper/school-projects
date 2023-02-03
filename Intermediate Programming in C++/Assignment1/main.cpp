/*
Tanner Kleintop
Tuesday January 17, 2023
The purpose of this code is to read a linked list of integers using pointers to structures. The file name will be given by the user by prompting them for one.
*/
# include <iostream>
# include <fstream>
# include <cstdlib>
# include <iomanip>
using namespace std;

struct entry // structure definition
{
	int value; // data item
	struct entry* nextPtr; // pointer to next node
};

	struct entry* getEntry() { // function to get a new entry
		struct entry* newPtr; // pointer to new node

			newPtr = new struct entry; // create node
			newPtr->value = 0; // set value to 0
			newPtr->nextPtr = NULL; // set nextPtr to NULL

		return newPtr; // return address of new node
}


int main() // function main begins program execution
{
		int input; // variable to store the input
		int storeval; // variable to store the value of the input
			storeval = 0; // set storeval to 0
				ifstream inFile; // variable to store the file name
				string filename; // variable to store the file name
		cout << "Enter a file name." << endl; // prompt the user for a file name
		cin >> filename; //reads the file name
			inFile.open(filename); // open the file
				if (!inFile) {
					cout << "no file is recognized" << endl; // if the file cannot be opened, print this message
					return 1; // exit program if file cannot be opened
				}
		struct entry* firstPtr; // pointer to first node
			firstPtr = NULL; // set firstPtr to NULL
		struct entry* lastPtr; // pointer to last node
			lastPtr = NULL; // set lastPtr to NULL
		struct entry* auxPtr; // pointer to aux node
			auxPtr = NULL; // set auxPtr to NULL
	inFile >> input; // read the first value from the file

	auxPtr = getEntry(); // get a new entry
		auxPtr->value = input; // set the value of the new entry to the input
			firstPtr = lastPtr = auxPtr; // set the first and last pointers to the new entry

		inFile >> input; // read the next value from the file

	while (!inFile.fail()) { // while the file is not empty
			auxPtr = getEntry(); // get a new entry
				auxPtr->value = input; // set the value of the new entry to the input
			lastPtr->nextPtr = auxPtr;  // set the next pointer of the last entry to the new entry
				lastPtr = auxPtr; // set the last pointer to the new entry

		inFile >> input;  // read the next value from the file

	}

	inFile.close(); // close the file

	auxPtr = firstPtr; // set auxPtr to the first entry

	while (auxPtr != NULL) { // while auxPtr is not NULL
		cout << setw(15) << auxPtr->value; // print the value of the entry

			auxPtr = auxPtr->nextPtr; // set auxPtr to the next entry

			storeval++; // increment storeval

		if (storeval == 10) { // if storeval is 10
			cout << endl; // print a new line

			storeval = 0; // set storeval to 0
		}
	}
	cout << endl; // print a new line
	return 0; // exit program
}

