/* Name: Franco Marcoccia
Date: 11/29/2017
Section: 1
Assignment: Homework 7
Due Date: Wednesday December 6th, 11:59:59pm
About this project: Uses file inputs and array structures to store NFL team data
Assumptions: Assumes file is in correct format, no trailing whitespace, types and limits described above.

All work below was performed by Franco Marcoccia */

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct teamInfo																											// declared struct with required info
{
	char TeamName[40];
	int wins;
	int losses;
	int playoffs;
	int winlossdiff;
};

void Menu();																											// function for menu
void ViewWL(teamInfo teamInfo2[], int SIZE);																			// functions for various menu choices
void ViewTW(teamInfo teamInfo2[], int SIZE);
void ViewPO(teamInfo teamInfo2[], int SIZE);
void ViewDF(teamInfo teamInfo2[], int SIZE);

int main()
{
	int SIZE, menuoption;																								// declared variables needed and array
	ifstream in;
	char filename[40];

	do																													// do while loop to open file and make sure it exists
	{
		cout << "Please enter the name of the input file." << endl;
		cout << "Filename: ";
		cin >> filename;
		in.open(filename);

		if (!in)
			cout << "That is not a valid file. Try again!" << endl;
	} while (!in);

	in >> SIZE;																											// reads in first number of size
	in.ignore();																										// ignores new line

	teamInfo * teamInfo2 = new teamInfo[SIZE];																			// dynamically creates array

	for (int i = 0; i < SIZE; i++)																						// for loop to store info from file
	{
		in.getline(teamInfo2[i].TeamName, 40, ',');
		in >> teamInfo2[i].wins;
		in.ignore();
		in >> teamInfo2[i].losses;
		in.ignore();
		in >> teamInfo2[i].playoffs;
		in.ignore();
		teamInfo2[i].winlossdiff = teamInfo2[i].wins - teamInfo2[i].losses;
	}
	in.close();																											// closes file

	do																													// do while loop for menu options
	{
		Menu();
		cin >> menuoption;
		cout << endl << endl;
		
		if (menuoption == 1)																							// if statements depending on user choice
			ViewWL(teamInfo2, SIZE);																					// function calls for required info
		else if (menuoption == 2)
			ViewTW(teamInfo2, SIZE);
		else if (menuoption == 3)
			ViewPO(teamInfo2, SIZE);
		else if (menuoption == 4)
			ViewDF(teamInfo2, SIZE);
		else if (menuoption == 5)
			cout << "Didn't do the extra credit" << endl << endl;
		else if (menuoption == 0)
			cout << "Goodbye!" << endl;
		else
			cout << "Invalid Choice." << endl << endl;

	} while (menuoption!=0);																							// while user doesn't exit program

	delete[] teamInfo2;																									// deletes dynamic array
	return 0;
}
void Menu()
{
	cout << "Select one of the following choices: " << endl;
	cout << "\t1 - View team Win/Loss records" << endl;
	cout << "\t2 - Show teams with at least x wins" << endl;
	cout << "\t3 - List teams that made the playoffs" << endl;
	cout << "\t4 - List teams and their win/loss differential" << endl;
	cout << "\t5 - Sort teams by Win/Loss differntial (extra credit)" << endl;
	cout << "\t0 - Exit program" << endl;
	cout << "---------------------------------------------------------------------" << endl;
	cout << "Choice: ";
}
void ViewWL(teamInfo teamInfo2[], int SIZE)
{
	cout << endl;
	cout << "Team W-L:" << endl;
	for (int i = 0; i < SIZE; i++)
		cout << teamInfo2[i].TeamName << " " << teamInfo2[i].wins << "-" << teamInfo2[i].losses << endl;
	cout << endl;
}
void ViewTW(teamInfo teamInfo2[], int SIZE)
{
	int usernum;
	cout << endl;
	cout << "Show teams with at least how many wins? --> ";
	cin >> usernum;
	for (int i = 0; i < SIZE; i++)
	{
		if (teamInfo2[i].wins >= usernum)
			cout << teamInfo2[i].TeamName << endl;
	}
	cout << endl;
}
void ViewPO(teamInfo teamInfo2[], int SIZE)
{
	int count = 0;
	cout << endl;
	cout << "Playoff teams:" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (teamInfo2[i].playoffs == 1)
		{
			cout << teamInfo2[i].TeamName;
			if (count < 3)
				cout << ", ";
			count++;
		}
	}
	cout << endl;
	cout << endl;
}
void ViewDF(teamInfo teamInfo2[], int SIZE)
{
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (teamInfo2[i].wins > teamInfo2[i].losses)
			cout << teamInfo2[i].TeamName << " " << "+" << teamInfo2[i].winlossdiff << endl;
		else if (teamInfo2[i].wins < teamInfo2[i].losses)
			cout << teamInfo2[i].TeamName << " " << teamInfo2[i].winlossdiff << endl;
		else if (teamInfo2[i].wins == teamInfo2[i].losses)
			cout << teamInfo2[i].TeamName << " " << teamInfo2[i].winlossdiff << endl;
	}
	cout << endl;
}

