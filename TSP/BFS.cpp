#include "BFS.h"

double BFS::bfs(Vertex *vStart, unordered_set<Vertex*> &vertsLeft, vector<Vertex*> &path) {
	double totalDist = 0;
	Vertex* startCopy = vStart;
	
	while (true) {
		if (vertsLeft.size() == 0)
			break;

		Vertex* closestV;
		double minDist = 1e300;

		//find closest vertex
		for (Vertex* v : vertsLeft)
		{
			double dist = vStart->dist(*v);

			if (dist < minDist) {
				minDist = dist;
				closestV = v;
			}
		}
		totalDist += minDist;

		//delete from set of unvisited and add to path
		vertsLeft.erase(closestV);
		path.push_back(closestV);
		vStart = closestV;
	}
	
	path.push_back(startCopy);
	totalDist+= path.back()->dist(*startCopy);

	return totalDist;
}