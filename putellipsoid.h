#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"

class PutEllipsoid: public FiguraGeometrica
{
    int x0;
    int y0;
    int z0;
    int rx;
    int ry;
    int rz;
    float r;
    float g;
    float b;
    float a;
public:
    PutEllipsoid(int x0,int y0,int z0,int rx,int ry,int rz,float r,float g,float b,float a);
    void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
