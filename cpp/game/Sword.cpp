#include "Sword.h"

Sword::Sword()
{
	this->m_BaseDamage = 25;
	this->m_WeaponName = "Sword";
	this->StealRate = 20;
	this->FreezeRate = 30;
	this->CritRate = 35;
}

int Sword::getBaseDamage()
{
	return this->m_BaseDamage;
}

int Sword::getLifeSteal()
{
	if (Trigger(StealRate))
	{
		return this->m_BaseDamage * 0.8;
	}
	return 0;
}

bool Sword::getFreeze()
{
	if (Trigger(FreezeRate))
	{
		return true;
	}
	return false;
}

bool Sword::getCrit()
{
	if (Trigger(CritRate))
	{
		return true;
	}
	return false;
}

bool Sword::Trigger(int rate)
{
	int num = rand() % 100 + 1;
	if (num < rate)
		return true;
	return false;
}
