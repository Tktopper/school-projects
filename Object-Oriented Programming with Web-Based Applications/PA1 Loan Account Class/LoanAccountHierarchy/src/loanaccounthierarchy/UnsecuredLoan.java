/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package loanaccounthierarchy;

/**
 * UnsecuredLoan class represents a type of loan account for unsecured loans.
 * It extends the LoanAccount class.
 * 
 * Unsecured loans are not backed by collateral or assets.
 * 
 * This class does not have any additional instance variables.
 * 
 * @author tannerkleintop
 */
public class UnsecuredLoan extends LoanAccount {

    /**
     * Constructs an UnsecuredLoan object with the specified principal, annual interest rate,
     * and number of months.
     * 
     * @param principal the loan principal amount
     * @param annualInterestRate the annual interest rate for the loan
     * @param months the number of months for the loan
     */
    public UnsecuredLoan(double principal, double annualInterestRate, int months) {
        super(principal, annualInterestRate, months);
    }

    /**
     * Returns a string representation of the UnsecuredLoan object.
     * 
     * @return a string containing information about the unsecured loan, including
     *         the loan details
     */
    @Override
    public String toString() {
        return "Unsecured Loan with:\n" + super.toString();
    }
}
