#include "Hero.h"

Hero::Hero()
{
	this->m_Name = "hero";
	this->m_Atk = 30;
	this->m_Def = 50;
	this->m_Hp = 500;
	this->weapon = NULL;
}

void Hero::EquipWeapon(Weapon* weapon)
{
	this->weapon = weapon;
	cout << this->m_Name << " equips with " << weapon->m_WeaponName << endl;
}

void Hero::Attack(Monster* monster)
{
	int damage = 0;
	int addHp = 0;
	bool isFreeze = false;
	bool isCrit = false;
	
	if (this->weapon == NULL)
	{
		damage = this->m_Atk;
	}
	else
	{
		damage = this->m_Atk + this->weapon->getBaseDamage();
		addHp = this->weapon->getLifeSteal();
		isFreeze = this->weapon->getFreeze();
		isCrit = this->weapon->getCrit();
	}
	if (isCrit)
	{
		damage = damage * 2;
		cout << "Critical Attck! Damage Value: " << damage << endl;
	}
	if (isFreeze)
	{
		cout << "Monster is frozen for this round!" << endl;
	}
	if (addHp > 0)
	{
		cout << addHp << " Hp is stolen from monster!" << endl;
	}

	monster->m_Freeze = isFreeze;
	int TrueDamage = (damage - monster->m_Def) > 0 ? damage-monster->m_Def : 1;

	monster->m_Hp -= TrueDamage;

	this->m_Hp += addHp;

	cout << this->m_Name << " attacks " << monster->m_Name << "! Causing "<< damage <<" damage!" << endl;
}
