#include "cutBox.h"
#include <iostream>
#include "math.h"

cutBox::cutBox(float x0_, float x1_, float y0_, float y1_, float z0_, float z1_, float r, float g, float b, float a) {
  x0 = x0_;
  x1 = x1_;
  y0 = y0_;
  y1 = y1_;
  z0 = z0_;
  z1 = z1_;
  this->r=r;
  this->g=g;
  this->b=b;
  this->a=a;
}

void cutBox::draw(Sculptor &s) {
  std::cout << "apagar Box:";
  s.setColor(r,g,b,a);
  for (int i = x0; i <= x1; i++) {
    for (int j = y0; j <= y1; j++) {
      for (int k = z0; k <= z1; k++) {
        s.cutVoxel(i,j,k);
      }
    }
  } 
}