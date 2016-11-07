#pragma once
#include <string>
using namespace std;
class Vertex {
public:
	int x, y, num;
	string toString();
	int dist(const Vertex &v2);
};
