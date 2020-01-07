#pragma once
#include "newcoder.h"

#define MAX_PRIME 1000
vector<bool> prime(MAX_PRIME + 1, true);

void initPrime()
{
	static bool initd = false;
	if (initd)
	{
		return;
	}

	initd = true;
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i <= MAX_PRIME; ++i)
	{
		if (prime[i])
		{
			for (int j = i + i; j <= MAX_PRIME; j += i)
			{
				prime[j] = false;
			}
		}
	}
}