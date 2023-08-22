/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package loanaccounthierarchy;

/**
 * Customer class represents a customer with their personal information and loan accounts.
 * It stores the first name, last name, and social security number (SSN) of the customer.
 * It also maintains a list of loan accounts associated with the customer.
 * 
 * The class provides methods to access and manipulate the customer's information and loan accounts.
 * 
 * @author tannerkleintop
 */
import java.util.ArrayList;

public class Customer {
    private String firstName;
    private String lastName;
    private String SSN;
    private ArrayList<LoanAccount> loanAccounts;

    /**
     * Constructs a Customer object with the specified first name, last name, and SSN.
     * Initializes the loanAccounts list as an empty ArrayList.
     * 
     * @param firstName the first name of the customer
     * @param lastName the last name of the customer
     * @param SSN the social security number of the customer
     */
    public Customer(String firstName, String lastName, String SSN) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.SSN = SSN;
        this.loanAccounts = new ArrayList<>();
    }

    /**
     * Returns the first name of the customer.
     * 
     * @return the first name of the customer
     */
    public String getFirstName() {
        return firstName;
    }

    /**
     * Returns the last name of the customer.
     * 
     * @return the last name of the customer
     */
    public String getLastName() {
        return lastName;
    }

    /**
     * Returns the social security number (SSN) of the customer.
     * 
     * @return the social security number (SSN) of the customer
     */
    public String getSSN() {
        return SSN;
    }

    /**
     * Adds a loan account to the customer's list of loan accounts.
     * 
     * @param account the loan account to be added
     */
    public void addLoanAccount(LoanAccount account) {
        loanAccounts.add(account);
    }

    /**
     * Generates a monthly report of the customer's loan accounts.
     * The report includes the customer's personal information and details of each loan account.
     * 
     * @return a string containing the monthly report
     */
    public String printMonthlyReport() {
        String report = "Account Report for Customer: " + firstName + " " + lastName + " with SSN " + SSN + "\n";
        for (LoanAccount account : loanAccounts) {
            report += account.toString() + "\n";
        }
        return report;
    }
}
