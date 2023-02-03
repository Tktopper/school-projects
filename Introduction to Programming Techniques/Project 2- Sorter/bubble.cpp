//
//Tanner Kleintop
//11/30/21
//The purpose of this code is to provide an input file with an unsorted list of numbers, sorting the numbers using a bubble sort.
//
#include <iostream>
#include <fstream>
using namespace std;
int bubbleSort(int arr[], int size) //second function that takes the array and size, returning number of swaps required
{
    int swaps = 0; //starts number of swaps at 0
    for(int t=0; t<size-1; t++) //loop through t
    {
        for(int a=0; a<size-t-1; a++) //loop through t = 0
        {
            if (arr[a] > arr[a+1]) //if statement for if the value being evaluated is larger than the value next to it, swap the values
            {
                int temp = arr[a+1]; //store variable
                arr[a+1] = arr[a]; //copy the value at t to t+1
                arr[a] = temp; //copy value and store it to the values of t
                swaps++; //add the swaps
            }
        }
    }
    return swaps; //return the swapped numbers
}
//main function
int main()
{

    // make an ifstream and ofstream variable for the file
    ifstream infile;
    ofstream outfile;
    string filename; //string to store name of the file
    cout << "Enter name of the input file with up to 100 integers: "; //asks for user input
    cin >> filename; //stores filename
    infile.open(filename); //opens input file that was provided 
    if (!infile.is_open()) //if statement for when input file cannot be found, providing an error 
    {
        cout << "Could not open the input file entered." << endl;
        return -1;
    }
    int arr[100]; //makes an array with a size of 100
    int size = 0; //starts with a size of 0
    int x;
    while(infile >> x) //read values from file and input into the array
    {
        arr[size++] = x;
    }
    int swaps = bubbleSort(arr, size); //store the returned values and swaps from bubble sort
    outfile.open("bubblesortoutput.txt"); //open output file

    // initialize count with 0, it is basically to count 10 values per line in the output file
    int count = 0; 
    for(int t=0; t<size; t++) //for loop for the array
    {
        x = arr[t]; //output values in output file
        outfile << x;
        count++; //increase to counter
        if (count == 10) //if counter to only allow 10 values or less on each line
        {
            outfile << endl;
            count = 0;
        } 
        else //else statement to add the space in between each integer
            outfile << " ";
    }
    cout << "The name of the output file is: bubblesortoutput.txt" << endl; //output filename in code terminal
    cout << "The number of integers in the input file is: "<< size << endl; //output number of integers in terminal
    cout << "The total number of swaps that were required to sort the file is: " << swaps << endl; //output the total number of swaps into code terminal
    return 0;
}
