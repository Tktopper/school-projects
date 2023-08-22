/*
* Tanner Kleintop
* March 28, 2023
* The purpose of this code is to provide 2 input files and the name of an output file. the inputs will be read and matrix operations will be performed on them where applicable.
*/

//libraries used for the code below.
#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX = 6; //set the max size of the matrices to a 6 by 6.
using namespace std;

//prototype functions that will call the functions commented below.
void additionMatrix(double A[][MAX], double B[][MAX], double C[][MAX], int rows, int cols);
void subtractionMatrix(double A[][MAX], double B[][MAX], double C[][MAX], int rows, int cols);
void multiplicationMatrix(double A[][MAX], double B[][MAX], double C[][MAX], int rows1, int cols1, int cols2);
void readMatrix(double matrix[][MAX], int& rows, int& cols, ifstream& in);
void printMatrix(double matrix[][MAX], int rows, int cols, ofstream& out); 

//function that will read the matrices from the input files provided by the user
void readMatrix(double matrix[][MAX], int& rows, int& cols, ifstream& in) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            in >> matrix[i][j]; //reads the elements at position (i,j) of the matrix from the file provided
        }
    }
}
//function that will print the output to the file provided by the user
void printMatrix(double matrix[][MAX], int rows, int cols, ofstream& out) {
    out << fixed << setprecision(3); //set the output to a fixed format with a decimal precsion set to 3 digits after the decimal place
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            out << setw(10) << matrix[i][j]; //with a width of 10 characters, this will print the element of position (i,j) of the matrix
        }
        out << endl; //add a new line after the matrix
    }
    out << endl; //add another new line.
}
//function that will perform addition if applicable on the two matrices.
void additionMatrix(double A[][MAX], double B[][MAX], double C[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] + B[i][j]; //add the two matrices together with respect to position (i,j)
        }
    }
}
//function that will perform subraction if applicable.
void subtractionMatrix(double A[][MAX], double B[][MAX], double C[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = A[i][j] - B[i][j]; //subtract the two matrices with respect to position (i,j)
        }
    }
}
//multiply the matrices together if applicable.
void multiplicationMatrix(double A[][MAX], double B[][MAX], double C[][MAX], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            C[i][j] = 0; //initalize the matrix C to zero at position (i,j)
            for (int k = 0; k < cols1; k++) {
                C[i][j] += A[i][k] * B[k][j]; //multiply A and B together to make matrix C with respect to (i,j)
            }
        }
    }
}

int main() {
    string inputfile1; //string to store one of the input files.
    string inputfile2; //string to store the second input file.
    string outFile; //string that will contain the output file

    cout << "Enter the name of the first input file: "; //asking the user for the name of the first file in the console
    cin >> inputfile1; //store the file name
    ifstream in1(inputfile1); //open the file
    if (in1.fail()) { //if the file cannot be opened output this message
        cout << "Cannot open " << inputfile1 << endl;
        return 1;//end the code with a 1.
    }

    cout << "Enter the name of the second input file: "; //open the second file
    cin >> inputfile2; //store the file name
    ifstream in2(inputfile2); //open the file
    if (in2.fail()) { //if the file cannot be opened output this message.
        cout << "Cannot open " << inputfile2 << endl;
        return 1; //end with a 1.
    }

    cout << "Enter the name of the output file: "; //provide the name of an output file that will store the matrix operations.
    cin >> outFile;//store the file name.
    ofstream out(outFile);//open the input file.

    int rows1; //stores the rows for the first matrix
    int cols1; //stores the columns for the first matrix
    in1 >> rows1 >> cols1;
    double A[MAX][MAX]; //stores the rows and colums sizes with a max size of 6 by 6
    readMatrix(A, rows1, cols1, in1); //read the dimension of the matrix, columns, and rows.

    out << "The First matrix you used was from the file: " << inputfile1 << endl; //in the output file give the user the name of the first file used
    out << "The Second matrix you used was from the file: " << inputfile2 << endl; //in the output file give the user the name of the second file used
    out << endl; //end line
    out << endl; //end line

    out << "Matrix A =" << endl; //outputs the value of the first matrix from the first file
    printMatrix(A, rows1, cols1, out); //print out the matrix

    in1.close();

    int rows2; //stores the rows for the second matrix
    int cols2; //stores the colums for the second matrix
    in2 >> rows2 >> cols2;
    double B[MAX][MAX]; //value to store the size of the matrix with the max size being a 6 by 6
    readMatrix(B, rows2, cols2, in2); //reads the information of the matrix

    out << "Matrix B =" << endl; //ouput matrix B from the given input file
    printMatrix(B, rows2, cols2, out); //print out the matrix

    in2.close();

    double C[MAX][MAX]; //array that stores the C matrix with the max size being a 6 by 6
    if (rows1 == rows2 && cols1 == cols2) { //if the rows and colums are both the same 
        additionMatrix(A, B, C, rows1, cols1); //output the matrix addition
        out << "A + B =" << endl;
        printMatrix(C, rows1, cols1, out); //print the matrix

        subtractionMatrix(A, B, C, rows1, cols1); //subtraction of matrices A and B with the result being C
        out << "A - B =" << endl;
        printMatrix(C, rows1, cols1, out); //print the matrix
    }
    else {
        out << "Matrix A and B cannot have addition and subtraction performed on them." << endl; //if the conditions above arent applicable, output this message
        out << endl; //end line
    }

    if (cols1 == rows2) { //in the colums from the first matrix equals the columns from the second matrix, perform matrix multiplication on the two
        multiplicationMatrix(A, B, C, rows1, cols1, cols2); //call the function of the matrix multiplication
        out << "A * B =" << endl; //ouput this in the file 
        printMatrix(C, rows1, cols2, out); //print the multiplied matrix
    }
    else {
        out << "Matrix A and B cannot have matrix multiplication performed on them." << endl; //if multiplication cannot be done, output this line
    }

    out.close(); //close the output file

    cout << "The output can be found in the file named: " << outFile << endl; //provide the user with the name of the output file.

    return 0; //end the code
}
