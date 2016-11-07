#pragma once
#include <string>
#include <vector>
#include "Vertex.h"
using namespace std;

class Parser
{
public:
	Parser();
	vector<Vertex> parse(string filename);

};

