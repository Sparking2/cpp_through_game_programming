// 1. What are the advantages and disadvantages of passing an argument by value?
//	R = One of the main advantages is that is copying the original object, this means anything processed in the function is isolated
//	from the original object, this advantage is also "it's bad" as it requires more resources as is copying the entire object, with big
//	ones is bad

//	2. What are the advantages and disadvantages of passing a reference?
//	R = The main advantage is that is not copying the original object, but is actually referencing it, so is a lot faster. This is also a disadvantage
//	as it means that if I modify the value inside the function, it will be changing the original value

//	3. What are the advantages and disadvantages of passing a constant reference?
//	R = Similar to the reference, it's not copying the value so is fast, but with the caveat that the object can't be modified in any way,
//	making it safe, for some operations that require to only process it.

//	4. What are the advantages and disadvantages of returning a reference?
//	R = as with other references, it's fast than returning an entire object, but the problem is it requires to manage a lot, so you don't send
//	back an object that is going out of scope, making it a null

//	5. Should game AI cheat in order to create a more worthy opponent?
//	R = sometimes, and it depends on the cheat, imaginary mega boosters are awful, but analyze all the options and pick the best play is ok.

//	Improve the Mad Lib game from Chapter 5, "Functions: Mad Lib," by using references to make the program more efficient.
#include <iostream>
#include <string>

using namespace std;

string askText(const string& prompt);
int askNumber(const string& prompt);
void tellStory(const string& name, const string& noun, const int& number, const string& bodyPart, const string& verb);

int main()
{
	cout << "Welcome to Mad Lib.\n\n";
	cout << "Answer the following questions to help create a new story.\n";

	string name = askText("Please enter a name: ");
	string noun = askText("Please enter a plural noun: ");
	int number = askNumber("Please enter a number: ");
	string bodyPart = askText("Please enter a body part: ");
	string verb = askText("Please enter a body part: ");

	tellStory(name, noun, number, bodyPart, verb);

	return 0;
}

string askText(const string& prompt)
{
	string text;
	cout << prompt;
	cin >> text;
	return text;
}

int askNumber(const string& prompt)
{
	int num;
	cout << prompt;
	cin >> num;
	return num;
}

void tellStory(const string& name, const string& noun, const int& number, const string& bodyPart, const string& verb)
{
	cout << "\nHere's your story:\n";
	cout << "The famous explorer ";
	cout << name;
	cout << " had nearly given up a life-long quest to find\n";
	cout << "The Lost City of ";
	cout << noun;
	cout << " when one day, the ";
	cout << noun;
	cout << " found the explorer. \n";
	cout << "Surrounded by ";
	cout << number;
	cout << " " << noun;
	cout << ", a tear came to ";
	cout << name << "'s";
	cout << bodyPart << ".\n";
	cout << "After all this time, the quest was finally over. ";
	cout << "And then, the ";
	cout << noun << "\n";
	cout << "promptly devoured";
	cout << name << ". ";
	cout << "The moral of the story? Be careful what you ";
	cout << verb;
	cout << " for.";
}

//	What's wrong with the following program?
/*
 *	int main()
 *	{
 *		int score;
 *		score = 1000;
 *		float& rScore = score;
 *		return 0
 *	}
 */
//	R: It's mixing types,the references need to be initialized with a value of the same type

//	What's wrong with the following function?
/*
 *	int& plusThree(int number)
 *	{
 *		int threeMore = number + 3;
 *		return threeMore;
 *	}
 */
//	R: Is returning a reference to a variable that is going out of scope...
