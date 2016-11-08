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
using namespace std;



int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Enter file" << endl;
		return -1;
	}
	std::srand(unsigned(std::time(0)));
	
	bool bfs = false;
	bool simulated = true;

	//parse data
	Parser p;
	vector<Vertex> verts = p.parse(argv[1]);
	vector<Vertex*> pointersToVerts;
	for (unsigned int i = 0; i < verts.size(); i++)
		pointersToVerts.push_back(&verts[i]);


	if (bfs) {
		unordered_set<Vertex*> vertsLeft(pointersToVerts.begin(), pointersToVerts.end());
		vector<Vertex*> path;
		Vertex *vStart = &verts[0];
		BFS::bfs(vStart, vertsLeft, path);
		Solution soultion(path);
		cout << soultion.getTotalDist() << endl;
	}

	if (simulated) {
		Solution s(pointersToVerts);
		int vertsCount = s.getNumberOfVerts()-1;

		for (int i=0; i<100000;i++)
		{
			int p1, p2;
			p1 = rand() % vertsCount;
			p2 = rand() % vertsCount;

			
			s.swap(p1, p2);
			cout << i << '\r';
		}	

	}
	
	
}

