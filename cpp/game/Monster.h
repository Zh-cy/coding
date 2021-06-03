#ifndef __MONSTER__
#define __MONSTER__

#include <iostream>
#include <string>
#include "Weapon.h"
#include "Hero.h"

using namespace std;

class Hero;

class Monster
{
public:
	Monster();
	void Attack(Hero* hero);

public:
	string m_Name;
	int m_Hp;
	int m_Atk;
	int m_Def;
	bool m_Freeze;
};


#endif
