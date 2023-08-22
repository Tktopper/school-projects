/*
* Tanner Kleintop
* February 21, 2023
* The purpose of this code is to take a old master file and a transaction file and combine them into one new master file
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Declare variables to store file names
    string oldMasterFileName, transactionFileName, newMasterFileName;

// Prompt user for input file names
cout << "Enter the name of the old master file: ";
cin >> oldMasterFileName;
cout << "Enter the name of the transaction file: ";
cin >> transactionFileName;
cout << "Enter the name of the new master file: ";
cin >> newMasterFileName;

// Open the input and output files
ifstream inOldMaster(oldMasterFileName.c_str(), ios::in);
ifstream inTransaction(transactionFileName.c_str(), ios::in);
ofstream outNewMaster(newMasterFileName.c_str(), ios::out);

// Check if the files were successfully opened
if (!inOldMaster) {
    cout << "Could not open " << oldMasterFileName << endl;
    return 1;
}
if (!inTransaction) {
    cout << "Could not open " << transactionFileName << endl;
    return 1;
}
if (!outNewMaster) {
    cout << "Could not create " << newMasterFileName << endl;
    return 1;
}

// Declare variables to store data from the files
int accountNumber, accountNum;
string firstName, lastName;
double currentBalance, dollarAmount;

// Read the first record from the old master file
inOldMaster >> accountNumber >> firstName >> lastName >> currentBalance;

// Read the first record from the transaction file
if (!inTransaction.eof()) {
    inTransaction >> accountNum >> dollarAmount;
}

// Loop through the records in both files
while (!inOldMaster.eof() && !inTransaction.eof()) {
    if (accountNumber == accountNum) {
        // If the account is in both files, update the balance
        currentBalance += dollarAmount;
        // Write the updated record to the new master file
        outNewMaster << accountNumber << " " << firstName << " " << lastName << " " << currentBalance << endl;
        // Read the next records from both files
        if (!inOldMaster.eof()) {
            inOldMaster >> accountNumber >> firstName >> lastName >> currentBalance;
        }
        if (!inTransaction.eof()) {
            inTransaction >> accountNum >> dollarAmount;
        }
    }
    else if (accountNumber < accountNum) {
        // If the account is only in the old master file, copy the record to the new master file
        outNewMaster << accountNumber << " " << firstName << " " << lastName << " " << currentBalance << endl;
        // Read the next record from the old master file
        if (!inOldMaster.eof()) {
            inOldMaster >> accountNumber >> firstName >> lastName >> currentBalance;
        }
    }
    else {
        // If the account is only in the transaction file
        cout << "Unmatched transaction record for account number " << accountNum << endl;
        // Read the next record from the transaction file
        if (!inTransaction.eof()) {
            inTransaction >> accountNum >> dollarAmount;
        }
    }
}

// Handle remaining records in transaction file if old master file has reached end-of-file
while (!inTransaction.eof()) {
    inTransaction >> accountNum >> dollarAmount;
    cout << "Unmatched transaction record for account number " << accountNum << endl;
}

// Copy any remaining records from the old master file to the new master file
while (!inOldMaster.eof()) {
    outNewMaster << accountNumber << " " << firstName << " " << lastName << " " << currentBalance << endl;
    inOldMaster >> accountNumber >> firstName >> lastName >> currentBalance;
}

// Close the files
inOldMaster.close();
inTransaction.close();
outNewMaster.close();

return 0;
}
