#include "Vertex.h"
#include <sstream>

using namespace std;

string Vertex::toString()
{
	stringstream ss;
	ss << num << " " << x << " " << y << endl;
	return ss.str();
}

long long Vertex::dist(const Vertex & v2)
{
	long long xD = x - v2.x;
	long long yD = y - v2.y;
	return xD*xD + yD*yD;
}
