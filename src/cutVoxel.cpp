#include "cutVoxel.h"
#include <iostream>

cutVoxel::cutVoxel(int x_, int y_, int z_, float r, float g, float b, float a) {
  this->x = x_;
  this->y = y_;
  this->z = z_;
  this->g=g;
  this->b=b;
  this->a=a;
}

void cutVoxel::draw(Sculptor &s) {
  std::cout << "cut Voxel:";
  s.setColor(r,g,b,a);
  if (x >= 0 && x < s.getNx() && y >= 0 && y < s.getNy() && z >= 0 && z < s.getNz()) {
    s.v[x][y][z].show = false;
  } 
  else {
    std::cout << "Coordenadas inválidas cutVoxel!" << std::endl;
  }
}