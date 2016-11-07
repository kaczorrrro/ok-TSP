#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <unordered_set>

#include "Parser.h"
#include "Vertex.h"

using namespace std;

long long bfs(Vertex *vStart, unordered_set<Vertex*> &vertsLeft, vector<Vertex*> &path);


int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Enter file" << endl;
		return -1;
	}
		
	Parser p;
	vector<Vertex> verts = p.parse(argv[1]);

	vector<Vertex*> path;
	unordered_set<Vertex*> vertsLeft;
	for (unsigned int i = 0; i < verts.size(); i++) 
		vertsLeft.insert(&verts[i]);
	Vertex *vStart = &verts[0];
	
	long long dist = bfs(vStart, vertsLeft, path);

	for (Vertex *v : path){
		cout << v->num << endl;
	}

	cout << "Dist: " << dist << endl;
	
}

//breadth first search
long long bfs(Vertex *vStart, unordered_set<Vertex*> &vertsLeft, vector<Vertex*> &path) {
	long long totalDist = 0;
	while (true) {
		if (vertsLeft.size() == 0)
			break;

		Vertex* closestV;
		int minDist = INT_MAX;

		//find closest vertex
		for (Vertex* v : vertsLeft)
		{
			int dist = vStart->sdist(*v);

			if (dist < minDist) {
				minDist = dist;
				closestV = v;
			}
		}
		totalDist += sqrt(minDist);

		//delete from set of unvisited and add to path
		vertsLeft.erase(closestV);
		path.push_back(closestV);
		vStart = closestV;
	}
	return totalDist;
}