#pragma once
#include <iostream>
#include "Body.h"
#include "Move.h"
#include "Sprite.h"
//#include "Debug.h"

#define SHOW_DEBUG

class Entity 
{
private:
	int		    _iID;
	ae::Sprite* _sprSprite;
	Body*	    _bodBody;

public:
	Entity();

	Entity(int iID, Vector2f vfPos, ae::Sprite sprSprite, Body bodBody);

	Entity(Entity& eSourceEntity);

	~Entity();
	
	void		 setID(int iNewID);
	void		 setPosition(Vector2f vfNewPosition);
	void		 setSprite(ae::Sprite sprNewSprite);
	void		 setTexture(std::string sTexturePath);
	void		 setBody(Body bodNewBody);
	void		 setSpriteSize(Vector2f vfNewSize);
	void		 setBodySize(Vector2f vfNewSize);
	virtual void setOrigin(Vector2f vfNewOrigin);
	void		 setRotation(float fAngle);
	
	int			 getID();
	Vector2f	 getPosition();
	ae::Sprite*  getSprite();
	Body*		 getBody();
	float		 getAngle();

	void		 rotate(float fAngle);
	void		 move(Vector2f vfDirection);
	void		 moveOrigin(Vector2f vfMovement);

	virtual void show(RenderWindow& window);
};