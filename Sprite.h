#pragma once
#include "Math.h"
#include "Paths.h"

namespace ae
{
	class Sprite
	{
	private:
		sf::RectangleShape _rsContainer;
		sf::Texture*		  _tTexture;
	public:
		Sprite();

		Sprite(sf::RectangleShape rsShape, std::string sPathToTexture);

		Sprite(Sprite& sprSourceSprite);

		sf::RectangleShape getContainer();
		void setContainer(sf::RectangleShape rsNewContainer);

		sf::Texture getTexture();
		void setTexture(sf::Texture tNewTexture);
		void setTexture(std::string sNewTexturePath);

		void setPosition(sf::Vector2f vfNewPosition);
		void setSize(sf::Vector2f vfNewSize);
		void setOrigin(sf::Vector2f vfNewOrigin);
		void setRotation(float fAngle);

		void rotate(float fAngle);
		void move(Vector2f vfDirection);
		void moveOrigin(Vector2f vfMovement);
	};

}

