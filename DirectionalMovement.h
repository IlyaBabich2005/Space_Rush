#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Math.h"

using namespace sf;

class DirectionalMovement
{
private:
	float _fAngle;
	float _fSpeed;
	Vector2f _vfDirection;

public:
	DirectionalMovement();

	DirectionalMovement(float fAngle, float fSpeed);

	void setAngle(float fNewAngle);
	void setSpeed(float fNewSpeed);
	void setDirection(Vector2f vfNewDirection);

	float getAngle();
	float getSpeed();
	Vector2f getDirection();

	Vector2f operator+(const DirectionalMovement& other) const;
};