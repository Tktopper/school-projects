/*
* Tanner Kleintop
* February 21, 2023
* The purpose of this code is to prompt the user for an old master file and transaction file and make a new file combining the 2 using eof to check the file.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define a struct to hold account information
struct Account {
    int accountNum;
    double balance;
    string firstName;
    string lastName;
};

int main() {
    // Prompt the user for the input file names
    string masterFileName, transactionFileName, outputFileName;
    cout << "Enter the name of the master file: ";
    cin >> masterFileName;
    cout << "Enter the name of the transaction file: ";
    cin >> transactionFileName;
    cout << "Enter the name of the output file: ";
    cin >> outputFileName;

    // Attempt to open the input files
    ifstream masterFile(masterFileName);
    ifstream transactionFile(transactionFileName);
    if (!masterFile.is_open() || !transactionFile.is_open()) {
        cout << "Error: Could not open input files." << endl;
        return 1;
    }

    // Read in the master account information from the master file
    const int MAX_ACCOUNTS = 1000;
    Account masterAccounts[MAX_ACCOUNTS];
    int numAccounts = 0;
    int accountNum;
    double balance;
    string firstName;
    string lastName;
    while (!masterFile.eof()) { // Keep reading until the end of file
        // Read in one account's information
        masterFile >> accountNum >> firstName >> lastName >> balance;
        if (masterFile.fail()) { // Check for errors in reading
            break;
        }

        // Check if we have space for another account
        if (numAccounts >= MAX_ACCOUNTS) {
            cout << "Error: Maximum number of accounts exceeded." << endl;
            return 1;
        }

        // Create a new account and add it to the array of accounts
        Account account;
        account.accountNum = accountNum;
        account.balance = balance;
        account.firstName = firstName;
        account.lastName = lastName;
        masterAccounts[numAccounts] = account;
        numAccounts++;
    }

    // Create a new output file for the updated account information
    ofstream outputFile(outputFileName);

    // Process the transactions from the transaction file
    while (!transactionFile.eof()) { // Keep reading until the end of file
        // Read in one transaction's information
        transactionFile >> accountNum >> balance;
        if (transactionFile.fail()) { // Check for errors in reading
            break;
        }

        // Check if the account number exists in the master account information
        bool accountExists = false;
        for (int i = 0; i < numAccounts; i++) {
            if (masterAccounts[i].accountNum == accountNum) {
                // If the account exists, update its balance and write the updated information to the output file
                accountExists = true;
                masterAccounts[i].balance += balance;
                outputFile << accountNum << " " << masterAccounts[i].firstName << " " << masterAccounts[i].lastName << " " << masterAccounts[i].balance << endl;
                break;
            }
        }

        if (!accountExists) {
            // If the account number doesn't exist, output a warning message to the console
            cout << "Warning: Transaction for account number " << accountNum << " does not have a matching master account number." << endl;
        }
    }

    // Close the input and output files
    masterFile.close();
    transactionFile.close();
    outputFile.close();

    // Output the name of the output file to the user
    cout << "Output file \"" << outputFileName << "\" has been created." << endl;

    return 0;
}
