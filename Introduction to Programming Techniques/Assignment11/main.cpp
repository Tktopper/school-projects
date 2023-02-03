#include <iostream>
#include <array>
#include <fstream>
using namespace std;
 
int main()
//write a code that reads up to 200 numbers from a file and stores them in an array and ouputs them in a file

{
    int num[200];
    int i = 0;
    ifstream inFile;
    inFile.open("untitled");
    if (inFile.fail())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    while (inFile >> num[i])
    {
        i++;
    }
    inFile.close();
    for (int j = 0; j < i; j++)
    {
        cout << num[j] << endl;
    }
    return 0;
}




