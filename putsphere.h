#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"

class PutSphere: public FiguraGeometrica
{
    int x0;
    int y0;
    int z0;
    int radius;
    float r;
    float g;
    float b;
    float a;
public:
    PutSphere(int x0,int y0,int z0,int radius,float r,float g,float b,float a);
    void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
