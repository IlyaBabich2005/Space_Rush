#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Paths.h"
#include "Player.h"

using namespace sf;

class Debug
{
private:
	Font _ftTextFont;
	Text _txtDebugText;
	int	 _iTextHeight;
public:
	Debug();

	Font getFont();
	void setFont(std::string sPathToFont);

	Text getText();
	void setText(Text txtNewText);

	int getTextHeight();
	void setTextHeigth(int iNewHeight);

	void ShowEntityInfo(Entity* eSourceEntity, RenderWindow &rwCurrentWindow);
	void ShowPlayerInfo(Player* pSourcePlayer, RenderWindow &rwCurrentWindow);
};