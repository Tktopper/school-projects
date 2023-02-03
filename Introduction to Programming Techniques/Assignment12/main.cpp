//
// Tanner Kleintop
// 11/11/21
// The purpose of this code is to roll a dice 50,000 times, Calculating the roll, Frequency, and Probability

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    const int arraysize = 13; //declaring array size of 13
    int counter[13], sum=0; //seting start Value to zero
    for(int i=0; i<13; i++) //for look for probability, etc.
        counter[i] = 0;
    int die1; //declaring dice 1
    int die2; //declaring dice 2
    double Probability;
    for ( int roll1 = 0; roll1 <=50000; roll1++ ) 
    {
        die1 =  1 + rand() % 6;
        die2 =  1 + rand() % 6;
        counter[die1+die2]++;
    }
    cout<<setw(8)<<"Roll"<<setw(13)<<"Frequency"<< setw(16)<<"Probability"<<endl;
    for(int face=2; face<arraysize;face++)
    {
        Probability=counter[face];
        cout<<setw(7)<<face<<setw(13)<<counter[face]<<setw(16)<< fixed <<showpoint<< setprecision(4)<< Probability/50000 <<endl;
        sum += counter[face];
    }
    return 0;
}



