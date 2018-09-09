/* Name: Franco Marcoccia
Date: 11/7/2017
Section: 1
Assignment: Homework #6
Due Date: Monday November 13th 11:59:00pm
About this project: This project uses c-strings/string objects to create a password tester
Assumptions: Assumes maximum size is 80

All work below was performed by Franco Marcoccia */

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

void EnterP();																										// function for menu
int main()
{
	const int SIZE = 80;																							// declares constant array size
	char passw[SIZE];																								// user input password
	char passw2[SIZE];																								// password to compare

	do
	{
		EnterP();
		cin >> passw;


		if (strlen(passw) < 6)																						// checks if length of char array is less than 6
			cout << "Password needs to have 6 or more characters" << endl;


		int uppercase = 0, lowercase = 0, digit = 0;																// initializes counters
		for (int i = 0; i < strlen(passw); i++)																		// loop for counters
		{
			if (isupper(passw[i]))
				uppercase++;
			else if (islower(passw[i]))
				lowercase++;
			else if (isdigit(passw[i]))
				digit++;
		}

		if (uppercase != 0 && lowercase != 0 && digit != 0 && strlen(passw)>6)										// if all conditions are met, check pw
		{
			cout << "Now re-enter your password for verification: ";
			cin >> passw2;
			
			if (strcmp(passw, passw2) != 0)																			// passwords don't match
				cout << "Password does not match. Start over" << endl;
			else																									// passwords match
				cout << endl << "You have now entered a valid password" << endl;
		}
			
			if (uppercase == 0)
				cout << "Password needs to contain at least one uppercase letter" << endl;
			else if (uppercase != 0)																				// sets counter back to 0 for future pw
				uppercase = 0;

			if (lowercase == 0)	
				cout << "Password needs to have at least one lowercase letter" << endl;
			else if (lowercase != 0)																				// sets counter back to 0 for future pw
				lowercase = 0;

			if (digit == 0)
				cout << "Password needs to contain at least one digit" << endl;
			else if (digit != 0)																					// sets counter back to 0 for future pw
				digit = 0;	
	} 
	while (strcmp(passw, passw2) != 0);																				// run program while pw don't match
	
	return 0;
}
void EnterP()
{
	cout << "Enter your password: ";
}