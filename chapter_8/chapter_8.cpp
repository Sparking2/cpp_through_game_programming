// 1.	Improve the Critter Caretaker program so that you can enter an unlisted menu choice that 
//		reveals the exact values of the critter's hunger and boredom levels

// 2.	Change the Critter Caretaker program so that the critter is more expressive about its needs
//		by hinting at how hungry and bored it is

#include <iostream>

using namespace std;

class Critter
{
public:
	Critter(int hunger = 0, int boredom = 0);
	void Talk();
	void Eat(int food = 4);
	void Play(int fun = 4);
	int GetHunger();
	int GetBoredom();

private:
	int m_Hunger;
	int m_Boredom;

	int GetMood() const;
	void Hint();
	void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom) :
	m_Hunger(hunger), m_Boredom(boredom)
{
}

inline int Critter::GetMood() const
{
	return m_Hunger + m_Boredom;
}

void Critter::PassTime(int time)
{
	m_Hunger += time;
	m_Boredom += time;
}

void Critter::Hint()
{
	if (m_Boredom > m_Hunger)
	{
		cout << "I'm too bored...\n";
	}
	else if (m_Hunger > m_Boredom)
	{
		cout << "I'm too hungry..\n";
	}
}


void Critter::Talk()
{
	cout << "I'm a critter and I feel ";
	int mood = GetMood();
	if (mood > 15)
	{
		cout << "mad.\n";
	}
	else if (mood > 10)
	{
		cout << "frustrated.\n";
	}
	else if (mood > 5)
	{
		cout << "oka.\n";
	}
	else
	{
		cout << "happy.\n";
	}

	Hint();

	PassTime();
}

void Critter::Eat(int food)
{
	cout << "Brruppp.\n";
	m_Hunger -= food;
	if (m_Hunger < 0)
	{
		m_Hunger = 0;
	}
	PassTime();
}

void Critter::Play(int fun)
{
	cout << "Whee!\n";
	m_Boredom -= fun;
	if (m_Boredom < 0)
	{
		m_Boredom = 0;
	}
	PassTime();
}

int Critter::GetBoredom()
{
	return m_Boredom;
}

int Critter::GetHunger()
{
	return m_Hunger;
}

int main()
{
	Critter crit;
	crit.Talk();
	int choice;
	do
	{
		cout << "\nCritter Caretaker\n\n";
		cout << "0 - Quit\n";
		cout << "1 - Listen to your critter\n";
		cout << "2 - Feed your critter\n";
		cout << "3 - Play with your critter\n\n";
		cout << "Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "Good-bye.\n";
			break;
		case 1:
			crit.Talk();
			break;
		case 2:
			crit.Eat();
			break;
		case 3:
			crit.Play();
			break;
		case 4:
			cout << "\nThe critter has " << crit.GetHunger() << " hunger, and " << crit.GetBoredom() << " boredom\n";
			break;
		default:
			cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
		}
	}
	while (choice != 0);
	return 0;
}

//	3.	What design problem does the following program have?
//	R: it is defining inside the class? not inlining a simple function?

/*
 *#include <iostream>
 *using namespace std;
 *
 *class Critter
 *{
 *public:
 *	int GetHunger() const {return m_Hunger;}
 *private:
 *	int m_Hunger;
 *};
 *int main()
 *{
 *	Critter crit;
 *	cout << crit.GetHunger() << endl;
 *	return 0;
 *}
 */
