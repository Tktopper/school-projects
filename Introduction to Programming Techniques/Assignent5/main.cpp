//
//Tanner Kleintop
//9/28/21
//The Purpose of this code is to provide 10 integers, as an output the smallest and largest integers would be given
//
#include <iostream>
using namespace std;
int main()
{
	const int MAX = 10; //Max amount of loops
	int count = 0; //count for the while loop
	int input; //stores each of the inputted numbers
	int smallest; //Output
	int largest; //Output

	cout << "Please enter 10 integers => "; //Input

	while (count != MAX) // While loop loops 10 times
	{
		cin >> input;

		if (count == 0) //What happens if when count is equaled to 0
		{
			largest = input; // largest equals input
			smallest = input; // smallest equals input
		}
		else // else statement where code decides what is the smallest and largest integers
		{
			if (input > largest) // if the input is larger than the other inputs, it becomes the new largest input
				largest = input;
			else if (input < smallest) // if the input is smaller than the other inputs, it becomes the new smallest input
				smallest = input;
		}
		count++; // adds 1 to the loop with a max of 10
	}
	cout << "The largest number is: " << largest << endl; // output
	cout << "The smallest number is: " << smallest << endl; // output
	return 0;
}



