#pragma once

#include "Player.h"

class Scene
{
private:
	int _iNumOfPlayers;
	vector<Player> _vpPlayers;
public:
	Scene();

	int getPlayersCount();
	void setPlayersCount(int iNewPlayerCount);

	vector<Player> getPlayers();
	void setPlayer(vector<Player> vpNewPlayers);

	void Show(RenderWindow rwSourceWindow);
};