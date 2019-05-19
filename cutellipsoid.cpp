#include "cutellipsoid.h"
#include <math.h>

CutEllipsoid::CutEllipsoid(int nx0,int ny0,int nz0,int nrx,int nry,int nrz)
{
    x0=nx0;
    y0=ny0;
    z0=nz0;
    rx=nrx;
    ry=nry;
    rz=nrz;
}

void CutEllipsoid::draw(Sculptor &t)
{
    float elipse;

    for(int i = 0; i<=z0+rz; i++)
    {
        for(int j = 0; j<=y0+ry; j++)
        {
            for(int k = 0; k<=x0+rx; k++)
            {
                elipse = pow(((i-z0)/rz),2) + pow(((j-y0)/ry),2) + pow(((k-x0)/rx),2);
                if(elipse <=1)
                {
                    t.cutVoxel(k,j,i);
                }
            }
        }
    }
}
