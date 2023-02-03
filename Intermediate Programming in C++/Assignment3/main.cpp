/*
Tanner Kleintop
January 27, 2023
The purpose of this code is display the ascii table in hex, oct, and the character
along with the decimal.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main() {
    ofstream outfile("ASCII_table.txt"); //Opens a file with this name
    outfile << setw(12) << "Decimal" << setw(12) << "Octal" << setw(12) << "Hexadecimal" << setw(12) << "Character" << endl; //adds this file to the header
        for (int i = 33; i <= 126; i++) { //increment from 33 to 126
            outfile << setw(12) << dec << i << setw(12) << showbase << oct 
                << i << setw(12) << hex << i << setw(12) << (char)i << endl; //outputs in the file in this order
        }
    outfile.close(); //closes the file
    cout << " A file named ASCII_table.txt was created containing the data." <<
        endl; //informs the user of a filename
    cout << endl; //adds an extra space after informing the user of the filename.
    return 0; //ends the code
}
