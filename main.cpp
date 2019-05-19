#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "sculptor.h"
#include "figurageometrica.h"
#include "cutvoxel.h"
#include "putvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "cutsphere.h"
#include "putsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

using namespace std;

int main()
{
    string x = "C:/Users/Darlan/Desktop/teste.txt";
    Sculptor *t;
    vector<FiguraGeometrica*> fig;
    ifstream fin;
    string s,w;
    stringstream ss;
    int x0,y0,z0,x1,y1,z1,rx,ry,rz,radius;
    float r,g,b,a;

    fin.open(x);

    if(!fin.is_open())
    {
        cout<< "nao abriu" <<endl;
        exit(0);
    }

    while(fin.good())
    {
        getline(fin, s);
        ss.str(s);
        ss >> s;

        if(s.compare("dim") == 0)
        {
            ss >> x0 >> y0 >> z0;
            cout << x0 << "x" << y0 << "x" <<
                 z0 << endl;
            t = new Sculptor(x0,y0,z0);
        }
        else
        {
            if(s.compare("putvoxel") == 0)
            {
                ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
                fig.push_back(new PutVoxel(x0,y0,z0,r,g,b,a));
            }
            else if(s.compare("cutvoxel") == 0)
            {
                ss >> x0 >> y0 >> z0;
                fig.push_back(new CutVoxel(x0,y0,z0));
            }
            else if(s.compare("putbox") == 0)
            {
                ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
                fig.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
            }
            else if(s.compare("cutbox") == 0)
            {
                ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
                fig.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
            }
            else if(s.compare("putsphere") == 0)
            {
                ss >> x0 >> y0 >> z0 >> radius >> r >> g >> b >> a;
                fig.push_back(new PutSphere(x0,y0,z0,radius,r,g,b,a));
            }
            else if(s.compare("cutsphere") == 0)
            {
                ss >> x0 >> y0 >> z0 >> radius;
                fig.push_back(new CutSphere(x0,y0,z0,radius));
            }
            else if(s.compare("putellipsoid") == 0)
            {
                ss >> x0 >> y0 >> z0 >> rx >> ry >> rz >> r >> g >> b >> a;
                fig.push_back(new PutEllipsoid(x0,y0,z0,rx,ry,rz,r,g,b,a));
            }
            else if(s.compare("cutellipsoid") == 0)
            {
                ss >> x0 >> y0 >> z0 >> rx >> ry >> rz;
                fig.push_back(new CutEllipsoid(x0,y0,z0,rx,ry,rz));
            }
        }
        s.clear();
        ss.clear();
    }

    for(int i=0; i<fig.size(); i++)
    {
        fig[i]->draw(*t);
    }

    t->printMatriz();
    t->writeOFF(w);
    //t->writeVECT(w);

    for(int i=0; i<fig.size(); i++){
    delete fig[i];
    }
    return 0;
}
