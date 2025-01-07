// Lost Fortune
// A personalized adventure

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	const int GOLD_PIECES = 900;
	int adventurers, killed, survivors;
	string leader;

	// get the information
	cout << "Welcome to Lost Fortune\n\n";
	cout << "Please enter the following for your personalized adventure\n";
	cout << "Enter a number: ";
	cin >> adventurers;
	cout << "Enter a number, smaller than the first: ";
	cin >> killed;
	survivors = adventurers - killed;
	cout << "Enter your las name: ";
	cin >> leader;

	// Tell the story
	cout << "\nA brave group of " << adventurers << " set out on a quest ";
	cout << "-- in search of the lost treasure of the Ancient Dwarves.";
	cout << "The group was led by that legendary rogue, " << leader << ".\n";
	cout << "\nAlong the way, a band of marauding ogres ambushed the party. ";
	cout << "All fought bravely under the command of " << leader;
	cout << ", and the ogres were defeated, but at a cost. ";
	cout << "Of the adventurers, " << killed << " were vanquished, ";
	cout << "leaving just " << survivors << " in the group.\n";

	cout << "\nThe party was about to give up all hope. ";
	cout << "But while laying the deceased to rest, ";
	cout << "they stumbled upon the buried fortune. ";
	cout << "So the adventurers split " << GOLD_PIECES << " gold pieces.";
	cout << leader << " held on to the extra " << (GOLD_PIECES % survivors);
	cout << " pieces to keep things fair of course.\n";

	return 0;
}

// Exercises
// 1.1 - Good names
// 1.2 - Bad names
// 2.0 - What is the result?
// cout << "Seven divided by three is " << 7 / 3 << endl; ======== Prints 2, both are integers so the decimals are omitted doing an integer operation.
// cout << "Seven divided by three is " << 7.0 / 3 << endl; ====== Prints 2.333333, one of the numbers is a floating point, so a floating point operation is made
// cout << "Seven divided by three is " << 7.0 / 3.0 << endl; ==== Same as previous, both are floating point, so no discard is made.
// 3.0 - Average Score
/*
int main()
{
	float grade_a, grade_b, grade_c;
	cout << "Write the first grade: \n";
	cin >> grade_a;
	cout << "Write the second grade: \n";
	cin >> grade_b;
	cout << "Write the third grade: \n";
	cin >> grade_c;
	cout << "The Average grade is: " << (grade_a + grade_b + grade_c) / 3 << "\n";
	return 0;
}
*/
