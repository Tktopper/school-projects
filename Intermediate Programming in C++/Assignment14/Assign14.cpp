/*
* Tanner Kleintop
* April 21, 2023
* The purpose of this code prompt the user for 2 points (x,y) and output the equation of the line, slope, distance, and the midpoint.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

// A Point class to represent a point in a 2D space
class Point {
private:
	double xCoord = 0; // x-coordinate of the point
	double yCoord = 0; // y-coordinate of the point
public:
	Point() {}; // Default constructor
	Point(double x, double y) { // Constructor with arguments to initialize the coordinates
		xCoord = x;
		yCoord = y;
	}
	double getX() { return xCoord; } // Getter function for x-coordinate
	void setX(double x) { xCoord = x; } // Setter function for x-coordinate
	double getY() { return yCoord; } // Getter function for y-coordinate
	void setY(double y) { yCoord = y; } // Setter function for y-coordinate

	// A function to calculate the distance between this point and another point 'p'
	double distance(Point p) {
		// Using the distance formula: distance = sqrt((x2 - x1)^2 + (y2 - y1)^2)
		return pow(pow(p.xCoord - xCoord, 2.0) + pow(p.yCoord - yCoord, 2.0), 0.5);
	}

	// A function to determine the quadrant in which this point lies
	string getQuadrant() {
		if ((xCoord == 0.0) && (yCoord == 0.0)) return "Origin"; // If point is at origin
		else if (xCoord == 0.0) return "Y-axis"; // If point lies on y-axis
		else if (yCoord == 0.0) return "X-axis"; // If point lies on x-axis
		else if ((xCoord > 0.0) && (yCoord > 0.0)) return "Quadrant I"; // If point is in quadrant I
		else if ((xCoord < 0.0) && (yCoord > 0.0)) return "Quadrant II"; // If point is in quadrant II
		else if ((xCoord < 0.0) && (yCoord < 0.0)) return "Quadrant III"; // If point is in quadrant III
		else return "Quadrant IV"; // If point is in quadrant IV
	}

	// A function to calculate the midpoint between this point and another point 'p'
	Point midpoint(Point p) {
		Point pAux; // Create a new point object to store the midpoint
		pAux.xCoord = (xCoord + p.xCoord) / 2.0; // Calculate the x-coordinate of midpoint
		pAux.yCoord = (yCoord + p.yCoord) / 2.0; // Calculate the y-coordinate of midpoint
		return pAux; // Return the midpoint as a new point object
	}
};


// Define a Line class that takes two points as input and calculates its equation
class Line {
private:
	// Initialize private variables
	double slope = 0;
	double yIntercept = 0;
	bool isVertical = 0;
	double xIntercept = 0;

public:
	// Constructor that takes two Point objects and calculates the line's equation
	Line(Point p1, Point p2) {
		// If the line is vertical, set isVertical flag to true and calculate the x-intercept
		if (p1.getX() == p2.getX()) {
			isVertical = true;
			xIntercept = p1.getX();
		}
		// If the line is not vertical, calculate the slope, y-intercept, and set isVertical flag to false
		else {
			isVertical = false;
			slope = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
			yIntercept = p1.getY() - slope * p1.getX();
		}
	}

	// Method to print the equation of the line
	void printEquation() {
		// If the line is vertical, print the x-intercept
		if (isVertical) {
			cout << "x = " << fixed << setprecision(4) << xIntercept << endl;
		}
		// If the line is not vertical, print the slope and y-intercept
		else {
			cout << "y = ";
			if (slope == 0) {
				cout << fixed << setprecision(4) << yIntercept << endl;
			}
			else {
				cout << fixed << setprecision(4) << slope << "x + " << yIntercept << endl;
			}
		}
	}
};

// Main function to demonstrate usage of the Line class
int main() {
	// Prompt user to enter coordinates for two points
	double x1, y1, x2, y2;
	cout << "Enter the x-coordinate of the first point: ";
	cin >> x1;
	cout << fixed << setprecision(4);
	cout << "Enter the y-coordinate of the first point: ";
	cin >> y1;
	cout << fixed << setprecision(4);
	cout << "Enter the x-coordinate of the second point: ";
	cin >> x2;
	cout << fixed << setprecision(4);
	cout << "Enter the y-coordinate of the second point: ";
	cin >> y2;
	cout << fixed << setprecision(4);


	// Create Point objects for the two points entered by the user
	Point p1(x1, y1);
	Point p2(x2, y2);

	// Display information about the two points, such as the quadrant they are in, their midpoint, and their distance from each other
	cout << "p1 = (" << p1.getX() << "," << p1.getY() << ")" << endl;
	cout << "Location = " << p1.getQuadrant() << endl;
	cout << "p2 = (" << p2.getX() << "," << p2.getY() << ")" << endl;
	cout << "Location = " << p2.getQuadrant() << endl;

	Point midP = p1.midpoint(p2);
	cout << "The midpoint is at (" << midP.getX() << "," << midP.getY() << ")" << endl;

	double d = p1.distance(p2);
	cout << "Distance between the points: " << fixed << setprecision(4) << p1.distance(p2) << endl;

	// Create a Line object from the two Point objects and display its equation
	Line line(p1, p2);
	line.printEquation();

	return 0;
}
