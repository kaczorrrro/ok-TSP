#include "SimulatedAnnealing.h"
#include <iostream>

SimulatedAnnealing::SimulatedAnnealing()
{
	std::random_device rd;     // only used once to initialise (seed) engine
	randomEngine = std::mt19937(rd());    // random-number engine used (Mersenne-Twister in this case)
}

Solution SimulatedAnnealing::run(Solution solution, double startTemp, double minTemp, double speed, int infoFreq)
{
	int sumWorseAccepted = 0;

	int vertsCount = solution.getNumberOfVerts() - 1;
	std::uniform_int_distribution<int> randomDistribution(0, vertsCount-1);

	currentBest = solution;
	double bestDistance = currentBest.getTotalDist();

	double oldDistance = solution.getTotalDist();
	int i = 0;
	for (temp = startTemp; temp > minTemp; temp *= (1- speed), i++) {
		if (output && i % infoFreq == 0) {
			cout <<"i: " << i << "\tCurrent temp: " << temp << "\tBest solution: " << currentBest.getTotalDist() << "\tLocal solution: " << solution.getTotalDist() << "\tAcceptance rate: " << sumWorseAccepted / (double)infoFreq << endl;
			sumWorseAccepted = 0;
		}
		int p1, p2;
		p1 = randomDistribution(randomEngine);
		p2 = randomDistribution(randomEngine);
		
		double newDistance = solution.getDistForSwapped(p1, p2);

		if (shouldSwap(oldDistance, newDistance, temp, sumWorseAccepted)){
			solution.swap(p1, p2);
			oldDistance = newDistance;
			if (newDistance < bestDistance) {
				bestDistance = newDistance;
				currentBest = solution;
			}
		}
	}

	return currentBest;
}

void SimulatedAnnealing::changeCurrentTemp(double newTemp)
{
	temp = newTemp;
}

void SimulatedAnnealing::stopOutput()
{
	output = false;
}

void SimulatedAnnealing::startOutput()
{
	output = true;
}



bool SimulatedAnnealing::shouldSwap(double oldDistance, double newDistance, double temp, int& sumWorse){
	static std::uniform_real_distribution<> dis(0, 1);
	if (oldDistance >= newDistance)
		return true;
	double x = dis(randomEngine);
	if (x < exp((oldDistance - newDistance) / temp)) {
		++sumWorse;
		return true;
	}
	return false;
}


