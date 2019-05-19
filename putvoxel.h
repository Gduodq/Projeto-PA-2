#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figurageometrica.h"

class PutVoxel: public FiguraGeometrica
{
    int x,y,z;
    float r,g,b,a;
public:
    PutVoxel(int nx,int ny,int nz,float nr, float ng, float nb, float na);
    void draw(Sculptor &t);
};

#endif // PUTVOXEL_H
