#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"
#include <fstream>

class FiguraGeometrica
{
public:
    float r,g,b,a;
    virtual ~FiguraGeometrica(){

    };
    virtual void draw(Sculptor &t) = 0;
};

#endif // FIGURAGEOMETRICA_H
