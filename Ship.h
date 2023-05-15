#pragma once

#include "Alive.h"

class Ship : public Alive
{
private:

public:
	Ship();

	Ship(int iID, Vector2f vfPos, ae::Sprite sprSprite, Body bodBody, int iHP);
};