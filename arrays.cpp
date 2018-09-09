/* Name: Franco
Date: 10/24/2017
Section: 1
Assignment: Homework #5
Due Date: Monday, November 6th 11:59:00pm
About this project: This project uses arrays in functions 
Assumptions: Assumes the user will call Fill Array function first so that the array has data in it to begin.

All work below was performed by Franco Marcoccia */


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void PrintArray(const int arr[], const int SIZE);																// functions parameters
void FillArray(int arr[], int SIZE, int min, int max);
void Insert(int arr[], int SIZE, int new_value, int index);
void Delete(int arr[], int SIZE, int index);
void Reverse(int arr[], int SIZE);
int MaxOdd(const int arr[], const int SIZE);
void Menu();
int main()
{
	const int SIZE = 15;																						// established const of array size
	srand((unsigned int)time(0));																				// for random ints
	char menu_selection;																						// variable declarations
	int arr[SIZE];
	int min, max, new_value, index;

	Menu();
	cin >> menu_selection;

	do																											// do while loop to run program under certain selections
	{
		if (menu_selection == 'P' || menu_selection == 'p')
		{
			PrintArray(arr, SIZE);																				// function to print array
			cout << endl;
			cout << "Enter your menu selection: ";
			cin >> menu_selection;
		}
		if (menu_selection == 'F' || menu_selection == 'f')
		{
			cout << "What is the minimum random value? ";
			cin >> min;
			cout << "What is the maximum random value? ";
			cin >> max;
			cout << endl;
			FillArray(arr, SIZE, min, max);																		// function fills the array with ints
			PrintArray(arr, SIZE);
			cout << endl;
			cout << "Enter your menu selection: ";
			cin >> menu_selection;
		}
		if (menu_selection == 'I' || menu_selection == 'i')
		{
			cout << "Enter the value to insert: ";
			cin >> new_value;
			cout << "Enter index at which to insert: ";
			cin >> index;
			cout << endl;
			Insert(arr, SIZE, new_value, index);																// function inserts a value into array, shifting others, while removing last
			PrintArray(arr, SIZE);
			cout << endl;
			cout << "Enter your menu selection: ";
			cin >> menu_selection;
		}
		if (menu_selection == 'D' || menu_selection == 'd')
		{
			cout << "Enter index of item to delete: ";
			cin >> index;
			cout << endl;
			Delete(arr, SIZE, index);																			// function deletes a number from a certain index while shifting over numbers and placing a 0 at the end
			PrintArray(arr, SIZE);
			cout << endl;
			cout << "Enter your menu selection: ";
			cin >> menu_selection;
		}
		if (menu_selection == 'R' || menu_selection == 'r')
		{
			cout << endl;
			Reverse(arr, SIZE);																					// function reverses order of array
			PrintArray(arr, SIZE);
			cout << endl << endl;
			cout << "Enter your menu selection: ";
			cin >> menu_selection;
		}
		if (menu_selection == 'X' || menu_selection == 'x')
		{
			cout << "The maximum odd value is " << MaxOdd(arr,SIZE) << endl << endl;						// function finds the largest odd number of array
			cout << "Enter your menu selection: ";
			cin >> menu_selection;
		}
		if (menu_selection == 'M' || menu_selection == 'm')
		{
			cout << endl;
			Menu();																							// displays menu again
			cin >> menu_selection;
			cout << endl;
		}
	} 
	while (menu_selection == 'P' || menu_selection == 'F' || menu_selection == 'I' || menu_selection == 'D' || menu_selection == 'R' || menu_selection == 'X' || menu_selection == 'M' || menu_selection == 'f' || menu_selection == 'p' || menu_selection == 'i' || menu_selection == 'd' || menu_selection == 'r' || menu_selection == 'x' || menu_selection == 'm');

	if (menu_selection == 'Q' || menu_selection == 'q')
		PrintArray(arr, SIZE);																							// ends program, displaying array

	return 0;
}
void PrintArray(const int arr[], const int SIZE)																	// given by Melina
{
	cout << "\nThe array:\n { ";
	for (int i = 0; i < SIZE - 1; i++)
	cout << arr[i] << ", ";
	cout << arr[SIZE - 1] << " }\n";
}
void FillArray(int arr[], int SIZE, int min, int max)																// takes in user input min/max to fill array by certain numbers
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}
void Insert(int arr[], int SIZE, int new_value, int index)															// uses user inputed values to insert an int
{
	for (int i = SIZE; i > index; i--)
	{
		arr[i] = arr[i - 1];
	}	
	arr[index] = new_value;
}
void Delete(int arr[], int SIZE, int index)																			// uses user inputed index to delete a value from array
{
	for (int i = index; i < SIZE - 1; i++)
		arr[i] = arr[i + 1];

	arr[SIZE - 1] = 0;
}
void Reverse(int arr[], int SIZE)																					// reverses the array depending on size
{
	int temp, i;
	if (SIZE % 2 == 0)
	{
		for (i = 0; i < SIZE / 2; i++)
		{
			temp = arr[SIZE - 1 - i];
			arr[SIZE - 1 - i] = arr[i];
			arr[i] = temp;
		}
	}
	else if (SIZE % 2 != 0)
	{
		for (i = 0; i < (SIZE - 1) / 2; i++)
		{
			temp = arr[SIZE - 1 - i];
			arr[SIZE - 1 - i] = arr[i];
			arr[i] = temp;
		}
	}	
}
int MaxOdd(const int arr[], const int SIZE)																	// finds highest odd number of array
{
	int highestodd = arr[0];
	for (int i = 1; i <= SIZE; i++)
	{
		if (arr[i] % 2 == 1)
		{
			if (arr[i] > highestodd)
				highestodd = arr[i];
		}
	}
	return highestodd;
}
void Menu()																									// displays menu when called
{
	cout << "		** Given features **" << endl;
	cout << "P		Print the array contents" << endl << endl;
	cout <<	"		** Function Tests **" << endl;
	cout << "F		Fill the array with random values" << endl;
	cout << "I		Insert" << endl;
	cout << "D		Delete" << endl;
	cout << "R		Reverse" << endl;
	cout << "X		Max Odd Value" << endl << endl;
	cout << "M		Print this menu" << endl;
	cout << "Q		Quit this program" << endl << endl;
	cout << "Enter your menu selection: ";
}
