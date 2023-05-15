#include "Timer.h"

Timer::Timer()
{
	_clTimer.restart();
	_timHandlingTime = seconds(0);
}

float Timer::getTime()
{
	return _timHandlingTime.asSeconds();
}

void Timer::setTime(Time timNewTime)
{
	_timHandlingTime = timNewTime;
}

Clock Timer::getClock()
{
	return _clTimer;
}

void Timer::setClock(Clock clNewClock)
{
	_clTimer = clNewClock;
}

void Timer::RefreshTimer()
{
	_timHandlingTime = _clTimer.getElapsedTime();
	_clTimer.restart();
}


