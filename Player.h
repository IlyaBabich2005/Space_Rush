#pragma once

#include "Ship.h"


class Player : public Ship
{
private:
	float _fArmor;
	float _fHyper;
	std::vector<DirectionalMovement> _vmvMovements;
public:
	Player();

	Player(int iID, Vector2f vfPos, ae::Sprite sprSprite, Body bodBody, int iHP);

	std::vector<DirectionalMovement> getMovements();

	void MoveSet() override;

	void KeyboardRotatingMoveSet(float fHandlingTime);
	void KeyboardMotionMoveSet(float fHandlingTime);
};