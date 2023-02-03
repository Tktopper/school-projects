//
// Tanner Kleintop
// 10/21/21
// The purpose of this program is to have the user guess a number 1 to 1000. The user is promted if their guess is too low or high until the guess is correct
//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int num, guess, tries = 0;
	char y;
	char n;
	srand(time(0)); //seed random number generator
	num = rand() % 1000 + 1; // random number between 1 and 1000
	cout << "Guess my number between 1 and 1000 => ";
	do 
	{
		cin >> guess;
		tries++;
	
		if (guess > num)
			cout << "Too high!\n\n";
		else if (guess < num)
			cout << "Too low!\n\n";
		else
		{
			cout << "\nYou Guess the Number!";
			cout << "\nYou got it in " << tries << " guesses!\n";
		}
		if (guess > num)
		    cout << "Guess again => ";
		else if (guess < num)
		    cout << "Guess again => ";
	} 
	while (guess != num);
	    if (guess != num);
	    {
	        cout << "Would you like to play again (y or n)?";
	        
	    }
	return 0;
}






