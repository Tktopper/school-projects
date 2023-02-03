//
// Tanner Allen Kleintop
// 9/30/21
// Determines the monthly credit card charges for a client and wether last months charges minus the monthly payments made exceeds the credit limit
//

#include <iostream>
using namespace std;
int main()
{
	double limit; // input
	double balance;// input
	double payment;// input
	double charge=1; // input
	cout << "Enter last month's balance => $"; //Asking to insert last months balance
	cin >> balance;
	cout << "Enter the payment made on the last balance => $"; //Asking to input the payment made on last months balance
	cin >> payment;
	cout << "Enter your credit limit on this card => $"; //Asking for the limit on the card used
	cin >> limit; //starting input
	balance = balance - payment; // New balance
	cout << "Beginning Balance = $" << balance << endl; //Outputting new balance
	while(balance != limit && charge != 0) //While loop for when the balance does not equal the limit that is set on the card. Entering 0 will end the limit
	{
		cout << "enter a charge (enter 0 to exit) => $"; //asking for a charge, enter zero to exit
		cin >> charge; //starting input
		balance = balance + charge; //New balance
		cout << "New Balance = $" << balance << endl; //Outputting the new balance

		if (balance >= limit) //If the statement limit on the card is greater than or equal, this message will be run.
		{
			cout << "Credit limit exceeded!"; //Output when limit is hit or exceeded.
			return 0;
		}
	}
}


