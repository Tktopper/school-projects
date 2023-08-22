/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package pizzaservingscalculator;

/**
 * The PizzaServingsCalculator class represents a GUI application to calculate the number of servings
 * that a circular pizza of a certain diameter will make.
 * The GUI includes a title, a text field for input, a button to perform the calculation, and a label to display the result.
 * The number of servings is calculated based on the size of the pizza entered by the user.
 * The GUI is built using Java Swing components.
 * The GUI class extends JFrame to create a window for the application.
 * 
 * @author tannerkleintop
 */
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PizzaServingsCalculator extends JFrame {

    private JLabel servingsLabel;

    public PizzaServingsCalculator() {
        setTitle("Pizza Servings Calculator"); // Set the title of the window
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // Set the close operation
        setSize(350, 300); // Set the size of the window

        setLayout(new GridLayout(4, 1)); // Set the layout of the window to a 4x1 grid

        JLabel titleLabel = new JLabel("Pizza Serving Calculator"); // Create a label for the title
        titleLabel.setHorizontalAlignment(SwingConstants.CENTER); // Center align the title label
        titleLabel.setForeground(Color.RED); // Set the color of the title label to red
        titleLabel.setFont(new Font("Arial", Font.BOLD, 20)); // Set the font of the title label
        add(titleLabel); // Add the title label to the window

        JPanel line2 = new JPanel(); // Create a panel for the second line
        JLabel sizeLabel = new JLabel("Enter the size of the pizza in inches: "); // Create a label for the pizza size input
        JTextField sizeTextField = new JTextField(4); // Create a text field for the pizza size
        line2.add(sizeLabel); // Add the size label to the panel
        line2.add(sizeTextField); // Add the size text field to the panel
        add(line2); // Add the panel to the window

        JButton calculateButton = new JButton("Calculate Servings"); // Create a button for calculating servings
        calculateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                double size = Double.parseDouble(sizeTextField.getText()); // Get the size entered by the user
                double servings = Math.pow(size / 8, 2); // Calculate the number of servings
                servingsLabel.setText(String.format("A %.2f inch pizza will serve %.2f people", size, servings)); // Set the text of the servings label
            }
        });
        add(calculateButton); // Add the button to the window

        servingsLabel = new JLabel(); // Create a label for displaying the servings
        servingsLabel.setHorizontalAlignment(SwingConstants.CENTER); // Center align the servings label
        add(servingsLabel); // Add the servings label to the window
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                PizzaServingsCalculator calculator = new PizzaServingsCalculator(); // Create an instance of the PizzaServingsCalculator
                calculator.setVisible(true); // Set the visibility of the calculator window to true
            }
        });
    }
}
