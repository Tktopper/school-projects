/*
Tanner Kleintop
January 19, 2023
The purpose of this code is to prompt the user for 2 integers and using a recursive function, the gcd for the two factors will be found.
*/

#include <iostream>

using namespace std;

int gcd(int a, int b); //reads the secondary function so it can be used in the main function

int main() //main function of the code
{
	int a; //declaring "a" as an integer
	int b; //declaring "b" as an integer
	cout << "Provide two positive integers: "; //display in the console asking the user for 2 inputs
	cin >> a >> b; //storing the two positive inputs
	cout << endl;
	while (a < 0 || b < 0) //if statement outputting if one or both of the integers is not positive
	{
		cout << "One of the integers provided was not positive. Enter another set of integers: "; //outputted if the following condition in the if statement is true
		cin >> a >> b; //storing the two positive inputs
		cout << endl;
	}
	if (a > 0 || b > 0) //else statement displayed after checking that both integers are positive
	{
		cout << "The GCD of " << a << " and " << b << " is " << gcd(a, b) << endl; //displaying the gcd of a and b
		return 0; //ends the code
	}
}

int gcd(int a, int b) //secondary function where all the math is done
{
	if (b != 0) //if b != 0 this is done
		return gcd(b, a % b);
	else //else statement for any other arugements
		return a;
}
