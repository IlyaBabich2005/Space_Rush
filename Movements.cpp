#include "Movements.h"

void Movements::setMovements(std::vector<DirectionalMovement> vdmNewMovements)
{
	this->_vdmMovements = vdmNewMovements;
}

std::vector<DirectionalMovement> Movements::getMovements()
{
	return this->_vdmMovements;
}

void Movements::Add()
{
	this->_vdmMovements.push_back(DirectionalMovement{});
}

void Movements::Add(float fCurrentAngle)
{
	this->Add();
	this->_vdmMovements.back().setAngle(fCurrentAngle);
}
