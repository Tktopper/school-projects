/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package loanaccount;

/**
 *
 * @author tannerkleintop
 * Tuesday May 30, 2023
 * CMPSC 221
 * The purpose of this code is to provide 2 loans and display their interest rates. 
 * The 2 will be displayed with 1% and 5% interest rates. One loan will be a $5000.00 and another will be $31000.00
 */

/**
 * This class represents a loan account and calculates monthly payments for different loan durations and interest rates.
 * The loan amounts and interest rates are specified in the main method.
 */
public class LoanAccount {
    private final double principal; //private variable to store the loan ammount
    private static double annualInterestRate; //static variable used to set the annual interest rates

    /**
     * Constructor to initialize the loan amount.
     * @param principal The loan amount.
     */
    public LoanAccount(double principal) {
        this.principal = principal;
    }

    
    /**
     * Sets the annual interest rate.
     * @param rate The annual interest rate.
     */
    public static void setAnnualInterestRate(double rate) {
        annualInterestRate = rate;
    }

     /**
     * Calculates the monthly payment for a given number of payments.
     * @param numberOfPayments The number of payments.
     * @return The monthly payment.
     */
    public double calculateMonthlyPayment(int numberOfPayments) {
        double monthlyInterest = annualInterestRate / 12;
        double denominator = Math.pow(1 + monthlyInterest, -numberOfPayments);
        double monthlyPayment = principal * (monthlyInterest / (1 - denominator));
        return monthlyPayment;
    }

    //main function of this code
    public static void main(String[] args) {
        LoanAccount loan1 = new LoanAccount(5000.00); //creates a loan named loan1 with a value of 5000.00
        LoanAccount loan2 = new LoanAccount(31000.00); //creates another loan named loan2 with a value of 31000.00

        // Set annualInterestRate to 1%
        LoanAccount.setAnnualInterestRate(0.01);

       
        //below is the output block used to display the output of the loan 1 and loan 2 using an interest rate of 1%. 
        //first a column displays across the top with a loan column followed by a colum of 3 years, then 5 years, then 6 years.
        System.out.println("Monthly payments for loan1 of $5000.00 and loan2 $31000.00 for 3, 5, and 6 year loans at 1% interest.");
    System.out.println(("Loans\t") + ("3 Years\t") + ("5 Years\t") + ("6 Years"));
    System.out.println(("loan1\t") + String.format("%.2f", loan1.calculateMonthlyPayment(36)) + "\t" 
        + String.format("%.2f", loan1.calculateMonthlyPayment(60)) + "\t" 
        + String.format("%.2f", loan1.calculateMonthlyPayment(72)));
    System.out.println(("loan2\t") + String.format("%.2f", loan2.calculateMonthlyPayment(36)) + "\t" 
        + String.format("%.2f", loan2.calculateMonthlyPayment(60)) + "\t" 
        + String.format("%.2f", loan2.calculateMonthlyPayment(72)));
    
            System.out.println(); //adds an blank line

        // Set annualInterestRate to 5%. it is important to note this is necessary to change the interest rate because not adding this would
        //keep the interest rate at 1% from the previous output block.
        LoanAccount.setAnnualInterestRate(0.05);
        
        //below is the output block that follows the exact same format as used above instead the interest rate for this block is 5%.
        //other than that, everything is the same.
        System.out.println("Monthly payments for loan1 of $5000.00 and loan2 $31000.00 for 3, 5, and 6 year loans at 5% interest.");
    System.out.println(("Loans\t") + ("3 Years\t") + ("5 Years\t") + ("6 Years"));
    System.out.println(("loan1\t") + String.format("%.2f", loan1.calculateMonthlyPayment(36)) + "\t" 
        + String.format("%.2f", loan1.calculateMonthlyPayment(60)) + "\t" 
        + String.format("%.2f", loan1.calculateMonthlyPayment(72)));
    System.out.println(("loan2\t") + String.format("%.2f", loan2.calculateMonthlyPayment(36)) + "\t" 
        + String.format("%.2f", loan2.calculateMonthlyPayment(60)) + "\t" 
        + String.format("%.2f", loan2.calculateMonthlyPayment(72)));
    
    }
}
