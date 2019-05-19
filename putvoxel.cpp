#include "putvoxel.h"

PutVoxel::PutVoxel(int nx,int ny,int nz, float nr, float ng, float nb, float na)
{
    x=nx;
    y=ny;
    z=nz;
    r=nr;
    g=ng;
    b=nb;
    a=na;
}

void PutVoxel::draw(Sculptor &t)
{
    t.putVoxel(x,y,z,r,g,b,a);
}
