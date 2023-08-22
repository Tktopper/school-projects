/*
* Tanner Kleintop
* Exercise 5 Redo
* April 27, 2023
* The purpose of this code is to read a binary tree from an input file prompted by the user. Then it outputs it in post order traversal
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// This function traverses the binary tree in post order
// Input: string* tree - a pointer to the binary tree to be traversed
//        int size - the size of the binary tree
//        int index - the current index of the binary tree
void postorderTraversal(string* tree, int s, int index)
{
    // If the current index is greater than or equal to the size of the binary tree, then return
    if (index >= s)
    {
        return;
    }

    // Traverse the left subtree
    postorderTraversal(tree, s, 2 * index + 1);

    // Traverse the right subtree
    postorderTraversal(tree, s, 2 * index + 2);

    // If the current node is not empty, output its data
    if (tree[index] != "")
    {
        cout << tree[index] << " ";
    }
}

// This function inserts nodes into the binary tree
// Input: string data1 - the data of the parent node
//        string data2 - the data of the left child node
//        string data3 - the data of the right child node
//        string* tree - a pointer to the binary tree to be inserted into
//        int size - the size of the binary tree
//        int index - the current index of the binary tree
void insert(string data1, string data2, string data3, string* tree, int s, int index)
{
    // If the current index is greater than or equal to the size of the binary tree, then return
    if (index >= s)
    {
        return;
    }

    // If the current node matches the parent node, insert the left and right child nodes
    if (tree[index] == data1)
    {
        if (data2 != "null")
        {
            tree[2 * index + 1] = data2;
        }
        if (data3 != "null")
        {
            tree[2 * index + 2] = data3;
        }
    }
    // If the current node does not match the parent node, continue to traverse the binary tree
    else
    {
        insert(data1, data2, data3, tree, s, 2 * index + 1);
        insert(data1, data2, data3, tree, s, 2 * index + 2);
    }
}

int main()
{
    string fileName;
    cout << "Enter the name of an input file: ";
    cin >> fileName;

    // Open the input file.
    ifstream inputFile(fileName.c_str());

    // Check if the file was successfully opened.
    if (!inputFile) {
        cout << "Unable to open input file." << endl;
        return 0;
    }

    // Count the number of data items in the file.
    string data;
    int s = 0;
    while (inputFile >> data)
    {
        s++;
    }

    // Create an array to hold the tree nodes.
    string* tree = new string[s];
    for (int i = 0; i < s; i++)
    {
        tree[i] = "";
    }

    // Reset the input stream to the beginning of the file.
    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    // Read the dataand construct the binary tree.
    while (inputFile >> data) {
        string data1, data2, data3;
        data1 = data;
        inputFile >> data2 >> data3;
        // If the root node is empty, create the root node.
        if (tree[0] == "")
        {
            tree[0] = data1;
            tree[1] = data2;
            tree[2] = data3;
        }

        // Otherwise, call the insertHelper function to insert the node.
        else
        {
            insert(data1, data2, data3, tree, s, 0);
        }
    }

    // Perform a postorder traversal of the tree.
    postorderTraversal(tree, s, 0);
    cout << endl;

    // Free memory allocated for the tree.
    delete[] tree;

    // Exit the program.
    return 0;
}
