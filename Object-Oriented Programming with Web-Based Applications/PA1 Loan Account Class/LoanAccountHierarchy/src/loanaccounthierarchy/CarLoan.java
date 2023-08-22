/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package loanaccounthierarchy;

/**
 * CarLoan class represents a type of loan account specifically for car loans.
 * It extends the LoanAccount class.
 * 
 * It contains information about the vehicle VIN (Vehicle Identification Number).
 * 
 * @author tannerkleintop
 */
public class CarLoan extends LoanAccount {
    private String vehicleVIN; // Stores the Vehicle Identification Number

    /**
     * Constructs a CarLoan object with the specified principal, annual interest rate,
     * number of months, and vehicle VIN.
     * 
     * @param principal the loan principal amount
     * @param annualInterestRate the annual interest rate for the loan
     * @param months the number of months for the loan
     * @param vehicleVIN the Vehicle Identification Number for the car
     */
    public CarLoan(double principal, double annualInterestRate, int months, String vehicleVIN) {
        super(principal, annualInterestRate, months);
        this.vehicleVIN = vehicleVIN;
    }

    /**
     * Returns a string representation of the CarLoan object.
     * 
     * @return a string containing information about the car loan, including
     *         the loan details and the vehicle VIN
     */
    @Override
    public String toString() {
        return "Car Loan with:\n" + super.toString() +
                "Vehicle VIN: " + vehicleVIN + "\n";
    }
}
