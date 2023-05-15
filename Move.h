#pragma once

class MoveInterface
{
public:
	virtual void Move(Vector2f vfNewCord) = 0;
	virtual void Move() = 0;
};