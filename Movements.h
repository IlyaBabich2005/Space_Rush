#pragma once
#include "DirectionalMovement.h"
#include <iostream>

class Movements
{
private:
	std::vector <DirectionalMovement> _vdmMovements;
public:
	void							 setMovements(std::vector<DirectionalMovement> vdmNewMovements);

	std::vector<DirectionalMovement> getMovements();

	void							 Add();
	void							 Add(float fCurrentAngle);

};