#pragma once
#include <string>
using namespace std;
class Vertex {
public:
	int x, y, num;
	string toString();
	int sdist(const Vertex &v2);
};
