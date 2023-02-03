//Tanner Kleintop
// 12/8/21
//The purpose of this code is to provide an ODD positive integer, the code will compute the product of every odd number from 1 to the number entered
#include <iostream>
using namespace std;
int
main ()
{
  int number;
  int startingvalue = 1;
  cout << "Enter a positive odd integer => ";	//ask for user input
  cin >> number;		// Storing the number
  while (number % 2 <= 0)	//checking the value to see if it meets the parameters of the code, being positive and odd
    {
      cout << "Error \nenter a positive odd integer => ";	// Asking for another number if the input does not meet requirements
      cin >> number;
    }
  if (number % 2 >= 1)		//if statement used once the integer entered is positive and odd
    {
      for (int i = 1; i <= number; i = i + 2)	// for statement multiplying all values from 1 to the number given
	{
	  startingvalue = startingvalue * i;	//math to calculate the product

	}
      cout << "The product is " << startingvalue << endl;	// Outputting the product result from 1 to the given value
    }
  return 0;
}

