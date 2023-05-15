#include "DirectionalMovement.h"

DirectionalMovement::DirectionalMovement()
{
	_fAngle = 0;
	_fSpeed = 0;
	_vfDirection = { 0,0 };
}

DirectionalMovement::DirectionalMovement(float fAngle, float fSpeed)
{
	_fAngle = fAngle;
	_fSpeed = fSpeed;
	_vfDirection = Math::ExpendVector(_fAngle);
}



void DirectionalMovement::setAngle(float fNewAngle)
{
	_fAngle = fNewAngle;
	setDirection(Math::ExpendVector(_fAngle));
}

void DirectionalMovement::setSpeed(float fNewSpeed)
{
	_fSpeed = fNewSpeed;
}

void DirectionalMovement::setDirection(Vector2f vfNewDirection)
{
	_vfDirection = vfNewDirection;
}



float DirectionalMovement::getAngle()
{
	return _fAngle;
}

float DirectionalMovement::getSpeed()
{
	return _fSpeed;
}

Vector2f DirectionalMovement::getDirection()
{
	return _vfDirection;
}

Vector2f DirectionalMovement::operator+(const DirectionalMovement& other) const
{
	return _vfDirection + other._vfDirection;
}


