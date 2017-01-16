#pragma once
#include"Solution.h"
#include <random>
class SimulatedAnnealing
{
public:
	SimulatedAnnealing();
	Solution run(Solution initial, double startTemp, double minTemp, double speed, int infoFreq = 0x1000);
	void changeCurrentTemp(double newTemp);
	void stopOutput();
	void startOutput();
	


private:
	bool shouldSwap(double oldDistance, double newDistance, double temp, int& sumWorse);
	double temp;
	bool output = true;
	std::mt19937 randomEngine;
	Solution currentBest;
};

