#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;
/**
*Construtor da Classe Sculptor
*/
Sculptor::Sculptor(int nx, int ny, int nz)
{
    nc = nx;
    nl = ny;
    np = nz;
    v = new Voxel**[np];
    v[0] = new Voxel*[np*nl];
    v[0][0] = new Voxel[nc*nl*np];
    v[1] = v[0] + nl*sizeof(Voxel**);
    for(int i=1; i<np; i++)
    {
        v[i] = v[i-1] + nl;
    }
    for(int i=1; i<np*nl; i++)
    {
        v[0][i] = v[0][i-1] + nc;
    }
}
/**
*Destrutor da Classe Sculptor
*/
Sculptor::~Sculptor()
{
    delete v;
    delete v[0];
    delete v[0][0];

}
/**
*Função para alterar a cor dos blocos desenhados
*/
void Sculptor::setColor(float _r, float _g, float _b, float _a)
{
    r = _r;
    g = _g;
    b = _b;
    a = _a;

}

void Sculptor::printMatriz()
{
    for(int i = 0; i<np; i++)
    {
        for(int j = 0; j<nl; j++)
        {
            for(int k = 0; k<nc; k++)
            {
                if(v[i][j][k].isOn == true)
                {
                    cout << "1 ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

}
/**
*Ativa um elemento da matriz
*/
void Sculptor::putVoxel(int x, int y, int z)
{
    bool _x = true;

    v[x][y][z].isOn = _x;
    v[x][y][z].r = r; v[x][y][z].g = g; v[x][y][z].b = b;
    v[x][y][z].a = a;

}
/**
*Desativa um elemento da matriz
*/
void Sculptor::cutVoxel(int x, int y, int z)
{
    bool _x = false;

    v[x][y][z].isOn = _x;

}
/**
*Ativa os voxels em forma de paralelepípedo
*/
void Sculptor::putBox(int x0, int y0, int z0, int x1, int y1, int z1)
{
    bool _x = true;

    for(int i = z0; i<=z1; i++)
    {
        for(int j = y0; j<=y1; j++)
        {
            for(int k = x0; k<=x1; k++)
            {
                    v[i][j][k].isOn = _x;
                    v[i][j][k].r = r; v[i][j][k].g = g; v[i][j][k].b = b;
                    v[i][j][k].a = a;
            }
        }
    }

}
/**
*Desativa os voxels em forma de paralelepípedo
*/
void Sculptor::cutBox(int x0, int y0, int z0, int x1, int y1, int z1)
{
    bool _x = false;

    for(int i = z0; i<=z1; i++)
    {
        for(int j = y0; j<=y1; j++)
        {
            for(int k = x0; k<=x1; k++)
            {
                v[i][j][k].isOn = _x;
            }
        }
    }

}
/**
*Ativa os voxels em forma de esfera
*/
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    bool _x = true;
    float sphere;

    for(int i = 0; i<=zcenter+radius; i++)
    {
        for(int j = 0; j<=ycenter+radius; j++)
        {
            for(int k = 0; k<=xcenter+radius; k++)
            {
                sphere = pow((k-xcenter),2) + pow(((j-ycenter)),2) + pow(((i-zcenter)),2);
                if(sphere <= pow(radius,2))
                {
                        v[i][j][k].isOn = _x;
                        v[i][j][k].r = r; v[i][j][k].g = g; v[i][j][k].b = b;
                        v[i][j][k].a = a;
                }
            }
        }
    }

}
/**
*Desativa os voxels em forma de esfera
*/
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    bool _x = false;
    float sphere;

    for(int i = 0; i<=zcenter+radius; i++)
    {
        for(int j = 0; j<=ycenter+radius; j++)
        {
            for(int k = 0; k<=xcenter+radius; k++)
            {
                sphere = pow((i-xcenter),2) + pow(((j-ycenter)),2) + pow(((k-zcenter)),2);
                if(sphere <= pow(radius,2))
                {
                    v[i][j][k].isOn = _x;
                }
            }
        }
    }

}
/**
*Ativa os voxels em forma de um elipsoide
*/
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int _rx, int _ry, int _rz)
{
    bool _x = true;
    float elipse;
    float rx = _rx;
    float ry = _ry;
    float rz = _rz;

    for(int i = 0; i<=zcenter+rz; i++)
    {
        for(int j = 0; j<=ycenter+ry; j++)
        {
            for(int k = 0; k<=xcenter+rx; k++)
            {
                elipse = pow(((i-xcenter)/rx),2) + pow(((j-ycenter)/ry),2) + pow(((k-zcenter)/rz),2);
                if(elipse <=1)
                {
                        v[i][j][k].isOn = _x;
                        v[i][j][k].r = r; v[i][j][k].g = g; v[i][j][k].b = b;
                        v[i][j][k].a = a;
                }
            }
        }
    }

}
/**
*Desativa os voxels em forma de um elipsoide
*/
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    bool _x = false;
    float elipse;

    for(int i = 0; i<=zcenter+rz; i++)
    {
        for(int j = 0; j<=ycenter+ry; j++)
        {
            for(int k = 0; k<=xcenter+rx; k++)
            {
                elipse = pow(((i-xcenter)/rx),2) + pow(((j-ycenter)/ry),2) + pow(((k-zcenter)/rz),2);
                if(elipse <=1)
                {
                    v[i][j][k].isOn = _x;
                }
            }
        }
    }

}
/**
*Escreve a escultura em formato VECT
*/
void Sculptor::writeVECT(string str)
{
    ofstream f_out;
    f_out.open("filenameVECT.txt");

    if(! f_out.good())
    {
        cout << "Falha ao criar arquivo\n";
    }
    else
        cout << "Arquivo criado!\n";

    int totalDeElementos = nc*nl*np;

    for(int i = 0; i<np; i++)
    {
        for(int j = 0; j<nl; j++)
        {
            for(int k = 0; k<nc; k++)
            {
                if(v[i][j][k].isOn == false)
                {
                    totalDeElementos--;
                }
            }
        }
    }

    str += "VECT\n";
    str += to_string(totalDeElementos) + " " + to_string(totalDeElementos) + " " + to_string(totalDeElementos) + "\n";

    for (int j = 0; j<=1; j++)
    {
        for(int i = 0; i<totalDeElementos; i++)
        {
            str += "1 ";
        }
        str += "\n";
    }

    for(int i = 0; i<np; i++)
    {
        for(int j = 0; j<nl; j++)
        {
            for(int k = 0; k<nc; k++)
            {
                if(v[i][j][k].isOn == true)
                {
                    str += to_string(i) + " " + to_string(j) + " " + to_string(k) + "\n" ;
                }
            }
        }
    }

    for(int i = 0; i<np; i++)
    {
        for(int j = 0; j<nl; j++)
        {
            for(int k = 0; k<nc; k++)
            {
                if(v[i][j][k].isOn == true)
                {
                    str += to_string(v[i][j][k].r) + " " + to_string(v[i][j][k].g) + " " + to_string(v[i][j][k].b) + " " + to_string(v[i][j][k].a) + "\n" ;
                }
            }
        }
    }

    f_out << str;
    f_out.close();
}
/**
*Escreve a escultura em formato OFF
*/
void Sculptor::writeOFF(string str){

    ofstream f_out;
    f_out.open("filenameOFF.txt");

    if(! f_out.good())
    {
        cout << "Falha ao criar arquivo\n";
    }
    else
        cout << "Arquivo criado!\n";

    int totalDeElementos = nc*nl*np;

    for(int i = 0; i<np; i++)
    {
        for(int j = 0; j<nl; j++)
        {
            for(int k = 0; k<nc; k++)
            {
                if(v[i][j][k].isOn == false)
                {
                    totalDeElementos--;
                }
            }
        }
    }

    str += "OFF\n";
    str += to_string(totalDeElementos*8) + " " + to_string(totalDeElementos*6) + " " + "0\n";

    for(int i = 0; i<np; i++)
    {
        for(int j = 0; j<nl; j++)
        {
            for(int k = 0; k<nc; k++)
            {
                if(v[i][j][k].isOn == true)
                {
                    str += to_string(k-0.5) + " " + to_string(j+0.5) + " " + to_string(i-0.5) + "\n";
                    str += to_string(k-0.5) + " " + to_string(j-0.5) + " " + to_string(i-0.5) + "\n";
                    str += to_string(k+0.5) + " " + to_string(j-0.5) + " " + to_string(i-0.5) + "\n";
                    str += to_string(k+0.5) + " " + to_string(j+0.5) + " " + to_string(i-0.5) + "\n";
                    str += to_string(k-0.5) + " " + to_string(j+0.5) + " " + to_string(i+0.5) + "\n";
                    str += to_string(k-0.5) + " " + to_string(j-0.5) + " " + to_string(i+0.5) + "\n";
                    str += to_string(k+0.5) + " " + to_string(j-0.5) + " " + to_string(i+0.5) + "\n";
                    str += to_string(k+0.5) + " " + to_string(j+0.5) + " " + to_string(i+0.5) + "\n";
                }
            }
        }
    }

    int cont = 0;

    for(int i = 0; i<np; i++)
    {
        for(int j = 0; j<nl; j++)
        {
            for(int k = 0; k<nc; k++)
            {
                if(v[i][j][k].isOn == true)
                {
                    int pos = 8*cont;
                    str += "4 " + to_string(pos) + " " + to_string(pos+3) + " " + to_string(pos+2) + " " + to_string(pos+1) + " " + to_string(v[i][j][k].r) + " " + to_string(v[i][j][k].g) + " " + to_string(v[i][j][k].b) + " " + to_string(v[i][j][k].a) + "\n";
                    str += "4 " + to_string(pos+4) + " " + to_string(pos+5) + " " + to_string(pos+6) + " " + to_string(pos+7) + " " + to_string(v[i][j][k].r) + " " + to_string(v[i][j][k].g) + " " + to_string(v[i][j][k].b) + " " + to_string(v[i][j][k].a) + "\n";
                    str += "4 " + to_string(pos) + " " + to_string(pos+1) + " " + to_string(pos+5) + " " + to_string(pos+4) + " " + to_string(v[i][j][k].r) + " " + to_string(v[i][j][k].g) + " " + to_string(v[i][j][k].b) + " " + to_string(v[i][j][k].a) + "\n";
                    str += "4 " + to_string(pos) + " " + to_string(pos+4) + " " + to_string(pos+7) + " " + to_string(pos+3) + " " + to_string(v[i][j][k].r) + " " + to_string(v[i][j][k].g) + " " + to_string(v[i][j][k].b) + " " + to_string(v[i][j][k].a) + "\n";
                    str += "4 " + to_string(pos+3) + " " + to_string(pos+7) + " " + to_string(pos+6) + " " + to_string(pos+2) + " " + to_string(v[i][j][k].r) + " " + to_string(v[i][j][k].g) + " " + to_string(v[i][j][k].b) + " " + to_string(v[i][j][k].a) + "\n";
                    str += "4 " + to_string(pos+1) + " " + to_string(pos+2) + " " + to_string(pos+6) + " " + to_string(pos+5) + " " + to_string(v[i][j][k].r) + " " + to_string(v[i][j][k].g) + " " + to_string(v[i][j][k].b) + " " + to_string(v[i][j][k].a) + "\n";
                    cont++;
                }
            }
        }
    }

    f_out << str;
    f_out.close();
}
