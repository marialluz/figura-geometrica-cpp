#include "cutSphere.h"
#include <iostream>
#include "math.h"

cutSphere::cutSphere(float x0_, float y0_, float z0_, float raio_, float r, float g, float b, float a) {
  x0 = x0_;
  y0 = y0_;
  z0 = z0_;
  raio = raio_;
  this->r=r;
  this->g=g;
  this->b=b;
  this->a=a;
}

void cutSphere::draw(Sculptor &s) {
  std::cout << "apagar Esfera:";
  s.setColor(r,g,b,a);
  for (int i = x0 - raio; i <= x0 + raio; i++) {
    for (int j = y0 - raio; j <= y0 + raio; j++) {
      for (int k = z0 - raio; k <= z0 + raio; k++) {
        // equação da esfera: (x - x0)² + (y - y0)² + (z - z0)² = r²
        if (pow(i - x0, 2) + pow(j - y0, 2) + pow(k - z0, 2) <=
            pow(raio, 2)) {
          s.cutVoxel(i, j, k);
        }
      }
    }
  }
}