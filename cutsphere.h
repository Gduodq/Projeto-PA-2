#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"

class CutSphere: public FiguraGeometrica
{
    int x0;
    int y0;
    int z0;
    int radius;
public:
    CutSphere(int x0,int y0,int z0,int radius);
    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
