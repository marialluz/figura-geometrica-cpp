#ifndef VOXEL_H
#define VOXEL_H

#include "figurageometrica.h"
#include "sculptor.h"

class putVoxel : public FiguraGeometrica{
    int x, y, z;
public:
    explicit putVoxel(int x_, int y_, int z_, float r, float g, float b, float a);
    void draw(Sculptor &s);
};

#endif // VOXEL_H