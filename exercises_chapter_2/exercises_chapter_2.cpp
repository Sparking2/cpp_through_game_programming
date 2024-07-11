// 1. Rewrite the Menu Chooser program using an enumeration to represent difficulty levels. The variable choice will still be of type int.

#include <iostream>
using namespace std;

int enumMenuChooser()
{
	enum difficulty
	{
		easy,
		normal,
		hard,
	};

	int choice;

	cout << "Difficulty Levels\n\n";
	cout << "1 - Easy\n";
	cout << "2 - Normal\n";
	cout << "3 - Hard\n\n";

	cout << "Choice: ";
	cin >> choice;
	switch (static_cast<difficulty>(choice))
	{
	case easy:
		cout << "You picked Easy.\n";
		break;
	case normal:
		cout << "You picked Normal.\n";
		break;
	case hard:
		cout << "You picked Hard.\n";
		break;
	default:
		cout << "You made an illegal choice";
	}
	return 0;
}

// 2. What's wrong with the following loop?

/*
	int x = 0;
	while (x){
		++x;
		cout << x << endl;
	}
*/

// R: The while evaluates to false since the start, as a 0 can also be used for false values;

// 3. Write a new version of the Guess My Number program in which the player and the computer switch roles. That is, the player picks a number and the computer must guess what it is.

int reverseGuessMyNumber()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	int tries = 0;
	int option;
	int guess = rand() % 100 + 1;

	int min = 0;
	int max = 100;

	cout << "\tWelcome to a game where I guess your Number\n\n";
	cout << "Pick a number from 1 - 100 and I'll guess it\n\n";

	do
	{
		cout << "Is " << guess << " your number?\n";
		cout << "\n1.- Too low!\n2.- Too High\n3.- That's it! You got it\n";
		cin >> option;
		switch (option)
		{
		case 1:
			min = guess;
			tries++;
			break;
		case 2:
			max = guess;
			tries++;
			break;
		case 3:
			break;
		default:
			cout << "Hey! that's not a valid option! \n";
		}

		guess = min + (rand() % (max - min + 1));
	}
	while (option != 3);

	cout << "Nice I got it in " << tries << " guesses";

	return 0;
}

// Main Program...

int main()
{
	reverseGuessMyNumber();
	enumMenuChooser();

	return 0;
}
