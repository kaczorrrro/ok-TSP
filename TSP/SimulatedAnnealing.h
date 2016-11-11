#pragma once
#include"Solution.h"
class SimulatedAnnealing
{
public:
	SimulatedAnnealing(double startTemp, double minTemp, double speed);
	Solution run(Solution initial);

	

	

	

private:
	double startTemp, minTemp, coolingRate;
	bool shouldSwap(double oldDistance, double newDistance, double temp);
};

