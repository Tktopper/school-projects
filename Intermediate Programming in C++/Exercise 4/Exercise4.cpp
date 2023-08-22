/*
* Tanner Kleintop
* March 1, 2023
* The purpose of this code it to prompt the user for a priority queue number then a name for that priorty queue. 
*/

#include <iostream>
#include <string>
using namespace std;

// Define a struct to represent each job in the priority queue
struct pqEntry {
    string job;
    int priority;
    struct pqEntry* nextPtr;
};

// Define a function to insert a job into the queue based on its priority
void insertJob(pqEntry*& head, int priority, string job) {
    // Allocate memory for the new job entry
    pqEntry* newJob = new pqEntry;
    // Fill in the job details
    newJob->job = job;
    newJob->priority = priority;
    newJob->nextPtr = NULL;

    // If the queue is empty or the new job has the highest priority, insert it at the head of the queue
    if (!head || priority < head->priority) {
        newJob->nextPtr = head;
        head = newJob;
    }
    else {
        // Otherwise, search for the correct position to insert the new job
        pqEntry* temp = head;
        while (temp->nextPtr && priority >= temp->nextPtr->priority) {
            temp = temp->nextPtr;
        }
        // Insert the new job after the job with the next lowest priority
        newJob->nextPtr = temp->nextPtr;
        temp->nextPtr = newJob;
    }
}

// Define a function to print out the entire queue from head to tail
void printQueue(pqEntry* head) {
    cout << "Queue:\n";
    while (head) {
        cout << "Priority " << head->priority << ": " << head->job << "\n";
        head = head->nextPtr;
    }
}

// Main function to prompt the user for job priorities and names, and build the priority queue
int main() {
    // Initialize the head of the queue to NULL
    pqEntry* head = NULL;
    // Prompt the user for jobs until a negative priority is entered
    int priority;
    string job;
    while (true) {
        cout << "Enter a priority (0-10) or a negative number to quit: ";
        cin >> priority;
        if (priority < 0) {
            break;
        }
        cout << "Enter a job name: ";
        cin >> job;
        // Insert the new job into the queue based on its priority
        insertJob(head, priority, job);
    }
    // Print out the resulting queue from head to tail
    printQueue(head);
    return 0;
}
