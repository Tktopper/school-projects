/*
* Tanner Kleintop
* February 28, 2023
* The purpose of this code is to provide a list of integers, the code will remove the duplicates and order them head to tail.
*/

#include <iostream>
using namespace std;

// Define a struct for a linked list node
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list
};

// Define a function to create a new node for the element
Node* createNode(int data) {
    Node* newNode = new Node;   // Allocate memory for a new node
    newNode->data = data;       // Store the data in the new node
    newNode->next = NULL;       // Set the next pointer to NULL initially
    return newNode;             // Return the new node
}

// Define a function to add an element to the end of the linked list
void enqueue(Node** head, int data) {
    // Check for duplicates
    Node* curr = *head;         // Start at the head of the list
    while (curr != NULL) {      // Traverse the list until the end is reached
        if (curr->data == data) {   // If a duplicate is found
            return;             // Do not add the element and return from the function
        }
        curr = curr->next;      // Move to the next node in the list
    }

    // Create a new node for the element
    Node* newNode = createNode(data);

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
    }
    // Otherwise, add the new node to the end of the list
    else {
        curr = *head;           // Start at the head of the list again
        while (curr->next != NULL) {    // Traverse the list until the last node is reached
            curr = curr->next;  // Move to the next node in the list
        }
        curr->next = newNode;   // Add the new node to the end of the list
    }
}

// Define a function to print the elements of the linked list from head to tail
void printQueue(Node* head) {
    Node* curr = head;          // Start at the head of the list
    while (curr != NULL) {      // Traverse the list until the end is reached
        cout << curr->data << " ";  // Print the data in the current node
        curr = curr->next;      // Move to the next node in the list
    }
    cout << endl;               // Print a newline character after the list is printed
}

int main() {
    Node* head = NULL;          // Pointer to the head of the list
    int data;

    // Prompt the user to enter positive integers until they enter 0 or a negative integer
    cout << "Enter a positive integer (0 or negative integer to quit): ";
    do {
        cin >> data;            // Read an integer from the user
        if (data > 0) {
            enqueue(&head, data);   // Add the element to the end of the list
        }
    } while (data > 0);         // Continue reading integers until the user enters a non-positive value

    // Print the resulting linked list from head to tail
    cout << "The resulting linked list is: ";
    printQueue(head);

    return 0;                   // Exit the program with a return value of 0
}


