#include "Parser.h"
#include <fstream>
#include <sstream>



Parser::Parser()
{
}

vector<Vertex> Parser::parse(string filename)
{
	ifstream file;
	file.open(filename);
	string line;

	vector<Vertex> outputV;



	while (getline(file, line)){
		Vertex v;
		stringstream ss;
		ss.str(line);
		ss >> v.num >> v.x >> v.y;

		outputV.push_back(v);
	}

	return outputV;
}

