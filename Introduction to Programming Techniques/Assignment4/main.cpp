//
// Tanner Kleintop
// 9/16/2021
// This program will ask the user to provide 2 integers, after providing it will show the result of them being added, subtracted, divided, etc.
#include <iostream>
using namespace std;
int main()
{
	int num1, num2, sum, difference, difference2, product, quotient, quotient2, result, result2;
	cout << " Enter two non-negative integers=> " << endl;
	cin >> num1 >> num2;
	sum = num1 + num2;
	cout << num1 << " added to " << num2 << " is: " << sum << endl;
	difference = num1 - num2;
	cout << num2 << " subtracted from " << num1 << " is: " << difference << endl;
	difference2 = num2 - num1;
	cout << num1 << " subtracted from " << num2 << " is: " << difference2 << endl;
	product = num1 * num2;
	cout << num1 << " multiplied by " << num2 << " is: " << product << endl;
	if (num2 == 0) {
		cout << num1 << " Cannot be divided by " << num2 << endl;
	}
	else {
		quotient = num1 / num2;
		cout << num1 << " divided by " << num2 << " is: " << quotient << endl;
	}
	if (num1 == 0) {
		cout << num2 << " cannot be divided by " << num1 << endl;
	}
	else {
		quotient2 = num2 / num1;
		cout << num2 << " divided by " << num1 << " is: " << quotient2 << endl;
	}
	if (num2 == 0) {
		cout << "Cannot compute " << num1 << " modulo " << num2 << endl;
	}
	else {
		result = num1 % num2;
		cout << num1 << " modulo " << num2 << " is: " << result << endl;
	}
	if (num1 == 0) {
		cout << "Cannot compute " << num2 << " modulo " << num1 << endl;
	}
	else {
		result2 = num2 % num1;
		cout << num2 << " modulo " << num1 << " is: " << result2 << endl;
	}

	return 0;
	return 0;
}
