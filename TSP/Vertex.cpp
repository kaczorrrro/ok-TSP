#include "Vertex.h"
#include <sstream>

using namespace std;

string Vertex::toString()
{
	stringstream ss;
	ss << num << " " << x << " " << y << endl;
	return ss.str();
}

int Vertex::sdist(const Vertex & v2)
{
	int xD = x - v2.x;
	int yD = y - v2.y;
	return xD*xD + yD*yD;
}
