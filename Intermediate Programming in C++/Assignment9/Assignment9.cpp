/*
* Tanner Kleintop
* March 21, 2023
* The purpose of this code is to prompt the user for a file contain a list of names. These names will be ready by the code and stored into a hash table.
* The output will but put out in the console providing who occupies each slot of the hash table.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int TABLE_SIZE = 256;  // constant size of the hash table

// Hash table entry structure
struct entry {
    string firstName;
    string lastName;
    struct entry* nextPtr;  // pointer to the next entry in case of collision
};

// Hash table
struct entry* table[TABLE_SIZE];  // an array of pointers to entry structures

// Function to generate hash key
unsigned char generateKey(string fullName) {
    unsigned char key = 0;
    for (int i = 0; i < fullName.length(); i++) {
        key ^= fullName[i];  // XOR each character of the name to get a hash value
    }
    return key;  // return the hash value as an unsigned char
}

// Function to add entry to hash table
void addEntry(string fullName) {
    unsigned char key = generateKey(fullName);  // generate a hash key for the name

    struct entry* newPtr = new struct entry;  // create a new entry structure
    newPtr->firstName = fullName.substr(0, fullName.find(' '));  // extract the first name
    newPtr->lastName = fullName.substr(fullName.find(' ') + 1);  // extract the last name
    newPtr->nextPtr = NULL;  // initialize the next pointer to NULL

    if (table[key] == NULL) {  // if the hash table slot is empty
        table[key] = newPtr;  // add the new entry to the slot
    }
    else {  // if the hash table slot is not empty
        struct entry* currPtr = table[key];
        while (currPtr->nextPtr != NULL) {  // find the last entry in the slot
            currPtr = currPtr->nextPtr;
        }
        currPtr->nextPtr = newPtr;  // add the new entry to the end of the slot
    }
}

// Function to print hash table contents
void printTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {  // loop through all the slots in the hash table
        if (table[i] != NULL) {  // if the slot is not empty
            cout << "Slot " << i << " is occupied with" << endl;
            struct entry* currPtr = table[i];  // start at the first entry in the slot
            while (currPtr != NULL) {  // loop through all the entries in the slot
                cout << "\t" << currPtr->firstName << " " << currPtr->lastName << "\t";  // print the name
                currPtr = currPtr->nextPtr;  // move to the next entry in the slot
            }
            cout << endl;
        }
    }
}

int main() {
    // Ask user for input file name
    string fileName;
    cout << "Enter input file name: ";
    cin >> fileName;

    // Open input file
    ifstream inputFile(fileName);
    if (!inputFile) {
        cout << "Error: could not open input file" << endl;
        return 1;
    }

    // Read names from input file and add them to hash table
    string fullName;
    while (getline(inputFile, fullName)) {
        addEntry(fullName);  // add each name to the hash table
    }

    // Close input file
    inputFile.close();

    // Print hash table contents
    printTable();

    return 0;
}
