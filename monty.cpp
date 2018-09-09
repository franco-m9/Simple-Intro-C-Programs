/* Name: Franco Marcoccia
Date: 10/11/2017
Section: 1
Assignment: Homework 4
Due Date: Friday October 20th, 11:59:00pm
About this project: This project uses functions, loops, and random number generation to act out the monty hall game.
Assumptions: Assumes user will input a door 1-3, assumes menu option will be a number.

All work below was performed by Franco Marcoccia */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

void printDoors();																						// function declarations
int WinningDoor();
void Statistics(double,double,double);
void Menu();
int main()
{
	int menuinput, userchoice, finaldoor, winningdoor;													// variable declarations
	double gamesplayed, wins, losses;												
	gamesplayed = wins = losses = 0;
	double winperc, lossperc;
	srand((unsigned int)time(0));																		// randomization using time

	cout << "Welcome to the Monty Hall Let's Make a Deal Simulator!" << endl << endl;

	do																									// do while statement for entire game
	{
		

		Menu();
		cin >> menuinput;

		while (menuinput < 1 || menuinput > 4)															// while loop incase user doesn't input 1-4
		{
			cout << "Invalid options, please retry > ";
			cin >> menuinput;
		}

			if (menuinput == 1)																			// if input is 1, run game
			{
				winningdoor = WinningDoor();															// sets winning door randomly
				cout << "Pick a Door, 1, 2, or 3!" << endl << endl;
				printDoors();																			// function to print doors
				cout << endl << endl;
				cout << "Choice > ";
				cin >> userchoice;

				int removeddoor = rand() % 3 + 1, otherdoor = rand() % 3 + 1;
				cout << "You chose door #" << userchoice << "!" << endl;
				cout << "I'll now open a door for you randomly that you didn't choose!" << endl;
				cout << "Opening door #" << removeddoor << " and it's a GOAT!" << endl;
				cout << "Now I'll be a kind host and give you the chance to switch your door!" << endl;
				cout << "Would you like door #" << userchoice << " or #" << otherdoor << "? > ";
				cin >> finaldoor;
				cout << "Opening door #" << finaldoor << "....." << endl;
				if (finaldoor == winningdoor)															// used if user wins
				{
					cout << "it's a BRAND NEW CAR!!!! YOU WIN!!!!" << endl << endl;
					wins++;																				// adds wins to counter if user won
				}
				else
				{
					cout << "baaaaaaaaaaaaa.... it's a GOAT!!!! You LOSE!" << endl << endl;				// used if user lost
					losses++;																			// adds loss to counter if user lost
				}
				gamesplayed++;																			// adds gamesplayed counter every game
			}
			else if (menuinput == 2)
			{
				Statistics(wins,losses,gamesplayed);													// function to display statistics if input is 2
			}
			else if (menuinput == 3)																	// resets counters if input is 3 
			{
				cout << "... Statistics Reset!" << endl << endl << endl;
				gamesplayed = wins = losses = 0;
			}
			else if (menuinput == 4)																	// ends program if input is 4
				cout << "Goodbye!" << endl;
		}
		while (menuinput == 1 || menuinput == 2 || menuinput == 3);


		return 0;
	}
	void printDoors()												/*ASCII Art doors*/
																	/*THIS FUNCTION PRINTDOORS IS PROVIDED (graciously by ascii artist Melina) by the student wherever needed.*/
	{
		cout << "---------    ---------    ---------- \n";
		cout << "|       |    |  ____ |    |  _____ | \n";
		cout << "|   |   |    |     | |    |      | | \n";
		cout << "|   |   |    |  ___| |    |   ___| | \n";
		cout << "|   |   |    | |     |    |      | | \n";
		cout << "|   |   |    | |____ |    |  ____| | \n";
		cout << "---------    ---------    ---------- \n";

		return;
	}
	void Menu()																// function to display menu
	{
		cout << "Choose one of the Following:" << endl;
		cout << "1 Play the Game" << endl;
		cout << "2 See Stats" << endl;
		cout << "3 Reset Stats" << endl;
		cout << "4 Quit" << endl;
		cout << "> ";
	}
	int WinningDoor()														// function that randomizes winning door
	{
		int winningdoor = rand() % 3 + 1;
		return winningdoor;
	}
	void Statistics(double wins,double losses, double gamesplayed)						// function to display statistics of the player
	{
		double winperc, lossperc;
		if (gamesplayed == 0)
			cout << "No Stats to Display, 0 games played." << endl << endl << endl;
		else
		{
			cout << "Results after " << gamesplayed << "games:" << endl;
			cout << "Wins: " << wins << "			Losses: " << losses << endl;
			cout << fixed << showpoint << setprecision(1);
			winperc = (wins / gamesplayed) * 100;
			lossperc = (losses / gamesplayed) * 100;
			cout << "Win %: " << winperc << "			Loss %: " << lossperc << endl;
		}
	}