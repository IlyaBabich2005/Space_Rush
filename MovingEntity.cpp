#include "MovingEntity.h"

MovingEntity::MovingEntity()
{
	this->_fMaxSpeed = 0;
	this->_fAcceleration = 0;

	_dmCurentMovement = NULL;
}

MovingEntity::MovingEntity(int iID, Vector2f vfPos, ae::Sprite sprSprite, Body bodBody) :
	Entity(iID, vfPos, sprSprite, bodBody),
	_fMaxSpeed(0),
	_fAcceleration(0) 
{
	_dmCurentMovement = NULL;
};

MovingEntity::~MovingEntity()
{
	if(_dmCurentMovement)
	delete _dmCurentMovement;
}

void MovingEntity::IsAccelerated(bool bIsAccelerated)
{
	this->_bIsAccelerated = bIsAccelerated;
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

void MovingEntity::setMovements(std::vector<DirectionalMovement> vdmNewMovements)
{
	this->_vdmMovements = vdmNewMovements;
}

void MovingEntity::setMaxAngularVelosity(float fNewMaxAngularVelosity)
{
	this->_fMaxAngularVelosity = fNewMaxAngularVelosity;
}

void MovingEntity::setResultingMovement(DirectionalMovement dmCurentDirection)
{
	this->_dmCurentMovement = &dmCurentDirection;
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

bool MovingEntity::IsAccelerated()
{
	return this->_bIsAccelerated;
}

float MovingEntity::getMaxAngularVelosity()
{
	return this->_fMaxAngularVelosity;
}

std::vector<DirectionalMovement> MovingEntity::getMovements()
{
	return this->_vdmMovements;
}

float MovingEntity::getAngularAcceleration()
{
	return _fAngularAcceleration;;
}



void MovingEntity::MoveSet()
{

}



void MovingEntity::AccelerateClockwise(float fHandlingTime)
{
	float FRAME_ANGULAR_ACCELERATION = fHandlingTime * this->_fAngularAcceleration;
	float ROTATION_ANGLE = 0.f;

	if (this->_fAngularVelosity < this->_fMaxAngularVelosity)
	{
		this->_fAngularVelosity += FRAME_ANGULAR_ACCELERATION;
	}

	ROTATION_ANGLE = fHandlingTime * _fAngularVelosity;

	rotate(ROTATION_ANGLE);
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



void MovingEntity::SetCurentMovement()
{
	const int NUM_OF_MOVEMENTS = _vdmMovements.size();
	int CURRENT_ANGLE = this->getAngle();
	bool IS_NEW_MOVEMENT = true;

	for (int MOVEMENT_INDEX = 0; MOVEMENT_INDEX < NUM_OF_MOVEMENTS; MOVEMENT_INDEX++)
	{
		auto  MOVEMENT = &_vdmMovements[MOVEMENT_INDEX];
		int	  MOVEMENT_ANGLE = MOVEMENT->getAngle();

		if (MOVEMENT_ANGLE == CURRENT_ANGLE)
		{
			this->_dmCurentMovement = MOVEMENT;
			IS_NEW_MOVEMENT = false;
			break;
		}
	}

	if (IS_NEW_MOVEMENT)
	{
		this->_vdmMovements.push_back(DirectionalMovement{});
		this->_dmCurentMovement = &this->_vdmMovements.back();
		this->_dmCurentMovement->setAngle(CURRENT_ANGLE);
	}
}

void MovingEntity::AccelerateForward(float fHandlingTime)
{
	const float FRAME_ACELERATION = fHandlingTime * this->_fAcceleration;
	const float CURRENT_SPEED = _dmCurentMovement->getSpeed();
	const float NEW_SPEED = CURRENT_SPEED + FRAME_ACELERATION;

	if (_dmCurentMovement->getSpeed() < _fMaxSpeed)
	{
		_dmCurentMovement->setSpeed(NEW_SPEED);
	}

	this->_bIsAccelerated = true;
}

void MovingEntity::AccelerateBack(float fHandlingTime)
{
	const float FRAME_ACELERATION = fHandlingTime * this->_fAcceleration;
	const float CURRENT_SPEED = _dmCurentMovement->getSpeed();
	const float NEW_SPEED = CURRENT_SPEED - FRAME_ACELERATION;

	if (_dmCurentMovement->getSpeed() > -_fMaxSpeed)
	{
		_dmCurentMovement->setSpeed(NEW_SPEED);
	}

	this->_bIsAccelerated = true;
}

void MovingEntity::MovingSlowDown(float fHandlingTime, int iSlowingCoefficient)
{
	const float FRAME_DECCELERATION_RATE = fHandlingTime * this->_fAcceleration / iSlowingCoefficient;

	for (int i = 0; i < this->_vdmMovements.size(); i++)
	{
		if (!this->_bIsAccelerated or (this->_bIsAccelerated and this->_dmCurentMovement != &this->_vdmMovements[i]))
		{
			if (abs(_vdmMovements[i].getSpeed()) > 1)
			{
				if (_vdmMovements[i].getSpeed() > 0)
				{
					_vdmMovements[i].setSpeed(_vdmMovements[i].getSpeed() - FRAME_DECCELERATION_RATE);
				}
				if (_vdmMovements[i].getSpeed() < 0)
				{
					_vdmMovements[i].setSpeed(_vdmMovements[i].getSpeed() + FRAME_DECCELERATION_RATE);
				}
			}
			else
			{
				_vdmMovements.erase(_vdmMovements.begin() + i);
				i--;
				continue;
			}
		}
	}
}

void MovingEntity::CalculateResultingMovement(float fHandlingTime)
{
	const int NUM_OF_MOVEMENTS = this->_vdmMovements.size();

	for (int MOVEMENT_INDEX = 0; MOVEMENT_INDEX < NUM_OF_MOVEMENTS; MOVEMENT_INDEX++)
	{
		

		
	}
}