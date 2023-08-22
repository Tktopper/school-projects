/*
* Tanner Kleintop
* March 14, 2023
* The purpose of this code is to prompt the user for a string and read the string, telling the user if it is valid or invalid.
* If valid it identifies each part, if invalid it provides the user where the invalid string begins.
*/

// Importing necessary libraries
#include <iostream> // for input/output operations
#include <string> // for string manipulation functions

using namespace std; // namespace for standard library

// Function to return the new state based on the input character and the current state
string transition_rule(string current_state, char input_char);

// Main function
int main() {
    string input_str; // declare variable to store user input
    cout << "Enter a string (100 characters max): ";
    cin >> input_str; // read in user input string
    string current_state = "start"; // initialize current state to "start"
    string current_token = ""; // initialize current token to empty string
    int invalid_start_pos = -1; // initialize invalid start position to -1 (i.e. no invalid substring)
    int invalid_length = 0; // initialize invalid length to 0 (i.e. no invalid substring)
    for (int i = 0; i < input_str.length(); i++) { // loop over each character in the input string
        char input_char = input_str[i]; // get current input character
        if (current_state == "start") { // if current state is "start"
            if (isalpha(input_char) || input_char == '_') { // if input character is a letter or underscore
                current_state = "identifier"; // transition to "identifier" state
            }
            else if (isdigit(input_char)) { // if input character is a digit
                current_state = "integer"; // transition to "integer" state
            }
            else if (input_char == ',' || input_char == '.') { // if input character is a comma or period
                current_state = "start"; // stay in "start" state
            }
            else { // if input character is invalid
                current_state = "invalid"; // transition to "invalid" state
                invalid_start_pos = i; // mark start position of invalid substring
                invalid_length = 1; // mark length of invalid substring as 1
            }
        }
        else if (current_state == "identifier") { // if current state is "identifier"
            if (isalnum(input_char) || input_char == '_') { // if input character is a letter, digit or underscore
                current_state = "identifier"; // stay in "identifier" state
            }
            else if (input_char == ',' || input_char == '.') { // if input character is a comma or period
                current_state = "start"; // transition to "start" state
            }
            else { // if input character is invalid
                current_state = "invalid"; // transition to "invalid" state
                invalid_start_pos = i; // mark start position of invalid substring
                invalid_length = 1; // mark length of invalid substring as 1
            }
        }
        else if (current_state == "integer") { // if current state is "integer"
            if (isdigit(input_char)) { // if input character is a digit
                current_state = "integer"; // stay in "integer" state
            }
            else if (input_char == ',' || input_char == '.') { // if input character is a comma or period
                current_state = "start"; // transition to "start" state
            }
            else { // if input character is invalid
                current_state = "invalid"; // transition to "invalid" state
                invalid_start_pos = i; // mark start position of invalid substring
                invalid_length = 1; // mark length of invalid substring as 1
            }
        }
        else { // current_state == "invalid"
            invalid_length++;
        }
        // If the current state is "start", it means that a token has just ended
        if (current_state == "start") {
            // Check if a token was being constructed
            if (current_token != "") {
                // If the first character of the token is a digit, it is a positive integer
                if (isdigit(current_token[0])) {
                    cout << current_token << "\tpositive integer" << endl;
                }
                // If the first character of the token is a letter, it is an identifier
                else if (isalpha(current_token[0])) {
                    cout << current_token << "\tidentifier" << endl;
                }
            }
            // Reset the current token
            current_token = "";
        }
        // If the current state is not "start", the current character is part of the current token
        else {
            current_token += input_char;
        }
    }
    // If an invalid string was found, print an error message and return 0
    if (invalid_start_pos != -1) {
        string invalid_str = input_str.substr(invalid_start_pos, invalid_length);
        cout << "Invalid string: " << invalid_str << endl;
        return 0;
    }
    // Check if there is a token being constructed at the end of the input string
    if (current_token != "") {
        // If the first character of the token is a digit, it is a positive integer
        if (isdigit(current_token[0])) {
            cout << current_token << "\tpositive integer" << endl;
        }
        // If the first character of the token is a letter, it is an identifier
        else if (isalpha(current_token[0])) {
            cout << current_token << "\tidentifier" << endl;
        }
    }
    // Return 0 to indicate successful completion of the program
    return 0;
}