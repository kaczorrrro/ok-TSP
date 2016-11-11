#pragma once
#include<vector>
#include"Vertex.h"

class Solution
{
public:
	Solution(std::vector<Vertex*> verts);
	void shuffle();
	double getTotalDist() { return totalDist; };
	int getNumberOfVerts() { return numberOfVerts; };
	double getDistForSwapped(int pos1, int pos2);
	void swap(int pos1, int pos2);
	double calculateDistance();
	string toString();
private:
	double totalDist;
	int numberOfVerts;
	std::vector<Vertex*> path;

	/*
	Swaps elements, does nothing more
	*/
	void justSwap(int pos1, int pos2);
	
	/*
	Both start and end included
	*/
	double distForRange(int start, int end);

	void parseInputPositions(int &pos1, int &pos2);
	
};

