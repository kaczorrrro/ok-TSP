#pragma once
#include"Solution.h"
class SimulatedAnnealing
{
public:
	SimulatedAnnealing(double startTemp, double speed);
	Solution run(Solution initial);

	

	

	

private:
	double startTemp, coolingRate;
	bool shouldSwap(long long oldDistance, long long newDistance, double temp);
};

