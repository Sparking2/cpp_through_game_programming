// Polymorphic Bad Guy
// Demonstrates calling member functions dynamically

#include <iostream>

using namespace std;

class Enemy
{
public:
	Enemy(int damage = 10);
	virtual ~Enemy();
	void virtual Attack() const;

protected:
	int* m_pDamage;
};

Enemy::Enemy(int damage)
{
	m_pDamage = new int(damage);
}

Enemy::~Enemy()
{
	cout << "In Enemy destructor, deleting m_pDamage.\n";
	delete m_pDamage;
	m_pDamage = nullptr;
}

void Enemy::Attack() const
{
	cout << "An enemy attacks and inflicts " << *m_pDamage << " damage points.";
}

class Boss : public Enemy
{
public:
	Boss(int multiplier = 3);
	~Boss() override;
	void Attack() const override;

protected:
	int* m_pMultiplier;
};

Boss::Boss(int multiplier)
{
	m_pMultiplier = new int(multiplier);
}

Boss::~Boss()
{
	cout << "In Boss destructor, deleting m_pMultiplier.\n";
	delete m_pMultiplier;
	m_pMultiplier = nullptr;
}

void Boss::Attack() const
{
	cout << "A boss attacks and inflicts " << (*m_pDamage) * (*m_pMultiplier) << " damage points.\n";
}

int main()
{
	cout << "Calling Attack() on Boss object pointer to Enemy:\n";
	Enemy* pBadGuy = new Boss();
	pBadGuy->Attack();
	cout << "\n\nDeleting pointer to Enemy:\n";
	delete pBadGuy;
	pBadGuy = nullptr;

	return 0;
}
