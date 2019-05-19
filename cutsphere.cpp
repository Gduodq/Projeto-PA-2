#include "cutsphere.h"
#include <math.h>

CutSphere::CutSphere(int nx0,int ny0,int nz0,int nradius)
{
    x0=nx0;
    y0=ny0;
    z0=nz0;
    radius = nradius;
}

void CutSphere::draw(Sculptor &t)
{
    float sphere;

    for(int i = 0; i<=z0+radius; i++)
    {
        for(int j = 0; j<=y0+radius; j++)
        {
            for(int k = 0; k<=x0+radius; k++)
            {
                sphere = pow((i-z0),2) + pow(((j-y0)),2) + pow((k-x0),2);
                if(sphere <= pow(radius,2))
                {
                    t.cutVoxel(k,j,i);
                }
            }
        }
    }
}
