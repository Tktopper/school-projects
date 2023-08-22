/*
* Tanner Kleintop
* April 11, 2023
* The purpose this code is to read an input file that acts like a tree. Reading the input and outputting the message in the file.
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// A node of the binary tree
struct Node {
    string value;
    Node* left;
    Node* right;
};

// Function to add a node to the binary tree recursively
void addNode(Node*& node, ifstream& input) {
    string left;
    string middle;
    string right;

    // Read the values of the node and its children from the input stream
    input >> left >> middle >> right;

    // Create a new node with the given value
    node = new Node{ left, nullptr, nullptr };

    // If the left child is not null, add it recursively
    if (middle != "null") {
        addNode(node->left, input);
    }

    // If the right child is not null, add it recursively
    if (right != "null") {
        addNode(node->right, input);
    }
}

// Function to print the postorder traversal of the binary tree
void postorder(Node* node) {
    if (node == nullptr) {
        return; // Base case: If the node is null, return
    }

    // Traverse the left subtree
    postorder(node->left);

    // Traverse the right subtree
    postorder(node->right);

    // Print the value of the node
    cout << node->value << " ";
}

// Main function
int main() {
    string inFilename;

    // Prompt the user to enter the name of the input file
    cout << "Enter the name of the input file: ";
    cin >> inFilename;

    // Open the input file
    ifstream input(inFilename);

    // If the input file cannot be opened, print an error message and return with error code
    if (input.fail()) {
        cout << "Cannot open " << inFilename << endl;
        return 1;
    }

    Node* root = nullptr;

    // Add nodes to the binary tree recursively
    addNode(root, input);

    // Close the input file
    input.close();

    // Print the postorder traversal of the binary tree
    postorder(root);

    // Print a newline character to separate the output from the prompt in the terminal
    cout << endl;

    return 0;
}
