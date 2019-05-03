#include <iostream>
#include "sculptor.h"

using namespace std;

int main()
{

    string str = "";

    Sculptor y(3,3,3);
    y.setColor(1,0,1,1);
    y.putBox(0,0,0,2,2,2);
    y.cutVoxel(1,1,1);
    y.printMatriz();
    y.writeOFF(str);

    /*
    y.putBox(0,0,0,2,2,2);
    y.printMatriz();
    y.cutBox(0,0,0,2,2,2);
    y.printMatriz();
    y.putSphere(2,2,2,2);
    y.printMatriz();
    y.cutSphere(2,2,2,2);
    y.printMatriz();
    y.putEllipsoid(4,4,4,3,4,3);
    y.printMatriz();
    y.cutEllipsoid(4,4,4,3,4,3);
    y.printMatriz();
    y.setColor(25,25,25,1);
    y.printMatriz();
    */
    return 0;
}
