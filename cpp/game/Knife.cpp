#include "Knife.h"

Knife::Knife()
{
	this->m_BaseDamage = 20;
	this->m_WeaponName = "knife";
}

int Knife::getBaseDamage()
{
	return this->m_BaseDamage;
}

int Knife::getLifeSteal()
{
	return 0;
}

bool Knife::getFreeze()
{
	return false;
}

bool Knife::getCrit()
{
	return false;
}
