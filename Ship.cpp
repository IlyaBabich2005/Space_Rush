#include "Ship.h"

Ship::Ship() 
{
	IsAlive(true);
	setHP(100);
}

Ship::Ship(int iID, Vector2f vfPos, ae::Sprite sprSprite, Body bodBody, int iHP) :
	Alive(iID, vfPos, sprSprite, bodBody, iHP) {};

