#pragma once
#include <vector>
struct GeometryE
{
	std::vector<GeometryE*> neighbors;
	GeometryE* map;
	GeometryE();
};

struct Geometry {
	GeometryE geometry[0x100];
	void addCon(unsigned char, unsigned char);
};
