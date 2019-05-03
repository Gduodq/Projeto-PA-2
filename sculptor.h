#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <iostream>

using namespace std;
/**
*Estrutura usada para os desenhos
*/
struct Voxel
{
/**
*Variáveis usadas na formação dos desenhos
*/

    float r,g,b;
    float a;
    bool isOn;
};
/**
*Classe usada para esboçar o desenho
*/
class Sculptor {
private:
  Voxel ***v;
  int nc,nl,np;
  float r,g,b,a;
public:
/**
*Funções usadas para desenhar
*/
  Sculptor(int nx, int ny, int nz);
  ~Sculptor();
  void setColor(float _r, float _g, float _b, float _a);
  void print();
  void printMatriz();
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void writeOFF(string filename);
  void writeVECT(string filename);
};

#endif // SCULPTOR_H
