#include "Entity.h"

Entity::Entity()
{
	_bodBody = new Body;
	_sprSprite = new ae::Sprite;

	_iID = 0;

	_sprSprite->setPosition({ 200 , 500 });
	_bodBody->setPosition({ 200 , 500 });
}

Entity::Entity(int iID, Vector2f vfPos, ae::Sprite sprSprite, Body bodBody)
{
	_bodBody = new Body;
	_sprSprite = new ae::Sprite;

	_iID = iID;
	*_sprSprite = sprSprite;
	*_bodBody = bodBody;

	_sprSprite->setPosition(vfPos);
	_bodBody->setPosition(vfPos);
}

Entity::Entity(Entity& eSourceEntity)
{
	this->_iID = eSourceEntity._iID;
	this->_sprSprite = eSourceEntity._sprSprite;
	this->_bodBody = eSourceEntity._bodBody;
}

Entity::~Entity()
{
	delete _bodBody;
	delete _sprSprite;
}



void Entity::setID(int iNewID)
{
	_iID = iNewID;
}

void Entity::setPosition(Vector2f vfNewPosition)
{
	this->_bodBody->setPosition(vfNewPosition);
	this->_sprSprite->setPosition(vfNewPosition);
}

void Entity::setSprite(ae::Sprite sprNewSprite)
{
	*this->_sprSprite = sprNewSprite;
}

void Entity::setTexture(std::string sTexturePath)
{
	this->_sprSprite->setTexture(sTexturePath);
}

void Entity::setBody(Body bodNewBody)
{
	*this->_bodBody = bodNewBody;
}

void Entity::setSpriteSize(Vector2f vfNewSize)
{
	_sprSprite->setSize(vfNewSize);
}

void Entity::setBodySize(Vector2f vfNewSize)
{
	_bodBody->setSize(vfNewSize);
}

void Entity::setOrigin(Vector2f vfNewOrigin)
{
	_sprSprite->setOrigin(vfNewOrigin);

	vfNewOrigin.x -= (_sprSprite->getContainer().getSize().x - _bodBody->getShape().getSize().x) / 2;
	vfNewOrigin.y -= (_sprSprite->getContainer().getSize().y - _bodBody->getShape().getSize().y) / 2;
	_bodBody->setOrigin(vfNewOrigin);
}

void Entity::setRotation(float fAngle)
{
	_bodBody->setRotation(fAngle);
	_sprSprite->setRotation(fAngle);
}



int Entity::getID()
{
	return _iID;
}

Vector2f Entity::getPosition()
{
	return this->getBody()->getShape().getPosition();
}

ae::Sprite* Entity::getSprite()
{
	return this->_sprSprite;
}

Body* Entity::getBody()
{
	return this->_bodBody;
}

float Entity::getAngle()
{
	return _bodBody->getShape().getRotation();
}



void Entity::rotate(float fAngle)
{
	_bodBody->rotate(fAngle);
	_sprSprite->rotate(fAngle);
}

void Entity::move(Vector2f vfDirection)
{
	_bodBody->move(vfDirection);
	_sprSprite->move(vfDirection);
}

void Entity::moveOrigin(Vector2f vfMovement)
{
	_bodBody->moveOrigin(vfMovement);
	_sprSprite->moveOrigin(vfMovement);
}



void Entity::show(RenderWindow& window)
{
	window.draw(_sprSprite->getContainer());

#ifdef  SHOW_HITBOXES

	window.draw(_bodBody->getShape());

#endif //  SHOW_HITBOXES

}

