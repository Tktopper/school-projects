//
//Tanner Kleintop
//12/14/21
//The purpose of this code is to provide an input file, getting back an output file with a list of the grades to each letter, meanm range min/max and standarddeviation.
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
   int maximumnumberofgrades = 100; //declaring the maximum value of grades to input as 100
   char INPUTFILE[maximumnumberofgrades]; //taken the input file into an array
   char OUTPUTFILE[maximumnumberofgrades] = "GradesOutput.txt"; //naming the output file
   float scores[100],sumvalue = 0,mean,standarddeviation; //declaring variables scores is for an array holding the scores, sumvalue is the sum, mean is the mean, and standard deviation is for standard deviation
   int count = 0, i; //setting count to equal i and 0
   float STOREDPERCENTS; //stored percents from the input file

   cout<<"Enter the name of file: "; //asking for user input
   cin>>INPUTFILE; //storing input

   ifstream INFILE;
   ofstream OUTFILE;
   INFILE.open(INPUTFILE);
   OUTFILE.open(OUTPUTFILE);
   
   if (!INFILE.is_open()) //if statement for if the entered file name could not be found
   {
        cout << "Could not open the input file entered" << endl;
        return 0;
    }

   while(INFILE>>STOREDPERCENTS) //while loop to continue to store values until all are stored
       scores[count++] = STOREDPERCENTS; 

   INFILE.close(); //closing the input file

   int MAXIMUM = scores[0]; //declaring the MAXIMUM to scores[0]
   int MINIMUM = scores[0]; //declaring the MINIMUM to scores[0]
   for(i=0;i<count;i++) //for loop for the sum
   {
      sumvalue += scores[i];
      if(scores[i] < MINIMUM)
        MINIMUM = scores[i];
      if(scores[i] > MAXIMUM)
        MAXIMUM = scores[i];
   }

   mean = sumvalue/count; //math for the mean value
   OUTFILE<<"minimum score is " << MINIMUM << endl; //output the maximum
   OUTFILE<<"maximum score is " << MAXIMUM << endl; //output the minimum
   OUTFILE<<"The range of scores is " << (MAXIMUM-MINIMUM) << endl; //range of scores
   OUTFILE<<"The mean is "<<mean<<endl; //outputting the mean
   sumvalue = 0; //setting the sum value to zero

   for(i=0;i<count;i++) //for loop to get sum value
       sumvalue += (scores[i] - mean)*(scores[i] - mean);

   sumvalue = sumvalue/count; //math for sume value
   standarddeviation = sqrt(sumvalue); //math for standarddeviation
   OUTFILE<<"The standard deviation is "<<standarddeviation<<endl; //outputting standard deviation

   float m,s,individualscore; //declaring variables of the mean, standarddeviation and individualscores.
   m = mean;
   s = standarddeviation;

    //declaring variables for each letter grade
   int Arkansas=0,Aminus=0,Bplus=0,Boredum=0,Bminus=0,Cplusplus=0,Cantdoitman=0,Cminus=0,Didnttechnicallyfail=0,Failed=0;

   for(i=0;i<count;i++) //for loop to sort the letter grades.
   {
       individualscore = scores[i];
       if( individualscore>= m+4/3.0*s )
           Arkansas++;
       else if( individualscore>= m+3/3.0*s )
           Aminus++;
       else if( individualscore>= m+2/3.0*s )
           Bplus++;
       else if( individualscore>= m+1/3.0*s )
           Boredum++;
       else if( individualscore>= m+0/3.0*s )
           Bminus++;
       else if( individualscore>= m-1/3.0*s )
           Cplusplus++;
       else if( individualscore>= m-2/3.0*s )
           Cantdoitman++;
       else if( individualscore>= m-3/3.0*s )
           Cminus++;
       else if( individualscore>= m-4/3.0*s )
           Didnttechnicallyfail++;
       else
           Failed++;
   }
        //Used to output the students grades in a neatly orgranized chart, declaring how many letter grades for each letter.
   OUTFILE<<"Number of grades in category A = "<<Arkansas<<endl;
   OUTFILE<<"Number of grades in category A- = "<<Aminus<<endl;
   OUTFILE<<"Number of grades in category B+ = "<<Bplus<<endl;
   OUTFILE<<"Number of grades in category B = "<<Boredum<<endl;
   OUTFILE<<"Number of grades in category B- = "<<Bminus<<endl;
   OUTFILE<<"Number of grades in category C+ = "<<Cplusplus<<endl;
   OUTFILE<<"Number of grades in category C = "<<Cantdoitman<<endl;
   OUTFILE<<"Number of grades in category C- = "<<Cminus<<endl;
   OUTFILE<<"Number of grades in category D = "<<Didnttechnicallyfail<<endl;
   OUTFILE<<"Number of grades in category F = "<<Failed<<endl;
//stating where the results are being stored
   cout<<"All results are stored in "<<OUTPUTFILE<<endl;
   return 0;
}
