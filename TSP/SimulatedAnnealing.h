#pragma once
#include"Solution.h"
class SimulatedAnnealing
{
public:
	SimulatedAnnealing(double startTemp, double minTemp, double speed, int infoFreq = 0x1000);
	Solution run(Solution initial);

	

	

	

private:
	double startTemp, minTemp, coolingRate;
	int infoFreq;
	bool shouldSwap(double oldDistance, double newDistance, double temp);
};

