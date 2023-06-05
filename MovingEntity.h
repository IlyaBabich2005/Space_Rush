#pragma once
#include <cmath>
#include "Entity.h"
#include "DirectionalMovement.h"
#include "Math.h"

class MovingEntity : public Entity
{
private:
	float							 _fMaxSpeed,
									 _fAcceleration,
								     _fAngularVelosity,
									 _fAngularAcceleration,
									 _fMaxAngularVelosity;

	std::vector<DirectionalMovement> _vdmMovements;
	DirectionalMovement				*_dmCurentMovement,
									 _dmResultingMovement;
public:	
	MovingEntity();

	MovingEntity(int iID, sf::Vector2f vfPos, ae::Sprite sprSprite, Body bodBody);

	~MovingEntity();

	void							 setMaxSpeed(float fNewMaxSpeed);
	void							 setAcceleration(float fNewAcceleration);		
	void							 setAngularVelosity(float fNewAngularVelosity);
	void							 setAngularAcceleration(float fNewAngularAcceleration);
	void							 setMaxAngularVelosity(float fNewMaxAngularVelosity);
	void							 setMovements(std::vector<DirectionalMovement> vdmNewMovements);
	void							 setCurentMovement(DirectionalMovement &dmCurentDirection);
	void							 setResultingMovement(DirectionalMovement dmCurentDirection);

	float							 getMaxSpeed();
	float							 getAcceleration();
	float							 getAngularVelosity();
	float							 getAngularAcceleration();
	float							 getMaxAngularVelosity();
	std::vector<DirectionalMovement> getMovements();
	DirectionalMovement*			 getCurentMovement();
	DirectionalMovement				 getResultingMovement();

	virtual void					 MoveSet();

	void							 AccelerateClockwise(float fHandlingTime);
	void							 AccelerateCounterclockwise(float fHandlingTime);
	void							 RotationSlowDown(float fHandlingTime, int iSlowingCoefficient);

	void							 SetCurentMovement();
	void							 AccelerateForward(float fHandlingTime);
	void							 AccelerateBack(float fHandlingTime);
	void							 MovingSlowDown(float fHandlingTime);
	void							 CulculateResultingVector(float fHandlingTime);
};