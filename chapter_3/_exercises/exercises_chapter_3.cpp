// 1. Improve the Word Jumble game by adding a scoring system. Make the point value for a word
// based on its length. Deduct points if the player asks for a hint.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int points = 0;

	enum fields : int8_t { word, hint, num_fields };
	constexpr int num_words = 5;
	const string words[num_words][num_fields] =
	{
		{"wall", "Do you fell you're banging your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all about."}
	};

	srand(static_cast<unsigned int>(time(nullptr)));
	const int choice = rand() % num_words;
	const string the_word = words[choice][word]; // word to guess
	const string the_hint = words[choice][hint]; // hint for word

	string jumble = the_word; // jumbled version of word
	const int length = static_cast<int>(jumble.size());
	points = length * 3;
	for(int i = 0; i < length; ++i)
	{
		const int index1 = rand() % length;
		const int index2 = rand() % length;
		const char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	cout << "\t\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	cout << "The jumble is: " << jumble;

	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;
	while ((guess != the_word) && (guess != "quit"))
	{
		if (guess == "hint")
		{
			points -= 2;
			cout << the_hint;
		}
		else
		{
			points -= 1;
			cout << "Sorry, that's not it.";
		}
		cout << "\n\nYour guess: ";
		cin >> guess;
	}

	if (guess == the_word)
	{
		cout << "\nThat's it! You guessed it!\n";
		cout << "\nFinal Score: " << points << "\n";
	}
	cout << "\nThanks for playing.\n";

	// 2. What's wrong with the following code? R: is including the end or null of the variable?
	const string phrase = "wtf is going on here?"; 
	for (int i = 0; i <= phrase.size(); ++i)
	{
		cout << "Character at position " << i << " is: " << phrase[i] << "\n";
	}

	// 3. What's wrong with the following code? R: The rows and columns in the initialization are inverted...
	const int ROWS = 2;
	const int COLUMNS = 3;
	char board[COLUMNS][ROWS] = { {'0', 'X', '0'}, {' ', 'X','X'} };


	return 0;

}
