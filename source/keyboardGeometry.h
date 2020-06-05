#pragma once
#include "geometry.h"
double dRand();
struct keyboardGeometry
{
public:
  Geometry keyboard;
  keyboardGeometry();
  ~keyboardGeometry();
  void beginMap(unsigned char);
  void endMap(unsigned char);
  unsigned char getMap(unsigned char);
};
