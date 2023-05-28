#pragma once

#include "MovingEntity.h"

class Alive : public MovingEntity
{
private:
	int  _iHp;
	bool _bIsAlive;
public:
	Alive();

	Alive(int iID, Vector2f vfPos, ae::Sprite sprSprite, Body bodBody, int iHP);

	int  getHP();
	void setHP(int iNewHP);

	bool IsAlive();
	void IsAlive(bool bState);

	void TakeDammage(int iDammage);

	void show(RenderWindow& window) override;
};