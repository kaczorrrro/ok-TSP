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

SimulatedAnnealing * simPointer;

void ctrlCHandler(int sigNum) {
	cout << "Enter new temp" << endl;
	double newTemp;
	cin >> newTemp;

}


int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Enter file [start min speed]" << endl;
		return -1;
	}
	double initTemp = 100;
	double minTemp = 0.1;
	double speed = 1e-7;

	if (argc == 5) {
		initTemp = std::stod(argv[2]);
		minTemp = std::stod(argv[3]);
		speed = std::stod(argv[4]);
	}

	
	
	bool bfs = false;
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

		SimulatedAnnealing sim(initTemp, minTemp, speed, 16384*16);
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

