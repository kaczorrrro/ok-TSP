#pragma once
#include <string>
using namespace std;
class Vertex {
public:
	int x, y, num;
	string toString();
	long long dist(const Vertex &v2);
};
