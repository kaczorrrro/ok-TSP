#pragma once
#include"Solution.h"
class RandomizedLocalSearch
{
public:
	RandomizedLocalSearch(int randomFactor) : randomFactor(randomFactor) {};
	Solution run(Solution solution, int steps);

	
	
private:
	int randomFactor;
	bool shouldSwap(double oldDistance, double newDistance, int i, int currentRand);
	
};

