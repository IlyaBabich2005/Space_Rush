#include "Player.h"

Player::Player()
{
	_fArmor = 0;
	_fHyper = 1.f;
	setHP(100);
	setMaxAngularVelosity(360);
	setAngularAcceleration(720);
	setMaxSpeed(400);
	setAcceleration(800);

	setTexture(GAME::RES::SHIP::TEXTURES::SHIP_ONE_DEFAULT);
	setBodySize({ 40, 25 });
	setSpriteSize({ 50, 50 });
	setPosition({ 400,400 });
	setOrigin({ 20, 25 });
	setRotation(0);
}

Player::Player(int iID, Vector2f vfPos, ae::Sprite sprSprite, Body bodBody, int iHP) :
	Ship(iID, vfPos, sprSprite, bodBody, iHP) 
{
	_fArmor = 0;
	_fHyper = 1.f;
	setHP(100);
}

std::vector<DirectionalMovement> Player::getMovements()
{
	return _vmvMovements;
}

void Player::MoveSet()
{

}

void Player::KeyboardRotatingMoveSet(float fHandlingTime)
{
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		AccelerateClockwise(fHandlingTime);
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		AccelerateCounterclockwise(fHandlingTime);
	}
	else
	{
		RotationSlowDown(fHandlingTime, 1);
	}
	
}

void Player::KeyboardMotionMoveSet(float fHandlingTime)
{
	DirectionalMovement* vfCurentMovement = NULL;
	bool bIsNewDirection = true,
		 bIsKeyPressed = false;
	Vector2f vfMovement = { 0,0 };
	float fDeltaAngle;

	//check is curent direction exist
	for (int i = 0; i < _vmvMovements.size(); i++)
	{
		if ((int)_vmvMovements[i].getAngle() == (int)getAngle())
		{
			vfCurentMovement = &_vmvMovements[i];
			bIsNewDirection = false;
			break;
		}
	}

	for (int i = 0; i < _vmvMovements.size(); i++)
	{
		vfMovement = vfMovement + (_vmvMovements[i].getDirection() * _vmvMovements[i].getSpeed());
	}

	if (bIsNewDirection)
	{
		this->_vmvMovements.push_back(DirectionalMovement{});
		vfCurentMovement = &_vmvMovements[_vmvMovements.size() - 1];
		vfCurentMovement->setAngle(getAngle());

	}


	//controls
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		bIsKeyPressed = true;

		if (vfCurentMovement->getSpeed() < getMaxSpeed())
		{
			vfCurentMovement->setSpeed(vfCurentMovement->getSpeed() + fHandlingTime * getAcceleration());
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		bIsKeyPressed = true;

		if (vfCurentMovement->getSpeed() > -getMaxSpeed())
			vfCurentMovement->setSpeed(vfCurentMovement->getSpeed() - fHandlingTime * getAcceleration());
	}


	//SlowDown
	for (int i = 0; i < _vmvMovements.size(); i++)
	{
		if (!bIsKeyPressed || (bIsKeyPressed && vfCurentMovement != &_vmvMovements[i]))
		{
			if (abs(_vmvMovements[i].getSpeed()) > 1)
			{
				if (_vmvMovements[i].getSpeed() > 0)
				{
					_vmvMovements[i].setSpeed(_vmvMovements[i].getSpeed() - fHandlingTime * getAcceleration() / 4);
				}
				if (_vmvMovements[i].getSpeed() < 0)
				{
					_vmvMovements[i].setSpeed(_vmvMovements[i].getSpeed() + fHandlingTime * getAcceleration() / 4);
				}
			}
			else
			{
				_vmvMovements.erase(_vmvMovements.begin() + i);
				i--;
				continue;
			}
		}

		vfMovement = vfMovement + (_vmvMovements[i].getDirection() * _vmvMovements[i].getSpeed());
	}


	//move
	move(fHandlingTime * vfMovement);
	if (getPosition().x > 1920)
	{
		setPosition({ 1920, getPosition().y });
	}
	if (getPosition().y > 1080)
	{
		setPosition({ getPosition().x, 1080 });
	}
	if (getPosition().y < 0)
	{
		setPosition({ getPosition().x, 0 });
	}
	if (getPosition().x < 0)
	{
		setPosition({ 0, getPosition().y });
	}
}



