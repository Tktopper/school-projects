/*
* Tanner Kleintop
* March 14, 2023
* The following code defines a doubly linked list, which takes input from a file and sorts the input values in ascending order.
* The sorted list is then printed to the console and optionally to an output file.
* The user can also choose to view every step of the sorting process.
*/

#include <iostream> // header file for standard input/output operations
#include <fstream> // header file for file input/output operations
#include <string> // header file for string manipulation

using namespace std; //using the standard namespace

// struct definition for a doubly linked list node
struct listMemb {
    int value;
    struct listMemb* leftPtr;
    struct listMemb* rightPtr;
};

// function to print the doubly linked list to an output stream
void printList(listMemb* h, ostream& outStream) {
    listMemb* p = h; // pointer to the head of the list
    int count = 0; // variable to count the number of nodes printed
    while (p != nullptr) { // loop through the list until the end is reached
        outStream << p->value << " "; // print the current node's value to the output stream
        p = p->rightPtr; // move to the next node in the list
        count++; // increment the node count
        if (count % 10 == 0) { // if the node count is a multiple of 10, start a new line
            outStream << endl;
        }
    }
    outStream << endl; // print a final newline character
}

// function to print the doubly linked list to a file
void printListToFile(listMemb* h, ofstream& outFile) {
    printList(h, outFile); // call the printList function with the output file stream
}

// function to insert a new node with value x into the doubly linked list
void insertIntoList(listMemb*& h, listMemb*& t, listMemb*& m, int x, int& c) {
    listMemb* p = new listMemb; // create a new node with value x
    p->value = x;
    p->leftPtr = nullptr;
    p->rightPtr = nullptr;
    if (h == nullptr) { // if the list is empty, set the new node as the head, tail, and midpoint
        h = t = m = p;
        c = 1; // set the node count to 1
    }
    else if (x < h->value) { // if x is less than the head node's value, insert the new node at the beginning of the list
        p->rightPtr = h;
        h->leftPtr = p;
        h = p; // set the new node as the head
        c++; // increment the node count
        if (c % 2 == 0) { // if the node count is even, move the midpoint to the left
            m = m->leftPtr;
        }
    }
    else { // if x is greater than or equal to the head node's value, insert the new node in the middle or at the end of the list
        listMemb* q = h;
        while (q->value <= x && q->rightPtr != nullptr) { // traverse the list until a node with a greater value is found or the end is reached
            q = q->rightPtr;
        }
        if (q->value <= x) { // if x is greater than or equal to the tail node's value, insert the new node at the end of the list
            p->leftPtr = q;
            q->rightPtr = p;
            t = p;
        }
        else { //else state if the previous statement is not satisfied
            p->leftPtr = q->leftPtr;
            q->leftPtr->rightPtr = p;
            p->rightPtr = q;
            q->leftPtr = p;
        }
        c++;
        if (c % 2 == 1) { //if c mod 2 equals 1, make the mid pointer move to the right pointer
            m = m->rightPtr;
        }
    }
}

void bisort(listMemb*& h, listMemb*& t, listMemb*& m, int& c, int verbose, ifstream& inFile, ofstream& outFile) {
    int x;
    while (inFile >> x) { //while the file is being read
        if (verbose) { //if verbose is true then the outfile displays each step betlow
            outFile << "Inserting " << x << endl;
        }
        insertIntoList(h, t, m, x, c);
        if (verbose) {
            printListToFile(h, outFile); //prints the list to the file if verbose is true
        }
    }
    inFile.close();
}

int main() {
    listMemb* h = nullptr; // initialize the head of the doubly linked list to null
    listMemb* t = nullptr; // initialize the tail of the doubly linked list to null
    listMemb* m = nullptr; // initialize the midpoint of the doubly linked list to null
    int c = 0; // initialize the node count to 0
    int verbose = 0; // initialize the verbose flag to false
    string inputFileName;
    cout << "Enter the input file name: "; //prompt user for an input
    cin >> inputFileName; // read the input file name from the file provided
    ifstream inFile(inputFileName);
    if (!inFile) { //if the file being called is not present
        cout << "Error opening input file." << endl; //output error
        return 1; //stop
    }
    string outputFileName;
    cout << "Enter the output file name: "; //prompt user for an input
    cin >> outputFileName; //read input
    ofstream outFile(outputFileName);
    if (!outFile) {
        cout << "Error opening output file." << endl; //output if there is an error opening the file
        return 1;
    }
    cout << "Do you want to view every step of the sorting process? (0 = no, 1 = yes): "; //asking the user if the would like the verbose option
    cin >> verbose; //store the user input

    bisort(h, t, m, c, verbose, inFile, outFile);
     
    cout << "The sorted list is: " << endl; //output the sorted list in the console
    printList(h,cout); //printing the sorted list

    outFile.close();
    if (verbose) {
        cout << "The verbose output has been written to " << outputFileName << "." << endl; //if the verbose option is true this will be prompting the user of a filename for the verbose option.
    }

    return 0; //stop
}