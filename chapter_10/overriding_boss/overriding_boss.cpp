// Overriding Boss
// Demonstrates calling and overriding base member functions

#include <iostream>
using namespace std;

class Enemy
{
public:
	Enemy(int damage = 10);
	void virtual Taunt() const; // made virtual to be overriden
	void virtual Attack() const; // made virtual to be overriden
private:
	int m_Damage;
};

Enemy::Enemy(int damage) :
	m_Damage(damage)
{
}

void Enemy::Taunt() const
{
	cout << "The enemy says he will fight you.\n";
}

void Enemy::Attack() const
{
	cout << "Attack! Inflicts " << m_Damage << " damage points.";
}

class Boss : public Enemy
{
public:
	Boss(int damage = 30);
	void Taunt() const override; // optional use of the keyword virtual
	void Attack() const override; // optional use of keyword virtual
};

Boss::Boss(int damage) :
	Enemy(damage) // call base class constructor with argument
{
}

void Boss::Taunt() const // override base class member function
{
	cout << "The boss says he will end your pitiful existence.\n";
}

void Boss::Attack() const // override base class member function
{
	Enemy::Attack(); // call base class member function
	cout << " And laughs heartily at you.\n";
}

int main()
{
	cout << "Enemy object:\n";
	Enemy anEnemy;
	anEnemy.Taunt();
	anEnemy.Attack();

	cout << "\n\nBoss object:\n";
	Boss aBoss;
	aBoss.Taunt();
	aBoss.Attack();

	return 0;
}
