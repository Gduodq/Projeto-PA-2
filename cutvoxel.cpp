#include "cutvoxel.h"

CutVoxel::CutVoxel(int nx, int ny,int nz)
{
    x = nx;
    y = ny;
    z = nz;
}

void CutVoxel::draw(Sculptor &t)
{
    t.cutVoxel(x,y,z);
}
