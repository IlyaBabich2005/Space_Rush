#include "Sprite.h"

ae::Sprite::Sprite()
{
	_rsContainer.setSize({ 200,200 });

	_rsContainer.setOrigin(Math::GetRectangleCentre(_rsContainer));

	_tTexture = new sf::Texture;
	_tTexture->loadFromFile(SYSTEM::RES::TEXTURES::NO_TEXTURE);

	_rsContainer.setTexture(_tTexture);
}

ae::Sprite::Sprite(sf::RectangleShape rsShape, std::string sPathToTexture)
{
	_rsContainer = rsShape;
	_rsContainer.setOrigin(Math::GetRectangleCentre(_rsContainer));

	_tTexture = new sf::Texture;
	if (!_tTexture->loadFromFile(sPathToTexture))
	{
		_tTexture->loadFromFile(SYSTEM::RES::TEXTURES::NO_TEXTURE);
	}

	_rsContainer.setTexture(_tTexture, true);
}

ae::Sprite::Sprite(Sprite& sprSourceSprite)
{
	_tTexture = new sf::Texture;

	*this->_tTexture = sprSourceSprite.getTexture();
	this->_rsContainer = sprSourceSprite.getContainer();

	_rsContainer.setOrigin(Math::GetRectangleCentre(_rsContainer));
}

sf::RectangleShape ae::Sprite::getContainer()
{
	return _rsContainer;
}

void ae::Sprite::setContainer(sf::RectangleShape rsNewContainer)
{
	_rsContainer = rsNewContainer;
}

sf::Texture ae::Sprite::getTexture()
{
	return *_tTexture;
}

void ae::Sprite::setTexture(sf::Texture tNewTexture)
{
	*_tTexture = tNewTexture;
}

void ae::Sprite::setTexture(std::string sNewTexturePath)
{
	if (!_tTexture->loadFromFile(sNewTexturePath))
	{
		_tTexture->loadFromFile(sNewTexturePath);
	}

	_rsContainer.setTexture(_tTexture, true);
}

void ae::Sprite::setPosition(sf::Vector2f vfNewPosition)
{
	_rsContainer.setPosition(vfNewPosition);
	//_rsContainer.setOrigin(_rsContainer.getOrigin() + vfNewPosition);
}

void ae::Sprite::setSize(sf::Vector2f vfNewSize)
{
	_rsContainer.setSize(vfNewSize);
	_rsContainer.setOrigin(Math::GetRectangleCentre(_rsContainer));
}

void ae::Sprite::setOrigin(sf::Vector2f vfNewOrigin)
{
	_rsContainer.setOrigin(vfNewOrigin.x, vfNewOrigin.y);
}

void ae::Sprite::setRotation(float fAngle)
{
	_rsContainer.setRotation(fAngle);
}



void ae::Sprite::rotate(float fAngle)
{
	_rsContainer.rotate(fAngle);
}

void ae::Sprite::move(Vector2f vfDirection)
{
	this->_rsContainer.move(vfDirection);
}

void ae::Sprite::moveOrigin(Vector2f vfMovement)
{
	_rsContainer.setOrigin(_rsContainer.getOrigin() + vfMovement);
}