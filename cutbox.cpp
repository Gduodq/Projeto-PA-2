#include "cutbox.h"

CutBox::CutBox(int nx0,int nx1,int ny0,int ny1,int nz0,int nz1)
{
    x0 = nx0;
    x1 = nx1;
    y0 = ny0;
    y1 = ny1;
    z0 = nz0;
    z1 = nz1;
}

void CutBox::draw(Sculptor &t)
{
    for(int i = z0; i<=z1; i++)
    {
        for(int j = y0; j<=y1; j++)
        {
            for(int k = x0; k<=x1; k++)
            {
                t.cutVoxel(k,j,i);
            }
        }
    }
}
