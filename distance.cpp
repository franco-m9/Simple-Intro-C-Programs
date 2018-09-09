/* Name: Franco Marcoccia
Date: 10/4/2017
Section: 1
Assignment: Homework 3 Exercise 2
Due Date: Friday October 6th at 11:59:00pm
About this project: This project uses various functions to display a message and convert values.
Assumptions: Assumes user inputs valid integer value.

All work below was performed by Franco Marcoccia */

#include <iostream>
#include <cmath>
using namespace std;

void WelcomeUser();																			// function that displays welcome message
int NumMillimeters(int meters, int centimers, int millimeters);								// function to convert values
int main()
{
	int mete1, centi1, milli1, mete2, centi2, milli2;										// variable declarations
	WelcomeUser();													
	cout << "Input first distance..." << endl;												// user inputted values
	cout << "Meters: ";
	cin >> mete1;
	cout << "Centimeters: ";
	cin >> centi1;
	cout << "Millimeters: ";
	cin >> milli1;

	cout << endl << "Input second distance..." << endl;										// further user inputed values
	cout << "Meters: ";
	cin >> mete2;
	cout << "Centimeters: ";
	cin >> centi2;
	cout << "Millimeters: ";
	cin >> milli2;

	cout << endl << "The first distance is " << NumMillimeters(mete1, centi1, milli1) << " mm." << endl;					// function converts to mm
	cout << "The second distance is " << NumMillimeters(mete2, centi2, milli2) << " mm." << endl;							// function converts to mm
	cout << "The difference is " << abs(NumMillimeters(mete1,centi1,milli1)-NumMillimeters(mete2,centi2,milli2)) << " mm." << endl;		// finds difference
	

	return 0;
}
void WelcomeUser()
{
	cout << "Welcome to the Millimeter Converter 2017!" << endl;
	cout << "Enter two distances and they'll be converted to millimeters (mm)." << endl << endl;
}
int NumMillimeters(int meters, int centimeters, int millimeters)
{
	int conversion = (meters * 1000) + (centimeters * 10) + (millimeters);
	return conversion;
}
