/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package loanaccounthierarchy;

/**
 * PrimaryMortgage class represents a type of loan account specifically for primary mortgages.
 * It extends the LoanAccount class.
 * 
 * It contains information about the PMI (Private Mortgage Insurance) monthly amount
 * and the property address.
 * 
 * @author tannerkleintop
 */
public class PrimaryMortgage extends LoanAccount {
    private double PMIMonthlyAmount; // Stores the PMI monthly amount
    private Address address; // Stores the property address

    /**
     * Constructs a PrimaryMortgage object with the specified principal, annual interest rate,
     * number of months, PMI monthly amount, and property address.
     * 
     * @param principal the loan principal amount
     * @param annualInterestRate the annual interest rate for the loan
     * @param months the number of months for the loan
     * @param PMIMonthlyAmount the monthly amount for Private Mortgage Insurance
     * @param address the property address
     */
    public PrimaryMortgage(double principal, double annualInterestRate, int months, double PMIMonthlyAmount, Address address) {
        super(principal, annualInterestRate, months);
        this.PMIMonthlyAmount = PMIMonthlyAmount;
        this.address = address;
    }

    /**
     * Returns a string representation of the PrimaryMortgage object.
     * 
     * @return a string containing information about the primary mortgage loan, including
     *         the loan details, PMI monthly amount, and property address
     */
    @Override
    public String toString() {
        return "Primary Mortgage Loan with:\n" + super.toString() +
                "PMI Monthly Amount: $" + PMIMonthlyAmount + "\n" +
                "Property Address:\n" +
                address.toString() + "\n";
    }
}
