/*
* Tanner Kleintop
* February 14, 2023
* The Purpose of this code is to prompt the user for a word or phrase and have it output the word or phrase in Pig Latin
*/

#include <iostream>  // include iostream header
#include <string>    // include string header
#include <cstring>   // include cstring header
#define _CRT_SECURE_NO_WARNINGS // define macro to suppress warning messages
using namespace std;   // use std namespace

string translateToPigLatin(string word) {   // define function to translate a word to Pig Latin
    int wordLength = word.length();   // get length of the word
    string firstConsonants = "";   // initialize an empty string to hold the first consonants of the word
    string remaining = "";   // initialize an empty string to hold the remaining part of the word
    for (int i = 0; i < wordLength; i++) {   // iterate over the characters in the word
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' ||   // if the character is a vowel
            word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U') {
            remaining = word.substr(i);   // set the remaining part of the word to be the substring starting from the current index
            break;   // exit the loop
        }
        firstConsonants += word[i];   // add the current character to the string of first consonants
    }
    return remaining + "-" + firstConsonants + "ay";   // return the translated word in Pig Latin
}

int main() {   // main function
    char input[201];   // declare a character array to hold the input
    cout << "Enter an English word, phrase, or sentence: ";   // prompt the user to enter input
    cin.getline(input, 201);   // read input from the user

    char* tokenPtr;   // declare a pointer to a char
    char* context = NULL;   // initialize a pointer to a char to NULL
    tokenPtr = strtok_s(input, " ", &context);   // tokenize the input string using spaces as delimiters

    while (tokenPtr != NULL) {   // loop through each token
        cout << translateToPigLatin(tokenPtr) << " ";   // translate the current token to Pig Latin and output it
        tokenPtr = strtok_s(NULL, " ", &context);   // get the next token
    }
    cout << endl;   // output a newline character
    return 0;   // return 0 to indicate successful completion of the program
}
