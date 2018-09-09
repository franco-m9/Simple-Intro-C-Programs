/* Name: Franco Marcoccia
Date: 9/26/2017
Section: 1
Assignment: Homework #3 Temp
Due Date: Friday October 6th at 11:59:00am
About this project: This project converts temperatures to celcius from fahrenheit as long as the user enters yes with the usage of loops.
Assumptions: Assumes the user will enter a valid temperature value.

All work below was performed by Franco Marcoccia */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int ftemp, tconv = 0;																	// variable declaration
	double ctemp, atemp, sum = 0;															// variable declaration
	char another;																			// variable declaration

	cout << fixed << showpoint << setprecision(2);											// setting decimal place to 2
	do
	{																						// loop runs once and then keeps going if yes
		if (tconv >= 0)
		{
			cout << "Temperature to convert from F to C: ";
			cin >> ftemp;
			tconv++;
			ctemp = (ftemp - 32)*(5.0 / 9);
			cout << ftemp << "F = " << ctemp << "C" << endl << endl;
			sum = sum + ctemp;
			cout << "Enter another? (Y or N): ";
			cin >> another;
		}
	}	
	while (another == 'y' || another == 'Y');
	
	if (another == 'n' || another == 'N')												// ends program and displays ending info
	{
			cout << "Number of Temps Converted: " << tconv << endl;
			atemp = (sum / tconv);
			cout << "Average Temp: " << atemp << "C" << endl;
	}
	else
		cout << "Invalid Character Entry... Aborting Program." << endl;					// dispayed if user doesn't enter yes or no

	return 0;
}