/*
* Tanner Kleintop
* February 17, 2023
* The purpose this assignment is to provide a number in decimal and have it provide it in big endian and then provides it in little endian
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int INTSIZE = 4; // Size of integer in bytes
const int BYTESIZE = 8; // Size of byte in bits
const int NIBSIZE = 4; // Size of nibble in bits

union integer4 { // Define a union to represent the 4-byte integer
    unsigned int intrep; // Integer representation
    unsigned char byterep[INTSIZE]; // Byte representation
};

// Function to print a byte in hexadecimal
void prHex(unsigned char);

// Function to print a byte in binary
void prBin(unsigned char);

int main() {
    integer4 num; // Declare an instance of the integer union
    cout << "Enter an unsigned integer in base 10 => ";
    cin >> num.intrep; // Read the integer input from the user

    // Print the original number in hexadecimal
    cout << "In hex: " << endl;
    for (int i = INTSIZE - 1; i >= 0; i--) {
        prHex(num.byterep[i]); // Print each byte in hexadecimal
        cout << " "; // Add a space between bytes
    }
    cout << endl;

    // Print the original number in binary
    cout << "In binary: " << endl;
    for (int i = INTSIZE - 1; i >= 0; i--) {
        for (int j = BYTESIZE - 1; j >= 0; j--) {
            prBin((num.byterep[i] >> j) & 0x01); // Print each bit in binary
            if (j % NIBSIZE == 0) cout << " "; // Add a space between nibbles
        }
    }
    cout << endl;

    cout << endl;

    // Reverse the endianness of the integer
    integer4 revNum;
    for (int i = 0; i < INTSIZE; i++) {
        revNum.byterep[i] = num.byterep[INTSIZE - i - 1]; // Swap the bytes
    }

    // Print the reversed number in hexadecimal
    cout << "Reverse endian:" << endl;
    cout << "In hex: " << endl;
    for (int i = INTSIZE - 1; i >= 0; i--) {
        prHex(revNum.byterep[i]); // Print each byte in hexadecimal
        cout << " "; // Add a space between bytes
    }
    cout << endl;

    // Print the reversed number in binary
    cout << "In binary: " << endl;
    for (int i = INTSIZE - 1; i >= 0; i--) {
        for (int j = BYTESIZE - 1; j >= 0; j--) {
            prBin((revNum.byterep[i] >> j) & 0x01); // Print each bit in binary
            if (j % NIBSIZE == 0) cout << " "; // Add a space between nibbles
        }
    }
    cout << endl;

    return 0;
}

// Function to print a byte in hexadecimal with leading zeroes
void prHex(unsigned char num) {
    cout << setfill('0') << setw(2) << hex << (int)num;
}

// Function to print a byte in binary
void prBin(unsigned char num) {
    cout << (int)num;
}