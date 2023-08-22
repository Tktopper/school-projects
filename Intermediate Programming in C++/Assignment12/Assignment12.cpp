/*
* Tanner Kleintop
* April 11, 2023
* The purpose of this code is to read an input file that has a matrix n x n and performs the adjacency of that matrix from the first time to the 5th time
*/
#include <iostream>
#include <fstream>
#include <string>

const int MAX_SIZE = 5; // maximum size of the matrix

// Reads a square matrix from a text file with the given filename
//This function reads a square matrix from a text file with the given filename. 
//It takes in a 2D array of integers to store the matrix, a reference to an integer to store the size of the matrix, 
//and a string representing the filename. The function opens the file and reads the first line to get the size of the matrix.
//It then reads the subsequent lines to get the matrix values and stores them in the 2D array.
void readMatrixFromFile(int matrix[][MAX_SIZE], int& size, std::string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        std::getline(file, line);

        // Extract row and column sizes from the first line
        size = 0;
        for (char c : line) {
            if (c >= '0' && c <= '9') {
                size = size * 10 + (c - '0');
            }
            else {
                break;
            }
        }

        // Read the matrix values from the subsequent lines
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                file >> matrix[i][j];
            }
        }
        file.close();
    }
}


// Multiplies two square matrices of the given size
//This function multiplies two square matrices of the given size. 
// It takes in three 2D arrays of integers to represent the matrices and an integer representing the size of the matrices. 
//It performs the matrix multiplication by iterating through the rows and columns of the matrices and storing the result in a third 2D array.
void matrixMultiply(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int sum = 0;
            for (int k = 0; k < size; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

// Computes the powers of a square matrix of the given size up to the given exponent
//This function computes the powers of a square matrix of the given size up to the given exponent.
//It takes in a 2D array of integers representing the matrix, an integer representing the size of the matrix,
//a 3D array of integers to store the powers of the matrix, and an integer representing the maximum
void computeMatrixPowers(int M[][MAX_SIZE], int size, int P[][MAX_SIZE][MAX_SIZE], int maxExponent) {
    for (int p = 1; p <= maxExponent; p++) {
        if (p == 1) {
            // M^1 = M
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    P[p - 1][i][j] = M[i][j];
                }
            }
        }
        else {
            // M^p = M^(p-1) * M
            matrixMultiply(P[p - 2], M, P[p - 1], size);
        }
    }
}

// Prints a square matrix of the given size
/*This function prints a square matrix of the given size to a specified output stream. 
It takes in a 2D array representing the matrix, the size of the matrix, and an output stream object. 
It then iterates through each row and column of the matrix and prints each element to the output stream followed by a space character.
After printing all the elements in a row, it moves to the next line by printing a newline character.*/
void printMatrix(int A[][MAX_SIZE], int size, std::ostream& out) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            out << A[i][j] << " ";
        }
        out << std::endl;
    }
}
//main function of the code
int main() {
    int size; // size of the matrix
    int M[MAX_SIZE][MAX_SIZE]; // adjacency matrix
    int P[MAX_SIZE][MAX_SIZE][MAX_SIZE]; // powers of the matrix

    std::string filename; //string to store the filename
    std::cout << "Enter the filename of the adjacency matrix: "; //prompt the user for a filename
    std::cin >> filename; //store the filename

    readMatrixFromFile(M, size, filename); //recursivley call the function readMatrixFromFile to read the matrix, getting the row and column size along with the name of the file

    computeMatrixPowers(M, size, P, 5); //this recursively calls to perform each power of the matrix from 1 to 5

    std::string outFilename; //string to store the output file
    std::cout << "Enter the filename for the output: "; //prompt the user for a filname for the output file
    std::cin >> outFilename; //store the output filename
    std::ofstream outfile(outFilename); //open the output file
    
    //this for loop displays the power that the matrix was put to in the output file. an example look of this is M^1 where M is the matrix being put to the first power
    for (int p = 1; p <= 5; p++) { 
        outfile << "M^" << p << ":" << std::endl;
        printMatrix(P[p - 1], size, outfile);
        outfile << std::endl;
    }

    outfile.close(); //close the output file

    std::cout << "Output written to file: " << outFilename << std::endl; //tell the user what the name of the output file is.

    return 0; //end the code
}
