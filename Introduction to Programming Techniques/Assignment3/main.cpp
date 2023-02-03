//
// Tanner Kleintop
// 9/7/2021
// This program will prompt the user to input 3 characters /integers/words and put them in reverse as a result
//
#include <iostream>
using namespace std;
int main()
{
	char ch1, ch2, ch3; //input
	int int1, int2, int3; //input
	string word1, word2, word3; //input
	cout << "Enter three integers including a space: " << endl; //requesting user input
	cin >> int1 >> int2 >> int3;
	cout << "In reverse:\t" << int3 << '\t' << int2 << '\t' << int1 << endl; //users input in reverse
	cout << "Enter three characters including a space: " << endl; //requesting user input
	cin >> ch1 >> ch2 >> ch3;
	cout << "In reverse:\t" << ch3 << '\t' << ch2 << '\t' << ch1 << endl; //output from users input in reverse
	cout << "Enter three words including a space: " << endl; //Requesting user input
	cin >> word1 >> word2 >> word3;
	cout << "In reverse:\t" << word3 << '\t' << word2 << '\t' << word1 << endl; //outputting user input  in reverse
	return 0;
}
