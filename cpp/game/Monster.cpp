#include "Monster.h"

Monster::Monster()
{
	this->m_Name = "monster";
	this->m_Hp = 300;
	this->m_Atk = 60;
	this->m_Def = 40;
	this->m_Freeze= false;
}

void Monster::Attack(Hero* hero)
{
	if (this->m_Freeze)
	{
		cout << this->m_Name << "is frozen in this round, cannot attack!" << endl;
		return;
	}
	
	int damage = (this->m_Atk - hero->m_Def) > 0 ? this->m_Atk-hero->m_Def : 1;
	
	hero->m_Hp -= damage;
	cout << this->m_Name << " attacks " << hero->m_Name << "! Causing " << damage << " damage!" << endl;
}
