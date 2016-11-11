#pragma once
#include "Solution.h"
class RandomizedIterativeImprovement
{
public:
	RandomizedIterativeImprovement(int randomFactor) : randomFactor(randomFactor) {};
	Solution run(Solution solution, int steps);
private:
	int randomFactor;
};

