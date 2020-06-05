#pragma once
#include "geometry.h"
double dRand();
struct KeyboardGeometry
{
public:
  Geometry keyboard;
  KeyboardGeometry();
  ~KeyboardGeometry();
  void beginMap(unsigned char);
  void endMap(unsigned char);
  unsigned char getMap(unsigned char);
};
