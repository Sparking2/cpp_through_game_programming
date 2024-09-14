// 1. What's wrong with the following prototype?
// int askNumber(int low=1, int high);
// R:	Whe are setting the default value in the most left element, but it should be in the other side,
//		never write more variables (that aren't default) after a default var

//	2. Rewrite the Hangman game from Chapter 4, "The Standard Template Library: Hangman", using functions.
//		Include a function to get the player's guess and another function to determine whether the player's
//		guess is the secret word.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

string pick_random_word();
void get_result(int, int, string);
void print_state(int, int, string, string);
bool checkGuess(char guess, string used);

int main()
{
	// setup
	constexpr int MAX_WRONG = 8;

	const string THE_WORD = pick_random_word();
	int wrong = 0;
	string soFar(THE_WORD.size(), '-');
	string used = "";

	cout << "Welcome to Hangman. Good luck!\n";

	while (wrong < MAX_WRONG && soFar != THE_WORD)
	{
		print_state(MAX_WRONG, wrong, soFar, used);

		char guess;
		cout << "\n\nEnter your guess: ";
		cin >> guess;
		guess = toupper(guess); // make uppercase since secret word is uppercase
		while (used.find(guess) != string::npos)
		{
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess: ";
			cin >> guess;
			guess = toupper(guess);
		}
		used += guess;
		if (THE_WORD.find(guess) != string::npos)
		{
			cout << "That's right! " << guess << " is in the word.\n";
			// update soFar to include newly guessed letter
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess)
				{
					soFar[i] = guess;
				}
			}
		}
		else
		{
			cout << "Sorry, " << guess << " isn't in the word.\n";
			++wrong;
		}
	}

	get_result(wrong, MAX_WRONG, THE_WORD);
}

string pick_random_word()
{
	vector<string> words;
	words.push_back("GUESS");
	words.push_back("HANGMAN");
	words.push_back("DIFFICULT");

	srand(static_cast<unsigned int>(time(nullptr)));
	random_shuffle(words.begin(), words.end());
	return words[0];
}

void print_state(int max_wrong, int wrong, string soFar, string used)
{
	cout << "\n\nYou have " << max_wrong - wrong;
	cout << " incorrect guesses left. \n";
	cout << "\nYou've used the following letters:\n" << used << endl;
	cout << "\nSo far, the word is:\n" << soFar << endl;
}

void get_result(int wrong, int max_wrong, string word)
{
	if (wrong == max_wrong)
	{
		cout << "\nYou've been hanged!";
	}
	else
	{
		cout << "\nYou guessed it!";
	}
	cout << "\nThe word was " << word << endl;
}

//	3.	Using default arguments, write a function that asks the user for a number and returns that number.
//		The function should accept a string prompt from the calling code. If the caller doesn't supply a string for
//		the prompt, the function should use a generic prompt. Next, using function overloading, write a function that
//		achieves the same result.

int get_number(string prompt = "Enter a number")
{
	int num;
	cout << prompt << "\n";
	cin >> num;
	return num;
}

int get_number()
{
	int num;
	cout << "Enter a number" << "\n";
	cin >> num;
	return num;
}