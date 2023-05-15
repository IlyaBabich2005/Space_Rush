#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Timer
{
private:
	Time _timHandlingTime;
	Clock _clTimer;
public:
	Timer();

	float getTime();
	void setTime(Time timNewTime);

	Clock getClock();
	void setClock(Clock clMewClock);

	void RefreshTimer();
};