/* Name: Franco Marcoccia
Date: 9/6/2017
Section: 1
Assignment: Homework 1
Due Date: Friday, Sept. 8th, 11:59:00pm
About this project: Calculating the area of various shapes with user inputed values
Assumptions: Assumes correct user input

All work below was performed by Franco Marcoccia */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	const double PI = 3.14159;																			// established constant PI value
	double circle_radius, square_length, triangle_base, triangle_height;								// established variables to calculate area

cout << "Welcome to the COP3014 Area Calculator!" << endl;
cout << "Please provide the following (all sizes in meters): " << endl;
cout << "	Radius of the Circle: ";
cin >> circle_radius;																					// user inputed value
cout << "	Side length of Square: ";
cin >> square_length;																					// user inputed value
cout << "	Base length of the Triangle: ";
cin >> triangle_base;																					// user inputed value
cout << "	Height of the Triangle: ";
cin >> triangle_height;																					// user inputed value
cout << "--------------------------------------------------" << endl;
cout << fixed << showpoint << setprecision(2) << endl;													// values set to two decimal places
cout << "Area of the Circle: " << circle_radius * circle_radius * PI << "m" << endl;
cout << "Area of the Square: " << square_length * square_length << "m" << endl;
cout << "Area of the Triangle: " << .50 * triangle_base * triangle_height << "m" << endl << endl;
cout << "Thanks for using the COP3014 Area Calculator!" << endl;
	
	return 0;
}