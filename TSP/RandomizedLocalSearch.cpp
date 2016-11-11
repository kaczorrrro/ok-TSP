#include "RandomizedLocalSearch.h"
#include "Solution.h"
#include <iostream>


Solution RandomizedLocalSearch::run(Solution solution, int steps)
{
	int vertsCount = solution.getNumberOfVerts() - 1;
	int currentRand = randomFactor;
	Solution currentBest = solution;
	double bestDistance = currentBest.getTotalDist();

	double oldDistance = solution.getTotalDist();
	cout << "\tLocal solution: " << solution.getTotalDist() << "\tRand val: " << currentRand << endl;
	for (int i = 0; i < steps; i++) {
		int p1, p2;
		p1 = rand() % vertsCount;
		p2 = rand() % vertsCount;

		double newDistance = solution.getDistForSwapped(p1, p2);
		
		if (i % 0x40000 == 0) {
			cout << "\tLocal solution: " << solution.getTotalDist() << "\tRand val: " << currentRand << endl;
		}

		if (shouldSwap(oldDistance, newDistance, i, currentRand))
		{
			solution.swap(p1, p2);
			oldDistance = newDistance;

			if (newDistance < bestDistance) {
				bestDistance = newDistance;
				currentBest = solution;
				cout << "New best distance: " << bestDistance << endl;
			}

		}


	}

	return currentBest;
}


bool RandomizedLocalSearch::shouldSwap(double oldDistance, double newDistance, int i, int currentRand) {
	if (i%currentRand == 0)
		return true;

	if (oldDistance >= newDistance)
		return true;

	return false;

}
