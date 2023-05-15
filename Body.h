#pragma once
#include "Math.h"

#define SHOW_HITBOXES

class Body 
{
private:
	RectangleShape  _csShape;
	bool			_bColisionActive;
		
public:
	Body();
	
	Body(RectangleShape csBody, bool bColisionActive);

	Body(Body &bodSourceBody);

	RectangleShape getShape();
	void setShape(RectangleShape csNewShape);

	bool IsColisionActive();
	void IsColisionActive(bool bNewCollisionState);

	void setPosition(sf::Vector2f vfStartPos);
	void setSize(Vector2f vfNewSize);
	void setOrigin(Vector2f vfNewOrigin);
	void setRotation(float fAngle);

	void rotate(float fAngle);
	void move(Vector2f vfDirection);
	void moveOrigin(Vector2f  vfMovement);
};