/*
* Tanner Kleintop, Andrew Nguyen, Krushil Amrutiya, Sean Gao, Shifra Suthakar
* April 29, 2023
* This is a C++ program that simulates a Turing Machine.
* The program reads a file with instructions for the Turing Machine.
* It then reads an input string and simulates the Turing Machine on it.
* The final output is the resulting tape after the Turing Machine is done.
*/
#include <iostream> // for input/output operations
#include <fstream> // for file handling operations
#include <iomanip> // for manipulating input/output formatting

using namespace std; // standard namespace to avoid naming conflicts

const char BLANK = 'B'; // constant for the blank symbol in a Turing machine
const char ZERO = '0'; // constant for the symbol '0' in a Turing machine
const char ONE = '1'; // constant for the symbol '1' in a Turing machine
const char STAR = '*'; // constant for the star symbol in a Turing machine
const char LEFT = 'L'; // constant for the direction 'Left' in a Turing machine
const char RIGHT = 'R'; // constant for the direction 'Right' in a Turing machine
const int MAXTAPE = 100; // constant for the maximum length of the tape in a Turing machine
const int MAXSTATES = 25; // constant for the maximum number of states in a Turing machine
const short STARTPOS = 40; // constant for the starting position of the tape head in a Turing machine.

// This is a struct that represents a transition between states in a Turing machine
// Each transition has a current state, a character to read from the tape, a next state, a character to write to the tape,
// and a direction to move the tape head (left, right or stay).
struct stateTrans {
	char state; // current state
	char readChar; // character to read
	char nextState; // next state
	char writeChar; // character to write
	char move; // direction to move
	struct stateTrans* next; // pointer to the next transition in the linked list
};

// This function checks if a given state already exists in a set of states
// It takes in the current state and an array of setStates to search through
// If the state is found in the set, the function returns true, otherwise it returns false.
bool duplicate(char state, char setStates[]) {
	for (int i = 0; i < MAXSTATES; i++) { // iterate through all possible states
		if (setStates[i] == state) return true; // if the current state is found in the set, return true
	}
	return false; // if the state is not found in the set, return false
}


// This function executes a Turing machine by taking in a pointer to the head of a linked list of state transitions, a pointer to the last transition,
// the current tape, the current state, the current position of the tape head, and a set of previously visited states.
// It loops through the linked list of state transitions until it finds a matching transition for the current state and tape symbol.
// If it finds a matching transition, it updates the tape symbol, the current state, and the position of the tape head based on the transition.
// If it does not find a matching transition, it exits the loop.
// Before moving to the next transition, it checks if the current state has already been visited.
// If it has been visited, it exits the loop and the Turing machine halts.
void execute(stateTrans* head, stateTrans* last, char turingMachine[], char& state, int& turingHead, char setStates[]) {
	while (head != NULL) { // loop through the linked list of state transitions
		if (head->state == state and head->readChar == turingMachine[turingHead]) { // check if the current state and tape symbol match the transition
			state = head->nextState; // update the current state
			turingMachine[turingHead] = head->writeChar; // update the tape symbol
			if (head->move == 'R') { // move the tape head right if the direction is 'R'
				turingHead++;
			}
			else { // move the tape head left if the direction is 'L'
				turingHead--;
			}
		}
		if (duplicate(state, setStates) == false) { // check if the current state has already been visited
			return; // if it has not been visited, continue to the next transition
		}
		head = head->next; // move to the next transition
	}
}

// This function inserts a new state transition into the linked list of state transitions.
// It takes in a string containing the transition information, a pointer to the last transition in the list,
// a pointer to the head of the list, an array of setStates to keep track of visited states, and an integer representing the current set state.
// If the last pointer is NULL, an error message is printed and the function returns.
void insert(string transitions, stateTrans*& lastPtr, stateTrans* head, char setStates[], int& setState) {
	if (lastPtr == NULL) { // check if the last pointer is NULL
		cout << "The previous node cannot be a null node!"; // if it is, print an error message
		cout << endl;
		return; // and return from the function
	}


// This function creates a new state transition node and inserts it into the linked list of state transitions.
// It takes in a string containing the transition information, a pointer to the last transition in the list,
// a pointer to the head of the list, an array of setStates to keep track of visited states, and an integer representing the current set state.
// It creates a new state transition node, sets its values to the corresponding transition information from the string,
// and checks if the current state has already been visited. If it has not been visited, it adds it to the setStates array
// and increments the setState counter.
// It then adds the new state transition node to the end of the linked list and updates the last pointer and the next pointer
// of the new state transition node.

// Declare a pointer to a new state transition node and allocate memory for it using the new keyword
	struct stateTrans* stateTrans;
	stateTrans = new struct stateTrans;
	// Set the state transition node's values to the corresponding transition information from the string
	stateTrans->state = transitions[0];
	stateTrans->readChar = transitions[1];
	stateTrans->nextState = transitions[2];
	stateTrans->writeChar = transitions[3];
	stateTrans->move = transitions[4];

	// Check if the current state has already been visited
	// If it has not been visited, add it to the setStates array
	if (duplicate(stateTrans->state, setStates) == false) {
		setStates[setState] = stateTrans->state;
		setState++; // increment the setState counter
	}
	// Add the new state transition node to the end of the linked list
	lastPtr->next = stateTrans;
	lastPtr = stateTrans;
	// Update the next pointer of the new node to point to the head of the list
	stateTrans->next = head;

}

