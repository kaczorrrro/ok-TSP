#include "SimulatedAnnealing.h"
#include <iostream>

SimulatedAnnealing::SimulatedAnnealing(double startTemp, double minTemp, double speed, int infoFreq): startTemp(startTemp),minTemp(minTemp), coolingRate(speed), infoFreq(infoFreq)
{
}

Solution SimulatedAnnealing::run(Solution solution)
{
	int vertsCount = solution.getNumberOfVerts() - 1;
	
	Solution currentBest = solution;
	double bestDistance = currentBest.getTotalDist();

	double oldDistance = solution.getTotalDist();
	int i = 0;
	for (double temp = startTemp; temp > minTemp; temp *= (1-coolingRate), i++) {
		if (i % infoFreq == 0) {
			cout << "Current temp: " << temp << "\tBest solution: " << currentBest.getTotalDist() << "\tLocal solution: " << solution.getTotalDist() << endl;
		}
		int p1, p2;
		p1 = rand() % vertsCount;
		p2 = rand() % vertsCount;
		
		double newDistance = solution.getDistForSwapped(p1, p2);

		if (shouldSwap(oldDistance, newDistance, temp)){
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

bool SimulatedAnnealing::shouldSwap(double oldDistance, double newDistance, double temp){
	if (oldDistance >= newDistance)
		return true;
	double x = ((double)rand() / (RAND_MAX));
	return x < exp( (oldDistance - newDistance ) / temp );
}


