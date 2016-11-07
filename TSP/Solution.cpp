#include "Solution.h"
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

Solution::Solution(vector<Vertex*> verts) : path(verts) {
	totalDist = calculateDistance();
	numberOfVerts = (int)path.size();
}

void Solution::shuffle()
{
	random_shuffle(path.begin(), path.end());
	totalDist = calculateDistance();
}

long long Solution::getDistForSwapped(int pos1, int pos2)
{
	if (min(pos1, pos2) == 0 || max(pos1, pos2) == numberOfVerts - 1) {
		cout << "Swapping is now allowed on first or last position! (yet)" << endl;
		return -1;
	}
	if (pos1 == pos2)
		return totalDist;
	{
		int temp1 = pos1;
		int temp2 = pos2;
		pos1 = min(temp1, temp2);
		pos2 = max(temp1, temp2);
	}


	Vertex v1 = *path[pos1];
	Vertex v2 = *path[pos2];

	long long toRemove = 0;
	long long toAdd = 0;

	if (abs(pos1 - pos2) == 1) {
		Vertex* v10 = path[pos1 - 1];
		toRemove += v1.dist(*v10);
		toAdd += v2.dist(*v10);

		Vertex* v23 = path[pos2 + 1];
		toRemove += v2.dist(*v23);
		toAdd += v1.dist(*v23);
	}
	else {
		Vertex* v10 = path[pos1 - 1];
		Vertex* v12 = path[pos1 + 1];
		toRemove += v1.dist(*v10);
		toRemove += v1.dist(*v12);
		toAdd += v2.dist(*v10);
		toAdd += v2.dist(*v12);

		Vertex* v21 = path[pos2 - 1];
		Vertex* v23 = path[pos2 + 1];
		toRemove += v2.dist(*v21);
		toRemove += v2.dist(*v23);
		toAdd += v1.dist(*v21);
		toAdd += v1.dist(*v23);
	}

	return totalDist + toAdd - toRemove;
}

void Solution::swap(int pos1, int pos2)
{
	if (min(pos1, pos2) == 0 || max(pos1, pos2) == numberOfVerts - 1) {
		cout << "Swapping is now allowed on first or last position! (yet)" << endl;
		return;
	}

	//this must be calculated before swapping occurs!
	totalDist = getDistForSwapped(pos1, pos2);

	Vertex* temp = path[pos1];
	path[pos1] = path[pos2];
	path[pos2] = temp;
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

