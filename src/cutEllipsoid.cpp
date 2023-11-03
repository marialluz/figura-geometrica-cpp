#include "cutEllipsoid.h"
#include <iostream>
#include "math.h"

cutEllipsoid::cutEllipsoid(float x0_, float y0_, float z0_, float raioX_, float raioY_, float raioZ_, float r, float g, float b, float a) {
  x0 = x0_;
  y0 = y0_;
  z0 = z0_;
  raioX = raioX_;
  raioY = raioY_;
  raioZ = raioZ_;
  this->r=r;
  this->g=g;
  this->b=b;
  this->a=a;
}

void cutEllipsoid::draw(Sculptor &s) {
  std::cout << "draw elipsoide:";
  s.setColor(r,g,b,a);
  for (int i = x0 - raioX; i <= x0 + raioX; i++) {
    for (int j = y0 - raioY; j <= y0 + raioY; j++) {
      for (int k = z0 - raioZ; k <= z0 + raioZ; k++) {
        // equação da elipsoide: (x - x0)²/a² + (y - y0)²/b² + (z - z0)²/c² = 1
        // o (float) é para converter o resultado da divisão para float, caso
        // contrário ele arredonda para inteiro
        if (pow(i - x0, 2) / (float)pow(raioX, 2) + pow(j - y0, 2) / (float)pow(raioY, 2) +pow(k - z0, 2) / (float)pow(raioZ, 2) <= 1) 
        {
          s.cutVoxel(i, j, k);
        }
      }
    }
  }
}