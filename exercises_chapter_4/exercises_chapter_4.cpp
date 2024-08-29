/*	1. 	Write a program using vectors and iterators that allows a user to maintain a list of
 *		his or her favorite games. The program should allow the user to list all game titles,
 *		add a game title, and remove a game title.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<std::string> game_titles;
vector<string>::iterator my_iterator;
vector<string>::const_iterator iterator_v;

int option = -1;
string game;
int index = -1;

int main()
{
	while (option != 4)
	{
		cout << "\nActions: \n1: Add game title\n2: Remove game title\n3: List game titles\n4: Exit\n\n";
		cin >> option;
		switch (option)
		{
		// Add a game
		case 1:
			cout << "Game: ";
			cin.ignore();
			getline(cin, game);
			game_titles.push_back(game);
			break;
		// Remove a game
		case 2:
			cout << "Please write the index of the game you want to remove: ";
			cin >> option;
			if (option < 0 || option > game_titles.size())
			{
				cout << "Invalid ID\n";
			}
			else
			{
				game_titles.erase(game_titles.begin() + option);
			}
			option = -1;
			break;
		case 3:
			index = 0;
			for (iterator_v = game_titles.begin(); iterator_v != game_titles.end(); ++iterator_v, index++)
			{
				cout << index << ".- ";
				cout << *iterator_v << "\n";
			}
			index = 0;
			break;
		case 4: break;
		default:
			cout << "\nInvalid Action\n";
			option = -1;
			break;
		}
	}

	cout << "Thank you for using this service\n";

	return 0;
}

/*	2. Assuming that ``scores`` is a vector that holds elements of type ``int``, what's wrong with
 *		the following code snippet (meant to increment each element)?
 *	vector<int>::iterator iter;
 *	// increment each score
 *	for (iter = scores.begin(); iter != scores.end(); ++iter)
 *	{
 *		iter++
 *	}
 *	R: 	Because iter is only pointing to the position, when you increase it, it updates the current iterator
 *		not the value that the iterator is pointing towards
 */

/*	3.	Write pseudocode for the Word Jumble game from Chapter 3
 */

// Create list of words for gameplay, include hints
// Randomly pick a word from the list
// Randomize the characters of the word
// While the player hasn't found the word or exited the game
//		Show the menu to the player
//		if hint is written
//			give the player the hint
//		else
//			compare the guess with the word
//	Repeat the while
//	Thank the player for playing
