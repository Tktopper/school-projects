/*
* Tanner Kleintop
* April 18, 2023
* The purpose of this code is to provide a list of strings and output them in a tree sorted format in a table.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Tree node structure
struct TreeNode {
    string data; // The value or data stored in this node.
    TreeNode* left; // Pointer to the left child of this node.
    TreeNode* right; // Pointer to the right child of this node.
    int height; // The height of this node in the tree.
    int balance; // The balance factor of this node.
    int multiplicity; // The number of times this value appears in the tree (if duplicates are allowed).
};

// Function to create a new node
TreeNode* newNode(string data) {
    TreeNode* node = new TreeNode(); // Dynamically allocate memory for a new node.
    node->data = data; // Set the value or data of the node to the input data.
    node->left = nullptr; // Set the left child pointer to NULL (no left child).
    node->right = nullptr; // Set the right child pointer to NULL (no right child).
    node->height = 1; // Set the height of the node to 1 (new leaf node).
    node->balance = 0; // Set the balance factor of the node to 0 (new leaf node).
    node->multiplicity = 0; // Set the multiplicity of the node to 0 (new unique node).
    return node; // Return the new node.
}

// Function to get the height of a node
int getHeight(TreeNode* node) {
    if (node == nullptr) { // Check if the node is a nullptr (no node exists)
        return 0; // Return 0 since it has no height.
    }
    return node->height; // Otherwise, return the height of the node.
}

// Function to get the balance factor of a node
int getBalance(TreeNode* node) {
    if (node == nullptr) { // Check if the node is a nullptr (no node exists)
        return 0; // Return 0 since it has no balance.
    }
    return getHeight(node->left) - getHeight(node->right); // Calculate the balance factor of the node.
}

// Function to perform a right rotation on a node
TreeNode* rotateRight(TreeNode* node) {
    // Get the left child of the input node and its right child
    TreeNode* leftChild = node->left;
    TreeNode* leftRightChild = leftChild->right;
    // Perform the rotation
    leftChild->right = node;
    node->left = leftRightChild;

    // Update the heights of the nodes
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    leftChild->height = max(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;

    // Update the balances of the nodes
    node->balance = getBalance(node);
    leftChild->balance = getBalance(leftChild);

    // Return the new root of the subtree
    return leftChild;
}

// Function to perform a left rotation on a node
TreeNode* rotateLeft(TreeNode* node) {
    // Get the right child of the input node and its left child
    TreeNode* rightChild = node->right;
    TreeNode* rightLeftChild = rightChild->left;
    // Perform the rotation
    rightChild->left = node;
    node->right = rightLeftChild;

    // Update the heights of the nodes
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    rightChild->height = max(getHeight(rightChild->left), getHeight(rightChild->right)) + 1;

    // Update the balances of the nodes
    node->balance = getBalance(node);
    rightChild->balance = getBalance(rightChild);

    // Return the new root of the subtree
    return rightChild;
}

// Function to balance a node
TreeNode* balance(TreeNode* node) {
    // If the input node is null, return null
    if (node == nullptr) {
        return nullptr;
    }
    // Update the height and balance of the node
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    node->balance = getBalance(node);

    // If the node is unbalanced, perform rotations to balance it
    if (node->balance > 1) {
        if (getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    if (node->balance < -1) {
        if (getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }

    // If the node is already balanced, return it
    return node;
}


// Function to insert a node into a tree
TreeNode* insert(TreeNode* root, string data) {
    // If the root is null, create a new node with the given data
    if (root == nullptr) {
        return newNode(data);
    }
    // If the data is less than the root's data, insert into the left subtree
    if (data < root->data) {
        root->left = insert(root->left, data);
    }

    // If the data is greater than the root's data, insert into the right subtree
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // If the data is equal to the root's data, increment its multiplicity
    else {
        root->multiplicity++;
    }

    // Balance the tree and return the new root
    return balance(root);
}

//This is a function that performs an inorder traversal of a binary search tree and prints out the nodes in a tabular format.
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        // Traverse the left subtree
        inorderTraversal(root->left);

        // Print the current node in tabular format
        cout << root->data << "\t";
        cout << (root->left ? root->left->data : "null") << "\t";
        cout << (root->right ? root->right->data : "null") << "\t";
        cout << root->height << "\t";
        cout << root->balance << "\t";
        cout << root->multiplicity << "\n";

        // Traverse the right subtree
        inorderTraversal(root->right);
    }
}
int main() {
    // Prompt the user to enter the name of the input file
    string fileName;
    cout << "Enter the name of the input file: ";
    cin >> fileName;
    // Open the input file
    ifstream inFile(fileName);

    // If the file cannot be opened, print an error message and exit the program
    if (!inFile) {
        cout << "Unable to open file " << fileName << "\n";
        return 1;
    }

    // Initialize the root of the tree to null
    TreeNode* root = nullptr;

    // Read the strings from the input file and insert them into the tree
    string data;
    while (inFile >> data) {
        root = insert(root, data);
    }

    // Print the contents of the tree in inorder traversal in tabular format
    cout << "NODE\tLEFT\tRIGHT\tHEIGHT\tBALANCE\tMULTIPLICITY\n";
    inorderTraversal(root);

    // Close the input file and exit the program
    inFile.close();
    return 0;
}