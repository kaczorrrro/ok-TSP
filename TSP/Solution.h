#pragma once
#include<vector>
#include"Vertex.h"

class Solution
{
public:
	Solution(std::vector<Vertex*> verts);
	void shuffle();
	long long getTotalDist() { return totalDist; };
	long long getDistForSwapped(int pos1, int pos2);
	void swap(int pos1, int pos2);
	long long calculateDistance();
	string toString();
private:
	long long totalDist;
	int numberOfVerts;
	std::vector<Vertex*> path;
	
};

