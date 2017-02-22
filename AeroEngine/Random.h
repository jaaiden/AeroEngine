#pragma once
#include <random>
#include <time.h>
class Random
{
public:
	// Returns a random integer [min, max)
	static int range(int min, int max)
	{
		static bool first = true;
		if (first)
		{
			srand(time(NULL));
			first = false;
		}

		return min + rand() % (max - min);
	}
};