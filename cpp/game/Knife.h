#ifndef __KNIFE__
#define __KNIFE__
#include <iostream>
#include "Weapon.h"
#include <string>

class Knife :public Weapon
{
public:
	Knife();
	virtual int getBaseDamage();
	virtual int getLifeSteal();
	virtual bool getFreeze();
	virtual bool getCrit();
};

#endif
