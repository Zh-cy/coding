#ifndef __HERO__
#define __HERO__

#include <iostream>
#include <string>
#include "Weapon.h"
#include "Monster.h"

using namespace std;

class Monster;

class Hero
{
public:
	Hero();
	void EquipWeapon(Weapon * weapon);
	void Attack(Monster * monster);

public:
	string m_Name;
	int m_Atk;
	int m_Def;
	int m_Hp;
	Weapon * weapon;
};

#endif
