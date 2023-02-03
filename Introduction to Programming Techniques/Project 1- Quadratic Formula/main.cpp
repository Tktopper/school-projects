//
//Tanner Kleintop
//10/20/21
// The purpose of this code is to provide coefficients a, b, and c of an equation, outputting its real/imaginary roots.
//
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() 
{
    double a, b, c, Root1, Root2, discriminant, realPart, imaginaryPart;
    cout << "Enter coefficients a, b, c => "; //asking for user input to input the three coefficients of an equation
    cin >> a >> b >> c; //storing inputs a, b, and c
    discriminant = b*b-4*a*c; //declaring the discriminant as b*b - 4*a*c
    if (a <= 0) // used to state the anything less than or equal to zero, then it is invalid.
    {
        cout << "Invalid Input (a cannot be less than or equal to 0)";
        return 0;
    }
    
    if (discriminant > 0) //if statement used if the discriminant is greater than 0
    {
        Root1 = (-b + sqrt(discriminant)) / (2*a); //equation for root one
        Root2 = (-b - sqrt(discriminant)) / (2*a); //equation for root two
        cout << "Roots are real and are different: " << endl; //output to state that roots are different and a real numbers.
        cout << fixed << setprecision(3) << "Root 1 = " << Root1 << endl;
        cout << fixed << setprecision(3) << "Root 2 = " << Root2 << endl;
    }
    else if (discriminant == 0) //else if statement used if Root 1 and Root 2 equal the same value
    {
        cout << "Roots are real and are the same: " << endl; //stating that the roots are real and that they are the same
        Root1 = (-b + sqrt(discriminant))/(2*a); //equation for root one
        cout  << "Root 1 = Root 2 = " << Root1 << endl; //outtputting that roots one and two are equal
    }
    else //else statement to declare imaginary numbers if necessary
    {
        realPart = -b/(2*a);
        imaginaryPart =sqrt(-discriminant)/(2*a);
        cout << "Two Complex Solutions are: "  << endl; //output used stating that the two roots are imaginary
        cout << "Root 1 = " << realPart << " + " << imaginaryPart << "i" << endl; //root one output
        cout << "Root 2 = " << realPart << " - " << imaginaryPart << "i" << endl; //root two output
    }
    return 0;
}




