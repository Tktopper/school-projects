/*
* Tanner Kleintop
* February 24, 2023
* The purpose of this code is to prompt the user to input a string, the code will then take the code and read the string character by character
* converting it to lowecase and only using alphabetical letters (ignoring spaces, commas and other punctuation)
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int MAX_STACK_SIZE = 25;
char stack[MAX_STACK_SIZE];  // Global stack array to hold characters
int stackPtr = -1;           // Stack pointer

// Pushes a character onto the stack
void push(char c) {
    // Check if the stack is already full
    if (stackPtr == MAX_STACK_SIZE - 1) {
        cout << "Error: Stack overflow!" << endl;
        exit(1); // Exit the program immediately
    }
    // Increment the stack pointer and add the character to the stack
    stack[++stackPtr] = c;
}

// Pops a character from the stack
char pop() {
    // Check if the stack is already empty
    if (stackPtr == -1) {
        cout << "Error: Stack underflow!" << endl;
        return '\0';
    }
    // Decrement the stack pointer and return the top character
    return stack[stackPtr--];
}

// Main function
int main() {
    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString);

    // Push the entire string onto the stack, ignoring spaces and punctuation
    for (int i = 0; i < inputString.length(); i++) {
        if (isalpha(inputString[i])) {
            push(tolower(inputString[i]));  // Convert to lower case and push onto stack
        }
    }

    // Pop characters from the stack and compare with the original string
    bool isPalindrome = true;
    for (int i = 0; i < inputString.length(); i++) {
        if (isalpha(inputString[i])) {
            char c = pop();  // Pop character from stack
            if (tolower(inputString[i]) != c) {  // Compare with original string
                isPalindrome = false;
                break;
            }
        }
    }

    // Output the result only if there was no stack overflow
    if (stackPtr != MAX_STACK_SIZE - 1) {
        if (isPalindrome) {
            cout << inputString << " is a palindrome!" << endl; //output if the string is a palindrome
        }
        else {
            cout << inputString << " is not a palindrome." << endl; //output if the string is not a palindrome
        }
    }

    return 0;
}
