#ifndef __SWORD__
#define __SWORD__
#include <iostream>
#include <string>
#include "Weapon.h"

class Sword :public Weapon
{
public:
	Sword();
	virtual int getBaseDamage();
	virtual int getLifeSteal();
	virtual bool getFreeze();
	virtual bool getCrit();
public:
	int StealRate;
	int FreezeRate;
	int CritRate;

	bool Trigger(int rate);
};

#endif
