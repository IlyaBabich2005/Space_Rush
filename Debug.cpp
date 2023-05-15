#include "Debug.h"

void Debug::ShowEntityInfo(Entity* eSourceEntity, RenderWindow &rwCurrentWindow)
{
	std::string sTmp;

	sTmp =
		"Position:\nx: " + std::to_string(eSourceEntity->getPosition().x) +
		"\ny: " + std::to_string(eSourceEntity->getPosition().y) +
		"\nAngle:\nx: " + std::to_string(eSourceEntity->getAngle());
	_txtDebugText.setString(sTmp);
	rwCurrentWindow.draw(_txtDebugText);
}

void Debug::ShowPlayerInfo(Player* pSourcePlayer, RenderWindow &rwCurrentWindow)
{
	std::string sTmp;

	sTmp =
		"Position:\nx: " + std::to_string(pSourcePlayer->getPosition().x) +
		"\ny: " + std::to_string(pSourcePlayer->getPosition().y) +
		"\nAngle:\nx: " + std::to_string(pSourcePlayer->getAngle()) + "\nVectors:\n";

	for (int i = 0; i < pSourcePlayer->getMovements().size(); i++)
	{
		sTmp +=std::to_string(i + 1) + ") x: " + std::to_string(pSourcePlayer->getMovements()[i].getDirection().x)
			+ "\n  y: " + std::to_string(pSourcePlayer->getMovements()[i].getDirection().y) + "\nSpeed: "
			+ std::to_string(pSourcePlayer->getMovements()[i].getSpeed()) + "\n";
	}

	_txtDebugText.setString(sTmp);
	rwCurrentWindow.draw(_txtDebugText);
}

Debug::Debug()
{
	setFont(SYSTEM::RES::FONTS::DEBUG_FONT);
	_txtDebugText.setFont(_ftTextFont);
	_txtDebugText.setFillColor(Color::White);
	_iTextHeight = 14;
	_txtDebugText.setCharacterSize(_iTextHeight);
}

Font Debug::getFont()
{
	return _ftTextFont;
}

void Debug::setFont(std::string sPathToFont)
{
	_ftTextFont.loadFromFile(sPathToFont);
}

Text Debug::getText()
{
	return _txtDebugText;
}

void Debug::setText(Text txtNewText)
{
	this->_txtDebugText = txtNewText;
}

int Debug::getTextHeight()
{
	return this->_iTextHeight;
}

void Debug::setTextHeigth(int iNewHeight)
{
	this->_iTextHeight = iNewHeight;
}

