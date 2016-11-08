#pragma once
#include<vector>
#include"Vertex.h"

class Solution
{
public:
	Solution(std::vector<Vertex*> verts);
	void shuffle();
	long long getTotalDist() { return totalDist; };
	int getNumberOfVerts() { return numberOfVerts; };
	long long getDistForSwapped(int pos1, int pos2);
	void swap(int pos1, int pos2);
	long long calculateDistance();
	string toString();
private:
	long long totalDist;
	int numberOfVerts;
	std::vector<Vertex*> path;

	/*
	Swaps elements, does nothing more
	*/
	void justSwap(int pos1, int pos2);
	
	/*
	Both start and end included
	*/
	long long distForRange(int start, int end);

	void parseInputPositions(int &pos1, int &pos2);
	
};

