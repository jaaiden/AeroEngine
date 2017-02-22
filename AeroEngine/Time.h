#pragma once
#include <SDL.h>
class Time
{
public:
	Time();
	~Time();

	static float Time::GetDeltaTime()
	{
		long last = 0;
		float deltaTime = 0;
		long now = SDL_GetTicks();

		if (now > last)
		{
			deltaTime = ((float)(now - last)) / 1000;
			last = now;
		}

		return deltaTime;
	}

	static float Time::GetDeltaTimeInSeconds()
	{
		return GetDeltaTime()*0.001;
	}
};