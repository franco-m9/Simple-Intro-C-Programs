/* Name: Franco Marcoccia
Date: 9/20/2017
Section: 1
Assignment: Homework 2 (Coins)
Due Date: Tuesday Sept 26 at 11:59:00pm
About this project: using selection statements to determine if user can match inputed dollar value with coins
Assumptions: Assumes user will enter valid dolar amount in form of dd.cc (two decimal places)

All work below was performed by Franco Marcoccia */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	char letter;																				                                    // established variable
	double dollar;																				                                    // established variable
	int hdollars, quarters, dimes, nickels, pennies;											                                    // established variables
	
	cout << fixed << showpoint << setprecision(2);												                                    // set decimal place to two

	cout << "Welcome to the coin game!" << endl;
	cout << "Would you like to play? (y or n) --> ";
	cin >> letter;																				                                    // user input

	if (letter == 'y' || letter == 'Y')
{
		cout << "What amount of $ would you like to match? --> ";								                                    // if user plays, asks them the variable values
		cin >> dollar;
		cout << "Okay! You need to match the value of $" << dollar << endl;
		cout << "Enter the number of: " << endl;
		cout << "	Half Dollars:  ";
		cin >> hdollars;
		cout << "	Quarters:  ";
		cin >> quarters;
		cout << "	Dimes:  ";
		cin >> dimes;
		cout << "	Nickels:  ";
		cin >> nickels;
		cout << "	Pennies:  ";
		cin >> pennies;
		
		if (hdollars < 0 || quarters < 0 || dimes < 0 || nickels < 0 || pennies < 0)				                                // gives message if user inputs negative value
			cout << "You can't enter a negative amount of coins. Aborting game." << endl;

		else if ((hdollars * .50) + (quarters * .25) + (dimes * .10) + (nickels * .05) + (pennies * .01) == dollar)                 // value matches dollar value
			cout << "You WIN!" << endl << "Thanks for playing!" << endl;
		
		double lost_value = dollar - ((hdollars * .50) + (quarters * .25) + (dimes * .10) + (nickels * .05) + (pennies * .01));     // lost value formula
		
		if ((hdollars * .50) + (quarters * .25) + (dimes * .10) + (nickels * .5) + (pennies * .01) != dollar)
		cout << "You LOST by: $" <<  abs(lost_value) << endl << "Thanks for playing!" << endl;                                      // absolute value of lost by value
}
	else if (letter == 'n' || letter == 'N')																						// user doesn't play
		cout << "Guess you're scared! Come back when you're ready to play!" << endl;												
	else if (letter != 'y' && letter != 'n' && letter != 'Y' && letter != 'N')														// user entered wrong character
		cout << "Invalid entry, aborting program." << endl;
	
	return 0;
}