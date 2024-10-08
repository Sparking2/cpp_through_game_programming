// 1. Write a program with a pointer to a pointer to a string object. Use the pointer to the pointer to call the size()
//	member function of the string object

#include <iostream>
#include <string>

void one()
{
	std::string myString = "Hello World!";
	std::string* pMyString = &myString;
	std::string** pMyPointerToPointerString = &pMyString;

	std::cout << "String size: " << (*pMyPointerToPointerString)->size();

}

// 2. Rewrite the Mad Lib Game project from Chapter 5, "Functions: Mad Lib", so that no string objects are passed to  the function
//	that tells the story. Instead, the function should accept pointers to string objects.

std::string askText(std::string prompt)
{
	std::string text;
	std::cout << prompt;
	std::cin >> text;
	return text;
}

int askNumber(std::string prompt)
{
	int num;
	std::cout << prompt;
	std::cin >> num;
	return num;
}

void tellStory(std::string* name, std::string* noun, int number, std::string* bodyPart, std::string* verb)
{
	std::cout << "\nHere's your story:\n";
	std::cout << "The famous explorer ";
	std::cout << *name;
	std::cout << " had nearly given up a life-long quest to find\n";
	std::cout << "The Lost City of ";
	std::cout << *noun;
	std::cout << " when one day, the ";
	std::cout << *noun;
	std::cout << " found the explorer. \n";
	std::cout << "Surrounded by ";
	std::cout << number;
	std::cout << " " << *noun;
	std::cout << ", a tear came to ";
	std::cout << *name << "'s";
	std::cout << *bodyPart << ".\n";
	std::cout << "After all this time, the quest was finally over. ";
	std::cout << "And then, the ";
	std::cout << *noun << "\n";
	std::cout << "promptly devoured";
	std::cout << *name << ". ";
	std::cout << "The moral of the story? Be careful what you ";
	std::cout << *verb;
	std::cout << " for.";
}

void two()
{
	std::cout << "Welcome to Mad Lib.\n\n";
	std::cout << "Answer the following questions to help create a new story.\n";

	std::string name = askText("Please enter a name: ");
	std::string noun = askText("Please enter a plural noun: ");
	int number = askNumber("Please enter a number: ");
	std::string bodyPart = askText("Please enter a body part: ");
	std::string verb = askText("Please enter a body part: ");

	tellStory(&name, &noun, number, &bodyPart, &verb);
}

// 3. Will the three memory addresses displayed by the following program all be the same?
//	Explain what's going on in the code.

/*
 *	#include <iostream>
 *	using namespace std;
 *
 *	int main()
 *	{
 *		int a = 10;
 *		int& b = a;
 *		int* c = &b;
 *
 *		cout << &a << endl;
 *		cout << &b << endl;
 *		cout << &(*c) << endl;
 *
 *		return 0;
 *	}
 *	Yes? it does because all the elements are doing reference and pointing to the same original spot in memory [a]
 *
 */


int main()
{
	one();
	two();

	int a = 10;
	int& b = a;
	int* c = &b;

	std::cout << &a << std::endl;
	std::cout << &b << std::endl;
	std::cout << &(*c) << std::endl;
}
