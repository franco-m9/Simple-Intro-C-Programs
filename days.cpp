/* Name: Franco Marcoccia
Date: 9/20/2017
Section: 1
Assignment: Homework 2 (Days)
Due Date: Tuesday Sept 26 at 11:59:00pm
About this project: Usage of selection statements to calculate the number of days in a month depending on the year.
Assumptions: Assumes correct user input of year

All work below was performed by Franco Marcoccia */
#include <iostream>
using namespace std;

int main()
{
	int month, year;																						// established variables
	cout << "Enter a month (1-12): ";
	cin >> month;																							// stores user inputted month
	cout << "Enter a year: ";
	cin >> year;																							// stores user inputted year
	cout << endl;

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)	// if any of these months display 31
		cout << "Number of days: 31" << endl;
	else if (month == 4 || month == 6 || month == 9 || month == 11)											// if any of these months display 30
		cout << "Number of days: 30" << endl;
	else if (month == 2)																					// displays days depending if it's a leap year
	{
		if (year % 100 == 0 && year % 400 == 0)
			cout << "Number of days: 29" << endl;
		else if (year % 100 != 0 && year % 4 == 0)
			cout << "Number of days: 29" << endl;
		else if (year % 100 != 0 && year % 4 != 0)
			cout << "Number of days: 28" << endl;
		else if (year % 100 == 0 && year % 400 != 0)
			cout << "Number of days: 28" << endl;
	}
	else if (month < 1 || month > 12)																		// makes sure the month is between 1-12
		cout << "Invalid Month entered. Aborting Program." << endl;

	return 0;
}