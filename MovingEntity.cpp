#include "MovingEntity.h"

MovingEntity::MovingEntity()
{
	this->_fMaxSpeed = 0;
	this->_fAcceleration = 0;

	_dmCurentDirection = NULL;
}

MovingEntity::MovingEntity(int iID, Vector2f vfPos, ae::Sprite sprSprite, Body bodBody) :
	Entity(iID, vfPos, sprSprite, bodBody),
	_fMaxSpeed(0),
	_fAcceleration(0) 
{
	_dmCurentDirection = NULL;
};

MovingEntity::~MovingEntity()
{
	delete _dmCurentDirection;
}

void MovingEntity::setMaxSpeed(float fNewMaxSpeed)
{
	this->_fMaxSpeed = fNewMaxSpeed;
}

void MovingEntity::setAcceleration(float fNewAcceleration)
{
	this->_fAcceleration = fNewAcceleration;
}

void MovingEntity::setAngularVelosity(float fNewAngularVelosity)
{
	this->_fAngularVelosity = fNewAngularVelosity;
}

void MovingEntity::setMaxAngularVelosity(float fNewMaxAngularVelosity)
{
	this->_fMaxAngularVelosity = fNewMaxAngularVelosity;
}

void MovingEntity::setAngularAcceleration(float fNewAngularAcceleration)
{
	_fAngularAcceleration = fNewAngularAcceleration;
}



float MovingEntity::getMaxSpeed()
{
	return this->_fMaxSpeed;
}

float MovingEntity::getAcceleration()
{
	return this->_fAcceleration;
}

float MovingEntity::getAngularVelosity()
{
	return _fAngularVelosity;
}

float MovingEntity::getMaxAngularVelosity()
{
	return this->_fMaxAngularVelosity;
}

float MovingEntity::getAngularAcceleration()
{
	return _fAngularAcceleration;;
}



void MovingEntity::MoveSet()
{

};



void MovingEntity::AccelerateClockwise(float fHandlingTime)
{
	if (_fAngularVelosity < _fMaxAngularVelosity)
	{
		_fAngularVelosity += fHandlingTime * _fAngularAcceleration;
	}

	rotate(fHandlingTime * _fAngularVelosity);
}

void MovingEntity::AccelerateCounterclockwise(float fHandlingTime)
{
	if (_fAngularVelosity > -_fMaxAngularVelosity)
	{
		_fAngularVelosity -= fHandlingTime * _fAngularAcceleration;
	}

	rotate(fHandlingTime * _fAngularVelosity);
}

void MovingEntity::RotationSlowDown(float fHandlingTime, int iSlowingCoefficient)
{
	if (_fAngularVelosity > 1)
	{
		_fAngularVelosity -= fHandlingTime * _fAngularAcceleration / iSlowingCoefficient;
	}
	else if (_fAngularVelosity < -1)
	{
		_fAngularVelosity += fHandlingTime * _fAngularAcceleration / iSlowingCoefficient;
	}
	else
	{
		_fAngularVelosity = 0;
	}

	rotate(fHandlingTime * _fAngularVelosity);
}



