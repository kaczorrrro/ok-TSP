#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <unordered_set>
#include <ctime>
#include "Parser.h"
#include "Vertex.h"
#include "BFS.h"
#include "Solution.h"
#include "SimulatedAnnealing.h"
using namespace std;



int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Enter file" << endl;
		return -1;
	}
	std::srand(unsigned(std::time(0)));
	
	bool bfs = true;
	bool simulated = true;

	//parse data
	Parser p;
	vector<Vertex> verts = p.parse(argv[1]);
	vector<Vertex*> pointersToVerts;
	for (unsigned int i = 0; i < verts.size(); i++)
		pointersToVerts.push_back(&verts[i]);

	Solution initial(pointersToVerts);
	cout << "Initial dist:" << (double)initial.getTotalDist() << endl;

	
	if (bfs) {
		cout << "Greedy" << endl;

		unordered_set<Vertex*> vertsLeft(pointersToVerts.begin(), pointersToVerts.end());
		vector<Vertex*> path;
		Vertex *vStart = &verts[0];
		BFS::bfs(vStart, vertsLeft, path);
		Solution soultion(path);
		cout << (double)soultion.getTotalDist() << endl;
	}

	if (simulated) {
		cout << "Simulated Annealing" << endl;

		Solution s(pointersToVerts);
		cout << "Start" << endl;

		SimulatedAnnealing sim(1000, 0.00001);
		Solution finalSolution = sim.run(s);
		cout << "End" << endl;

		cout << (double)finalSolution.getTotalDist() << endl;

	}
	
	
}

