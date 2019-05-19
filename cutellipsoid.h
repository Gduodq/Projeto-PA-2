#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"

class CutEllipsoid: public FiguraGeometrica
{
    int x0;
    int y0;
    int z0;
    int rx;
    int ry;
    int rz;
public:
    CutEllipsoid(int x0,int y0,int z0,int rx,int ry,int rz);
    void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
