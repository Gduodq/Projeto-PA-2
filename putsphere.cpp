#include "putsphere.h"
#include <math.h>

PutSphere::PutSphere(int nx0,int ny0,int nz0,int nradius,float nr,float ng,float nb,float na)
{
    x0=nx0;
    y0=ny0;
    z0=nz0;
    radius = nradius;
    r=nr;
    g=ng;
    b=nb;
    a=na;
}

void PutSphere::draw(Sculptor &t)
{
    float sphere;


    for(int i = 0; i<=z0+radius; i++)
    {
        for(int j = 0; j<=y0+radius; j++)
        {
            for(int k = 0; k<=x0+radius; k++)
            {
                sphere = pow((float)(k-x0),2) + pow((float)(j-y0),2) + pow((float)(i-z0),2);
                if(sphere <= pow(radius,2))
                {
                    t.putVoxel(k,j,i,r,g,b,a);
                }
            }
        }
    }
}