int main() {
// Initialize variables for the Turing machine
int turingHead = STARTPOS; // Starting position of the Turing machine
char state = '0'; // Starting state of the Turing machine
char setStates[MAXSTATES] = { '0' }; // Array to keep track of visited states
int setState = 1; // Counter for number of visited states
char turingMachine[MAXTAPE] = { 'B' }; // Array representing the tape of the Turing machine, initialized with a blank symbol 'B'
string input; // Input string for the Turing machine
string transitions; // String to store each line of the input file
struct stateTrans* lastPtr = NULL; // Pointer to the last state transition node in the linked list
struct stateTrans* last = NULL; // Pointer to the last state transition node in the linked list (used in insert function)
struct stateTrans* head = NULL; // Pointer to the head of the state transition linked list

// Get the input file name from the user
string filename;
cout << "Please enter the name of your input file: ";
cin >> filename;

// Open the input file
ifstream is(filename);
if (is.fail()) {
	cout << "Cannot open provided input file with the name: " << filename << endl;
	return 1;
}

// initialize turingMachine array with 'B' for 100 cells
for (int i = 0; i < 100; i++) {
	turingMachine[i] = 'B';
}

// read the input string from the input file and store it in the turingMachine array starting from STARTPOS
is >> input;
for (int i = STARTPOS; i <= ((STARTPOS - 1) + input.length()); i++) {
	// if the end of the line is reached, break the loop
	if (input[i - STARTPOS] == '\n')
		break;
	// store the current character of the input string in the turingMachine array at the current position
	turingMachine[i] = input[i - STARTPOS];
}
// print a new line to separate the input from the output
cout << endl;

// Find the end of the input tape by searching for the first occurrence of 'B' (blank symbol)
int endOfTape = STARTPOS;
while (true) {
	if (turingMachine[endOfTape] == 'B')
		break;
	endOfTape++;
}

// Print information about the input tape
cout << "Input: " << endl;
cout << "Tape has a starting length of: " << STARTPOS << endl;
cout << "Initial length of input is: " << (endOfTape - STARTPOS) << endl;

// Loop through the tape array, printing out each element with a space in between
// If the current element is at the starting position, print it surrounded by vertical bars
for (int i = STARTPOS; i <= endOfTape + 1; i++) {
	if ((i - 1) == STARTPOS) {
		cout << "|" << turingMachine[i - 1] << "|" << " ";
	}
	else cout << turingMachine[i - 1] << " ";
}

// Read in the next set of transitions from the input stream
is >> transitions;

// Print a newline character at the end
cout << endl;

// Create a new state transition node
struct stateTrans* stateTrans;
stateTrans = new struct stateTrans;

// Set the state transition node's values based on the input transitions string
stateTrans->state = transitions[0];
stateTrans->readChar = transitions[1];
stateTrans->nextState = transitions[2];
stateTrans->writeChar = transitions[3];
stateTrans->move = transitions[4];

// Set the node's next pointer to point to itself, making it the only node in the linked list
stateTrans->next = stateTrans;

// Set the head and last pointers to point to the new node
head = stateTrans;
lastPtr = stateTrans;
// Check if the current state has already been encountered before
// If not, add the state to the list of encountered states
if (duplicate(stateTrans->state, setStates) == false) {
	setStates[setState] = stateTrans->state;
	setState++;
}

// Read in the next line of input containing a transition
is >> transitions;

// Loop over all the remaining transition lines in the input file
while (!is.fail()) {
	// Insert the transition into the linked list of state transitions
	insert(transitions, lastPtr, head, setStates, setState);
	// Update the last pointer to the current state transition node
	last = lastPtr;
	// Read in the next line of input containing a transition
	is >> transitions;
}

// Execute the Turing machine on the input tape
execute(head, last, turingMachine, state, turingHead, setStates);

// Find the starting position of the input tape
int startOfTape;
for (int i = 0; i < 100; i++) {
startOfTape = i;
if (turingMachine[i] != 'B') break;
}
endOfTape = startOfTape; // Set the endOfTape variable to the starting position of the tape
while (true) { // Execute loop indefinitely
	if (turingMachine[endOfTape] == 'B') break; // Break the loop if 'B' is found at the end of the tape
	endOfTape++; // Increment the endOfTape to move along the tape
}
cout << endl;
cout << "Output:" << endl;
cout << "Execution halts in state: " << state << endl; // Print the halting state of the Turing machine
cout << "Tape starting position is: " << startOfTape << endl; // Print the starting position of the tape
cout << "Length of output tape is: " << (endOfTape - startOfTape) << endl; // Print the length of the tape
for (int i = (startOfTape - 1); i <= endOfTape; i++) { // Iterate through the tape from startOfTape to endOfTape
	if (i == turingHead) { // If the current index is the current head position of the tape, surround the current character with '|'
		cout << "|" << turingMachine[i] << "|" << " ";
	}
	else cout << turingMachine[i] << " "; // Otherwise, print the current character
}

	cout << endl; //add a newline
	return 0; //end the code succesfully with a return of 0
}