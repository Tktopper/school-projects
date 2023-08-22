/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package loanaccounthierarchy;


/**
 * The LoanAccount class represents a generic loan account.
 */
public class LoanAccount {
    private double principal; // Stores the principal amount of the loan
    private double annualInterestRate; // Stores the annual interest rate of the loan
    private int months; // Stores the term of the loan in months

    /**
     * Constructs a LoanAccount object with the specified principal, annual interest rate, and term.
     *
     * @param principal          the principal amount of the loan
     * @param annualInterestRate the annual interest rate of the loan
     * @param months             the term of the loan in months
     */
    public LoanAccount(double principal, double annualInterestRate, int months) {
        this.principal = principal;
        this.annualInterestRate = annualInterestRate;
        this.months = months;
    }

    /**
     * Calculates the monthly payment for the loan.
     *
     * @return the monthly payment amount
     */
    public double calculateMonthlyPayment() {
        double monthlyInterestRate = annualInterestRate / 100 / 12;
        double numerator = monthlyInterestRate * Math.pow(1 + monthlyInterestRate, months);
        double denominator = Math.pow(1 + monthlyInterestRate, months) - 1;
        return principal * (numerator / denominator);
    }

    /**
     * Returns the principal amount of the loan.
     *
     * @return the principal amount
     */
    public double getPrincipal() {
        return principal;
    }

    /**
     * Returns the annual interest rate of the loan.
     *
     * @return the annual interest rate
     */
    public double getAnnualInterestRate() {
        return annualInterestRate;
    }

    /**
     * Returns the term of the loan in months.
     *
     * @return the term in months
     */
    public int getMonths() {
        return months;
    }

    /**
     * Returns a string representation of the LoanAccount object.
     *
     * @return a string representation of the object
     */
    @Override
    public String toString() {
        return String.format("Principal: $%.2f%n" +
                "Annual Interest Rate: %.2f%%%n" +
                "Term of Loan in Months: %d%n" +
                "Monthly Payment: $%.2f%n", principal, annualInterestRate, months, calculateMonthlyPayment());
    }
}

