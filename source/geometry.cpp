#include "geometry.h"


void Geometry::addCon(unsigned char c1, unsigned char c2) {
	geometry[c1].neighbors.push_back(&geometry[c2]);
	geometry[c2].neighbors.push_back(&geometry[c1]);
}
