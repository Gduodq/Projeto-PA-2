#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"

class CutVoxel: public FiguraGeometrica
{
    int x, y, z;
public:
    CutVoxel(int nx, int ny, int nz);
    void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
