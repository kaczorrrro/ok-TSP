#include "SimulatedAnnealing.h"

SimulatedAnnealing::SimulatedAnnealing(double startTemp, double speed): startTemp(startTemp), coolingRate(speed)
{
}

Solution SimulatedAnnealing::run(Solution solution)
{
	int vertsCount = solution.getNumberOfVerts() - 1;
	
	Solution currentBest = solution;
	long long bestDistance = currentBest.getTotalDist();

	long long oldDistance = solution.getTotalDist();
	for (double temp = startTemp; temp > 1; temp *= (1-coolingRate)) {
		int p1, p2;
		p1 = rand() % vertsCount;
		p2 = rand() % vertsCount;
		
		long long newDistance = solution.getDistForSwapped(p1, p2);

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

bool SimulatedAnnealing::shouldSwap(long long oldDistance, long long newDistance, double temp){
	if (oldDistance >= newDistance)
		return true;
	double x = ((double)rand() / (RAND_MAX));
	return x < exp( (sqrt(oldDistance) - sqrt(newDistance) ) / temp );
}


