#include "BFS.h"

long long BFS::bfs(Vertex *vStart, unordered_set<Vertex*> &vertsLeft, vector<Vertex*> &path) {
	long long totalDist = 0;
	while (true) {
		if (vertsLeft.size() == 0)
			break;

		Vertex* closestV;
		long long minDist = LLONG_MAX;

		//find closest vertex
		for (Vertex* v : vertsLeft)
		{
			long long dist = vStart->dist(*v);

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
	return totalDist;
}