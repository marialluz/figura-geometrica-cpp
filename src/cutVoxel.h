#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"
#include "sculptor.h"

class cutVoxel : public FiguraGeometrica{
    int x, y, z;
public:
    explicit cutVoxel(int x_, int y_, int z_, float r, float g, float b, float a);
    void draw(Sculptor &s);
};

#endif // CUTVOXEL_H