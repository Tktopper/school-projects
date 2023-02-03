//
// Tanner Kleintop
// 10/25/21
// The purpose of this code is to provide 5 pairs of positive integers, outputting wether the first integers is a multiple of the second
//
#include <iostream>
using namespace std;
int multiple( int, int );
 int main() //main funcation
 {
   int c, m; //declaring variables. variable c is used for integer input one and m is used for integer input two.
   for ( int i = 1; i <= 5; ++i ) //for loop used to ask for user input 5 differenttimes
   {
      cout << "Enter two integers => "; // asking for user input
       cin >> c >> m; // storing user input
          if ( multiple( m, c ) ) //if statement using the function below to multiply the two together to get an output
          cout << c << " is a multiple of " << m << "\n\n"; // used to state that mis a mutiple of c
       else // else statement if c would come up as NOT a multiple of m
          cout << c << " is NOT a multiple of " << m << "\n\n";// else statement used to state that m is NOT a multiple of c
    }
    cout << endl;
    return 0;
 }
int multiple( int a, int b ) // secondary function used to b % a and input it into the main int above. 
 {
    return !( b % a ); //stating what the secondary function does
 } 



