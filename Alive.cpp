#include "Alive.h"

Alive::Alive()
{
	_iHp = 0;
	_bIsAlive = false;
}

Alive::Alive(int iID, Vector2f vfPos, ae::Sprite sprSprite, Body bodBody, int iHP) :
	MovingEntity(iID, vfPos, sprSprite, bodBody), _iHp(iHP)
{
	if (_iHp > 0)
	{
		_bIsAlive = true;
	}
};

int Alive::getHP()
{
	return _iHp;
}

void Alive::setHP(int iNewHP)
{
	_iHp = iNewHP;

	if (_iHp <= 0)
	{
		_bIsAlive = false;
	}
	else
	{
		_bIsAlive = true;
	}
}

bool Alive::IsAlive()
{
	return _bIsAlive;
}

void Alive::IsAlive(bool bState)
{
	_bIsAlive = bState;
}

void Alive::TakeDammage(int iDammage)
{
	_iHp -= iDammage;

	if (_iHp <= 0)
	{
		_bIsAlive = false;
	}
}

void Alive::show(RenderWindow& window) 
{
	if (IsAlive())
	{
		Entity::show(window);
	}
};

