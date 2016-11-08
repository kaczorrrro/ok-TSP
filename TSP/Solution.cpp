#include "Solution.h"
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

Solution::Solution(vector<Vertex*> verts) : path(verts) {
	//add first city as last so we have a cycle
	path.push_back(path[0]);
	
	totalDist = calculateDistance();
	numberOfVerts = (int)path.size();
}

void Solution::shuffle()
{
	//shuffle all except last element, then set last the same as first to have a cycle
	random_shuffle(path.begin(), path.end()-1);
	path[numberOfVerts-1] = path[0];

	totalDist = calculateDistance();
}

long long Solution::getDistForSwapped(int pos1, int pos2)
{
	parseInputPositions(pos1, pos2);

	if (pos2 >= numberOfVerts - 1) {
		cout << "Swapping is not allowed on last pos, swap first position instead" << endl;
		return totalDist;
	}
	if (pos1 == pos2)
		return totalDist;

	long long toRemove = 0;
	long long toAdd = 0;

	if (pos1 == 0) {
		toRemove += distForRange(pos1, pos1 + 1);
		toRemove += distForRange(pos2 - 1, pos2 + 1);
		toRemove += distForRange(numberOfVerts-2, numberOfVerts-1);
		
		justSwap(pos1, pos2);

		toAdd += distForRange(pos1, pos1 + 1);
		toAdd += distForRange(pos2 - 1, pos2 + 1);
		toAdd += distForRange(numberOfVerts - 2, numberOfVerts - 1);

		justSwap(pos1, pos2);
	}
	else{
		toRemove += distForRange(pos1 - 1, pos1 + 1);
		toRemove += distForRange(pos2 - 1, pos2 + 1);

		justSwap(pos1, pos2);

		toAdd += distForRange(pos1 - 1, pos1 + 1);
		toAdd += distForRange(pos2 - 1, pos2 + 1);

		justSwap(pos1, pos2);	
	}

	return totalDist + toAdd - toRemove;
}

void Solution::swap(int pos1, int pos2)
{
	parseInputPositions(pos1, pos2);
	if (pos2 == numberOfVerts - 1) {
		cout << "Swapping is not allowed on last pos, swap first position instead" << endl;
		return;
	}

	//this must be calculated before swapping occurs!
	totalDist = getDistForSwapped(pos1, pos2);

	justSwap(pos1, pos2);
}


long long Solution::distForRange(int start, int end) {
	long long sum = 0;

	for (int i = start; i < end; i++) {
		sum+=path[i]->dist(*path[i + 1]);
	}

	return sum;
}

void Solution::justSwap(int pos1, int pos2) {
	if (pos1 == 0) {
		path[0] = path[pos2];
		path[pos2] = path[numberOfVerts - 1];
		path[numberOfVerts - 1] = path[0];

	}
	else {
		Vertex* temp = path[pos1];
		path[pos1] = path[pos2];
		path[pos2] = temp;
	}
}

long long Solution::calculateDistance() {
	long long sum = 0;
	for (int i = 0, n = (int)path.size()-1; i < n; i++)
	{
		sum += path[i]->dist(*path[i + 1]);
	}
	return sum;
}

string Solution::toString()
{
	stringstream ss;
	for (Vertex *x : path)
		ss << x->num << " -> ";
	ss << "END";
	return ss.str();
}

void Solution::parseInputPositions(int &pos1, int &pos2) {
	int temp1 = pos1;
	int temp2 = pos2;
	pos1 = temp1 < temp2 ? temp1 : temp2;
	pos2 = temp2 > temp1 ? temp2 : temp1;
}

