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
#include "RandomizedLocalSearch.h"
#include "RandomizedIterativeImprovement.h"
using namespace std;



int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Enter file" << endl;
		return -1;
	}
	std::srand(unsigned(std::time(0)));
	
	bool bfs = true;
	bool bfsPreprocess = true;
	bool simulated = true;
	bool randomized = false;
	bool iterative = false;

	//parse data
	Parser p;
	vector<Vertex> verts = p.parse(argv[1]);
	vector<Vertex*> pointersToVerts;
	for (unsigned int i = 0; i < verts.size(); i++)
		pointersToVerts.push_back(&verts[i]);

	Solution initial(pointersToVerts);
	cout << "Initial dist:" << initial.getTotalDist() << endl;

	
	if (bfs) {
		cout << "Greedy" << endl;

		unordered_set<Vertex*> vertsLeft(pointersToVerts.begin(), pointersToVerts.end());
		vector<Vertex*> path;
		Vertex *vStart = &verts[0];
		BFS::bfs(vStart, vertsLeft, path);
		Solution solution(path);
		cout << solution.toString() << endl;
		cout << solution.getTotalDist()<< endl;
		
		if (bfsPreprocess)
			pointersToVerts = path;
	}

	if (simulated) {
		cout << "Simulated Annealing" << endl;

		Solution s(pointersToVerts);
		cout << "Start" << endl;

		double init = 1000/3; //350 is better with preprocessing
		double rate = 0.0000004/4; //can be smaller for init 350

		SimulatedAnnealing sim(init, 40, rate,16384);
		Solution finalSolution = sim.run(s);
		cout << "End" << endl;

		cout << finalSolution.toString() << endl;
		cout << finalSolution.getTotalDist() << endl;

	}

	if (randomized) {
		cout << "Randomized Local Search" << endl;

		Solution s(pointersToVerts);
		cout << "Start" << endl;

		RandomizedLocalSearch r(0x10000);
		Solution finalSolution = r.run(s, 10000000);
		cout << "End" << endl;

		cout << finalSolution.toString() << endl;
		cout << finalSolution.getTotalDist() << endl;

	}

	if (iterative) {
		cout << "Randomized iterative improvment" << endl;

		Solution s(pointersToVerts);
		cout << "Start" << endl;

		RandomizedIterativeImprovement r(20);
		Solution finalSolution = r.run(s, 1000);
		cout << "End" << endl;

		cout << finalSolution.toString() << endl;
		cout << finalSolution.getTotalDist() << endl;

	}
	
	
}

