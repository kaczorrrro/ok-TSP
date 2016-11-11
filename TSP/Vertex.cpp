#include "Vertex.h"
#include <sstream>

using namespace std;

string Vertex::toString()
{
	stringstream ss;
	ss << num << " " << x << " " << y << endl;
	return ss.str();
}

double Vertex::dist(const Vertex & v2)
{
	double xD = x - v2.x;
	double yD = y - v2.y;
	return sqrt(xD*xD + yD*yD);
}

