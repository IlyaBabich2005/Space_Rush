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
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		AccelerateForward(fHandlingTime);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		AccelerateBack(fHandlingTime);
	}

	MovingSlowDown(fHandlingTime, 4);



	//move
	move(fHandlingTime * );

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



