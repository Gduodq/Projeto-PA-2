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
protected:
  Voxel ***v;
  int nc,nl,np;
  float r,g,b,a;
public:
/**
*Funções usadas para desenhar
*/
  Sculptor(int nx, int ny, int nz);
  ~Sculptor();
  void printMatriz();
  void putVoxel(int nx, int ny, int nz, float nr, float ng, float nb, float na);
  void cutVoxel(int x, int y, int z);
  void writeOFF(string filename);
  void writeVECT(string filename);
};

#endif // SCULPTOR_H
