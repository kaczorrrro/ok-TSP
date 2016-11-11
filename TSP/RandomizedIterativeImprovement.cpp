#include "RandomizedIterativeImprovement.h"
#include <iostream>


Solution RandomizedIterativeImprovement::run(Solution solution, int steps)
{
	int vertsCount = solution.getNumberOfVerts() - 1;
	
	Solution currentBest = solution;
	double bestDistance = currentBest.getTotalDist();

	double oldDistance = solution.getTotalDist();
	int rCount = 1;
	for (int ii = 0; ii < steps; ii++) {
		//if (ii%randomFactor == 0) {
		//	int p1 = rand() % (vertsCount - 1) + 1;
		//	int p2 = rand() % p1;
		//	solution.swap(p1, p2);
		//	oldDistance = solution.getTotalDist();
		//}


		double bestDistLocal = INT_MAX;
		//pair of best edges for swapping
		int a = -1;
		int b = -1;

		for (int i = 1; i < vertsCount; i++) {
			for (int j = 0; j < i; j++) {
				double distLocal = solution.getDistForSwapped(i, j);
				if (distLocal < bestDistLocal) {
					a = i;
					b = j;
					bestDistLocal = distLocal;
				}
			}
		}
		if (bestDistLocal < oldDistance)
		{
			solution.swap(a, b);
			oldDistance = bestDistLocal;
		}
		else {
			rCount++;
			for (int i = 0; i < rCount; i++) {
				int p1 = rand() % (vertsCount - 1) + 1;
				int p2 = rand() % p1;
				solution.swap(p1, p2);
			}
			oldDistance = solution.getTotalDist();
		}

		if (solution.getTotalDist() < bestDistance) {
			rCount--;
			bestDistance = solution.getTotalDist();
			currentBest = solution;
		}


		
		if (ii % 0x100 == 0)
			cout << "Current: " << oldDistance << " Best: " << bestDistance << endl;
	}

	return currentBest;
}
