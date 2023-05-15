#include "Body.h"

Body::Body()
{
	_csShape.setSize({ 100,180 });

	_csShape.setFillColor(Color::Transparent);
	_csShape.setOutlineThickness(1);
	_csShape.setOutlineColor(Color::Blue);
	
	_csShape.setOrigin(Math::GetRectangleCentre(_csShape));

	_bColisionActive = false;
}

Body::Body(RectangleShape csBody, bool bColisionActive)
{
	_csShape = csBody;
	_csShape.setOrigin(Math::GetRectangleCentre(_csShape));

	_bColisionActive = bColisionActive;
}

Body::Body(Body& bodSpurceBody)
{
	this->_bColisionActive = bodSpurceBody._bColisionActive;
	this->_csShape = bodSpurceBody._csShape;
	_csShape.setOrigin(Math::GetRectangleCentre(_csShape));
}

RectangleShape Body::getShape()
{
	return _csShape;
}

void Body::setShape(RectangleShape csNewShape)
{
	_csShape = csNewShape;
}

bool Body::IsColisionActive()
{
	return _bColisionActive;
}

void Body::IsColisionActive(bool bNewCollisionState)
{
	_bColisionActive = bNewCollisionState;
}

void Body::setPosition(Vector2f vfNewPos)
{
	_csShape.setPosition(vfNewPos);
	//_csShape.setOrigin(_csShape.getOrigin() + vfNewPos);
}

void Body::setSize(Vector2f vfNewSize)
{
	_csShape.setSize(vfNewSize);
	_csShape.setOrigin({ _csShape.getSize().x / 2, _csShape.getSize().y / 2 });
}

void Body::setOrigin(Vector2f vfNewOrigin)
{
	_csShape.setOrigin(vfNewOrigin.x, vfNewOrigin.y);
}

void Body::setRotation(float fAngle)
{
	_csShape.setRotation(fAngle);
}



void Body::rotate(float fAngle)
{
	_csShape.rotate(fAngle);
}

void Body::move(Vector2f vfDirection)
{
	this->_csShape.move(vfDirection);
}

void Body::moveOrigin(Vector2f vfMovement)
{
	_csShape.setOrigin(_csShape.getOrigin() + vfMovement);
}
