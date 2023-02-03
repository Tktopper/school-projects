//
//Tanner Kleintop
//11/9/21
//The Purpose of this code is to provide a loan amount, years to repay, and interest rate. an output file will be provided breaking down each payment per month.
//
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    //declaring variables
        //NumberofMonths is the years multiplied by 12 to break down months/number of monthly payments
        //annualrate is the rate inputted as a percentage (ex: 3.5%)
        //annualratedec is the annualrate divided by 100 to get it as a decimal
        //MIR is the monthly interest rate (yearly rate divided by 12)
        //payment is the amount paid per pay cycle
        //loanamount is the loan that you inputted
        //years is the number of years the loan will be paid off inputted
        // MI is the monthy interest value
    double NumberofMonths, annualrate, annualratedec, MIR;
    double payment, loanamount, years, term, la, MI;
    cout<<"enter the principal amount:\n$"; //user input for loan value
    cin>>loanamount; //storing loan value
    cout<<"enter the annual percentage interest rate:\n"; //user input for percent rate
    cin>>annualrate; //storing percent interest rate
    cout<<"how many years:\n"; //user input for number of years
    cin>>years; //storing number of years
        ofstream output; //used to declare a file output
        string filename; //stores filename
        cout<<"Enter Output Filename: ";//asking for user input on what the file will be named
        cin>>filename;//storirng file name
        output.open (filename);//opening filename
    NumberofMonths = 12 * years; //math for the NumberofMonths
    annualratedec = annualrate / 100; //math for the annualratedec
    MIR = annualratedec / 12.0; //math for the monthy interest Rate
        if (annualratedec == 0) //if statement for if the decimal is 0
            payment = loanamount / NumberofMonths;
        else //else statement to declare the math 
            {
                term = pow((1 + MIR), NumberofMonths); //math to solve for the term
                payment = (loanamount * MIR * term) / (term - 1.0); //math to declare what the payment will be
            }
    output<<"Loan Amount (principal) is $"<<loanamount<<"\n"; //outputting the loan amount into the file
    output<<"Yearly Rate is "<<annualratedec<<"\n"; //outputting the yearly rate as a decimal into the file
    output<<"Term (Years) is "<<years<<"\n"; //outputting the number of years into the file
    output<<"Monthly payment is $"<<payment<<"\n"<<endl; //outputting the monthly payment into the file
                output << setw(1)<<"Months";//declaring months as a value at the top of where numbers will be displayed below
                output << setw(15)<<"Balance";//declaring the balance as a value at the top of where numbers will be displayed below
                output << setw(20)<<"Interest";//displaying interest above where numbers will be displayed
                output << fixed << showpoint << setprecision(2);//setting the values beyond this point to 2 decimal places
                output << setw(25)<<"Payment"<<endl;//dispalying the payment above where numbers will go
         for (int month = 0; month <= NumberofMonths; month++) //for statement that will allow the code to run from 0 to x amount of months depending on the year inputted
    {
        loanamount -= la;
        MI = MIR * loanamount; //math for the monthly interest value
        if (month != NumberofMonths) //if statement for the loanamount
            la = payment - MI; //math for the loanamount
        else
        {
            la = loanamount; //declaring that when the values equal each other
        }
        output << setw(5)  << month << setw(10) << "$" << setw(10) << loanamount << setw(9) << "$";
        output << setw(7) << MI << setw(20) << "$" << setw(7) << payment << endl;
    }
        return 0;
    }







