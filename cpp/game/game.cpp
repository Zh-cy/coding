#include <iostream>
#include "Weapon.h"
#include "Knife.h"
#include "Sword.h"
#include "Hero.h"
#include "Monster.h"

using namespace std;

void play()
{
	Monster* monster = new Monster;
	Hero* hero = new Hero;
	Weapon* knife = new Knife;
	Weapon* sword = new Sword;

	cout << "Select one weapon: " << endl;
	cout << "1. fight with hands" << endl;
	cout << "2. knife" << endl;
	cout << "3. sword" << endl;

	int selection;
	cin >> selection;
	switch(selection)
	{
		case 1:
			cout << "No weapon is selected!" << endl;
			break;
		case 2:
			hero->EquipWeapon(knife);
			break;
		case 3:
			hero->EquipWeapon(sword);
			break;
	}

	getchar();

	int round = 1;

	while (true)
	{
		getchar();
		cout << "---------round " << round << "---------" << endl;
		if (hero->m_Hp <= 0)
		{
			cout << "You lose!" << endl;
			break;
		}
		hero->Attack(monster);
		if (monster->m_Hp <= 0)
		{
			cout << "You win!" << endl;
			break;
		}
		monster->Attack(hero);
		if (hero->m_Hp <= 0)
		{
			cout << "You lose!" << endl;
			break;
		}

		cout << "Hero Hp: " << hero->m_Hp << endl;
		cout << "Monster Hp: " << monster->m_Hp << endl;
		++round;
	}
	delete monster;
	delete hero;
	delete knife;
	delete sword;
}


int main()
{
	play();
	return 0;	
}
