/*
Tanner Kleintop
February 10, 2023
The purpose of this code is to take a word given by the user and translate it to pig latin
*/

#include <iostream>
#include <cstring>

using namespace std;

// MAX_LENGTH defines the maximum length of the input string
#define MAX_LENGTH 201
// _CRT_SECURE_NO_WARNINGS disables warnings from the CRT library
#define _CRT_SECURE_NO_WARNINGS

// Function to check if a character is a vowel
bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

int main() {
    // Input string
    char line[MAX_LENGTH];
    // Pointer to the current token
    char* token;
    // Pointer to the context
    char* context;

    cout << "Enter an English word, phrase, or sentence: ";
    // Read the input string from the user
    cin.getline(line, MAX_LENGTH);

    // Tokenize the input string into separate words
    token = strtok_s(line, " ", &context);
    // Loop through each word
    while (token != NULL) {
        // Check if the first letter is a vowel
        if (isVowel(token[0])) {
            // If it is, print the word followed by "-ay "
            cout << token << "-ay ";
        }
        else {
            // If it's not a vowel, get the length of the word
            int length = strlen(token);
            // Print all letters except the first
            for (int i = 1; i < length; i++) {
                cout << token[i];
            }
            // Print the first letter followed by "-", then the rest of the word followed by "ay "
            cout << "-" << token[0] << "ay ";
        }
        // Move on to the next word
        token = strtok_s(NULL, " ", &context);
    }
    // End the line
    cout << endl;

    return 0;
}
