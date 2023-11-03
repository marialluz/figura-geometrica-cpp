#include "putBox.h"
#include <iostream>

PutBox::PutBox(float x0_, float x1_, float y0_, float y1_, float z0_, float z1_, float r, float g, float b, float a) {
  this->x0 = x0_;
  this->x1 = x1_;
  this->y0 = y0_;
  this->y1 = y1_;
  this->z0 = z0_;
  this->z1 = z1_;
  this->r=r;
  this->g=g;
  this->b=b;
  this->a=a;
}

void PutBox::draw(Sculptor &s) {
  std::cout << "draw Box:";
  s.setColor(r,g,b,a);
  
  for (int i = x0; i <= x1; i++) {
    for (int j = y0; j <= y1; j++) {
      for (int k = z0; k <= z1; k++) {
        s.putVoxel(i,j,k);
       }
     }
   }
}