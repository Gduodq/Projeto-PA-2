#include "putellipsoid.h"
#include <math.h>

PutEllipsoid::PutEllipsoid(int nx0,int ny0,int nz0,int nrx,int nry,int nrz,float nr,float ng,float nb,float na)
{
    x0=nx0;
    y0=ny0;
    z0=nz0;
    rx=nrx;
    ry=nry;
    rz=nrz;
    r=nr;
    g=ng;
    b=nb;
    a=na;
}

void PutEllipsoid::draw(Sculptor &t)
{
    float elipse;

    for(int i = 0; i<=z0+rz; i++)
    {
        for(int j = 0; j<=y0+ry; j++)
        {
            for(int k = 0; k<=x0+rx; k++)
            {
                elipse = pow(((float)(i-z0)/rz),2) + pow(((float)(j-y0)/ry),2) + pow(((float)(k-x0)/rx),2);
                if(elipse <=1)
                {
                    t.putVoxel(k,j,i,r,g,b,a);
                }
            }
        }
    }
}
