//
//Tanner Kleintop
//11/30/21
//The purpose of this code is to sort an input file given by the user with a number of integers up to 100, outputting the sorted array
//
#include <iostream>
#include <fstream>
using namespace std;
int selectionSort(int arr[], int size) //function for the selection sort, taking the size and array, with the numbrt of swapped needed to sort it
{
    int swaps = 0; //start swaps at 0
    int min_index; //declares the minimum index
    for(int t=0; t<size-1; t++) //loop through the values given
    {
        min_index = t; //declare the the min_index is t
             //loop through t=a+1
              for(int a=t+1; a<size; a++)
        {
            if (arr[a] < arr[min_index]) //if statement for if the value is less than the value of the min_index, updating the minimum index with a
                min_index = a;
        }
        int temp = arr[t]; 
        arr[t] = arr[min_index];
        arr[min_index] = temp;
        swaps++;
    }
    return swaps; //return the swapped values
}
int main()
{
    // make an ifstream and ofstream variable for the file
    ifstream infile;
    ofstream outfile;
    string filename; //string name to store file as a name
    cout << "Enter name of the input file with up to 100 integers: "; //asking for user input
    cin >> filename; //store user input
    infile.open(filename); //open the file provided by the users input
    if (!infile.is_open()) //if statement for if the file provided cannot be found
    {
        cout << "Could not open the input file entered." << endl;
        return -1;
    }
    int arr[100]; //making the array a size up to 100, not having more than 100 integers
    int size = 0; //start size with 0
    int x;
    while(infile >> x) //read the value from given file and add it into the array, increasing the swap size
    {
        arr[size++] = x;
    }
    int swaps = selectionSort(arr, size);//using the selection sort function from above and storing the swapped values
    outfile.open("selectionsortoutput.txt"); //opening the output file
    int count = 0; //start count with 0, adding up to 10 numbers per line
    for(int t=0; t<size; t++)//for loop for the array
    {
        x = arr[t]; //printing the values into the output
        outfile << x;
        count++;
        if (count == 10) //if statement for storing each number in the output file, with 10 numbers or less per line.
        {
            outfile << endl;
            count = 0;
        } 
        else
            outfile << " "; //used to put a space in between each integer
    }
    cout << "The name of the output file is: selectionsortoutput.txt" << endl; //output the name of the file into code terminal
    cout << "The number of integers in the input file is: "<< size << endl; //output the number of integers into the code terminal
    cout << "The total number of swaps that were required to sort the file is: " << swaps << endl; //output the number of swaps required to sort the code
    return 0;
}
