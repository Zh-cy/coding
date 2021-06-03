#ifndef __WEAPON__
#define __WEAPON__
#include <iostream>
#include <string> 
using namespace std;

class Weapon
{
public:
	virtual int getBaseDamage()=0;
	virtual int getLifeSteal()=0;
	virtual bool getFreeze()=0;
	virtual bool getCrit()=0;

	string m_WeaponName;
	int m_BaseDamage;
};

#endif
