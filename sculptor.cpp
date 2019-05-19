#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <iostream>

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
    v[4][6][6].isOn = false;
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
void Sculptor::putVoxel(int nx, int ny, int nz, float nr, float ng, float nb, float na)
{
    if((nx>=0) && (nx<nc) && (ny>=0) && (ny<nl) && (nz>=0) && (nz<np))
    {
        v[nz][ny][nx].isOn = true;
        v[nz][ny][nx].r = nr;
        v[nz][ny][nx].g = ng;
        v[nz][ny][nx].b = nb;
        v[nz][ny][nx].a = na;
    }
}
/**
*Desativa um elemento da matriz
*/
void Sculptor::cutVoxel(int nx, int ny, int nz)
{
    if((nx>=0) && (nx<nc) && (ny>=0) && (ny<nl) && (nz>=0) && (nz<np))
    {
        v[nz][ny][nx].isOn = false;
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
void Sculptor::writeOFF(string str)
{

    ofstream f_out;
    f_out.open("filenameOFF.off");

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
