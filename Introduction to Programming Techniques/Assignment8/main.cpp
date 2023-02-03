//
// Tanner Kleintop
// 10/18/21
// The Purpose of this code is to 
//

#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    cout << "Sample File Output: " << endl; //Output
    
    cout << setw(0) << "Decimal" << setw(10) << "Octal" << setw(14) << "Hexadecimal" << endl;
    for ( int i = 1; i <= 256; ++i )
    {
        cout << setw(7) << showbase << dec << i;
        cout << setw(10) << showbase << oct << i;
        cout << setw(14) << showbase << hex << i << endl;
    }   
    cout << endl;
}
