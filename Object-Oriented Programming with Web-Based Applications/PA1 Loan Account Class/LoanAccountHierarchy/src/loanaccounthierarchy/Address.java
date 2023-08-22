package loanaccounthierarchy;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author tannerkleintop
 */

public class Address {
    private String street;   // Represents the street address
    private String city;     // Represents the city
    private String state;    // Represents the state
    private String zipcode;  // Represents the zip code

    // Constructor to initialize the Address object with street, city, state, and zipcode
    public Address(String street, String city, String state, String zipcode) {
        this.street = street;
        this.city = city;
        this.state = state;
        this.zipcode = zipcode;
    }

    // Getter methods to retrieve the values of street, city, state, and zipcode
    public String getStreet() {
        return street;
    }

    public String getCity() {
        return city;
    }

    public String getState() {
        return state;
    }

    public String getZipcode() {
        return zipcode;
    }

    // Override the toString() method to return a formatted string representation of the address
    @Override
    public String toString() {
        return String.format("    %s%n    %s, %s %s", street, city, state, zipcode);
    }
}

