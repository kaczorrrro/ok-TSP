#pragma once
#include"Solution.h"
#include <random>
class SimulatedAnnealing
{
public:
	SimulatedAnnealing(double startTemp, double minTemp, double speed, int infoFreq = 0x1000);
	Solution run(Solution initial);

	

private:
	double startTemp, minTemp, coolingRate;
	int infoFreq;
	bool shouldSwap(double oldDistance, double newDistance, double temp, int& sumWorse);
	std::mt19937 randomEngine;
};

