#include "putVoxel.h"
#include <iostream>

putVoxel::putVoxel(int x_, int y_, int z_, float r, float g, float b, float a) {
  this->x = x_;
  this->y = y_;
  this->z = z_;
  this->g=g;
  this->b=b;
  this->a=a;
}

void putVoxel::draw(Sculptor &s) {
  std::cout << "put Voxel:";
  s.setColor(r,g,b,a);
  if (x >= 0 && x < s.getNx() && y >= 0 && y < s.getNy() && z >= 0 && z < s.getNz()) {
    s.v[x][y][z].r = r;
    s.v[x][y][z].g = g;
    s.v[x][y][z].b = b;
    s.v[x][y][z].a = a;
    s.v[x][y][z].show = true;
  } 
  else {
    std::cout << "Coordenadas inválidas putVoxel!" << std::endl;
  }
}