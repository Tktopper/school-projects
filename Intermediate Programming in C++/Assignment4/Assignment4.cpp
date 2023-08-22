/*
Tanner Kleintop
February 3, 2023
The purpose of this code is to take 7 digits and turn them into all lettered combinations.
*/

//libraries for the code
#include <iostream>
#include <fstream>

const int ROWSIZE = 10; //sets the size of the row 
const int COLSIZE = 5; //sets the column size
const int NUMSIZE = 8; //sets the number size of 8, 7 numbers and 1 null bit

void combine(char* input, char letters[ROWSIZE][COLSIZE], char* build, int index, std::ofstream& out) {
    //function to go through all possible combinations of the given digits
    if (index == 7) { //Base case for the characters being processed
        build[7] = '\0'; //add null character
        out << build << std::endl; //puts the combination in an output file
        return;
    }

    int indexNum = (int)input[index] - (int)'0'; // Calculate the index of the letters array based on the input digit
    //loops through all letters in the current column of the array
    for (int i = 0; letters[indexNum][i] != '\0'; i++) {
        build[index] = letters[indexNum][i]; //update the character being evaluated in the index array
        combine(input, letters, build, index + 1, out); //recursively call the function to build the next character
    }
}

int main() { 

    char array[NUMSIZE]; //array to store the 7 different digits
    char letters[ROWSIZE][COLSIZE] = { { '0', '\0', '\0', '\0', '\0' },
                                        { '1', '\0', '\0', '\0', '\0' },
                                        { 'A', 'B', 'C', '\0', '\0' },
                                        { 'D', 'E', 'F', '\0', '\0' },
                                        { 'G', 'H', 'I', '\0', '\0' },
                                        { 'J', 'K', 'L', '\0', '\0' },
                                        { 'M', 'N', 'O', '\0', '\0' },
                                        { 'P', 'Q', 'R', 'S', '\0' },
                                        { 'T', 'U', 'V', '\0', '\0' },
                                        { 'W', 'X', 'Y', 'Z', '\0' } };
    char buildArr[ROWSIZE]; //array to store the built combinations

    std::cout << "Enter a 7-digit number: "; //prompt the user for an input
    std::cin >> array; //stores the user input

    std::ofstream out("combinations.txt"); //Open the output file with this name
    combine(array, letters, buildArr, 0, out); //call the recursive function to generate the functions
    out.close(); //closes the output file

    std::cout << "The combinations have been saved in the file 'combinations.txt'" << std::endl; //informs the user of the output file
    return 0;
}
