#include "figurageometrica.h"
#include "cutBox.h"
#include "cutSphere.h"
#include "cutEllipsoid.h"
#include "cutVoxel.h"
#include "putBox.h"
#include "putSphere.h"
#include "putEllipsoid.h"
#include "putVoxel.h"
#include "sculptor.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

int main(){
    FiguraGeometrica *pfig;
    std::vector<FiguraGeometrica*> figs;
    std::ifstream fin;

    int x, y, z;
    fin.open("figura.txt");
    if(!fin.is_open()){
        return 0;
    }
    while(fin.good()){
        std::string s;
        // le o primeiro elemento da linha
        fin >> s;
        if(s.compare("dim") == 0 )
          {
            fin >> x >> y >> z;
          }
        else if(s.compare("putbox") == 0){
          float x0, y0, z0, x1, y1, z1, r, g, b, a;
          fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
          figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }
        else if(s.compare("cutbox") == 0){
          float x0, y0, z0, x1, y1, z1, r, g, b, a;
          fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
          figs.push_back(new cutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        }
        else if(s.compare("putsphere") == 0){
          float x0, y0, z0, raio, r, g, b, a;
          fin >> x0 >> y0 >> z0 >> raio >> r >> g >> b >> a;
          figs.push_back(new putSphere(x0, y0, z0, raio, r, g, b, a));
        }
        else if(s.compare("cutsphere") == 0){
            float x0, y0, z0, raio, r, g, b, a;
            fin >> x0 >> y0 >> z0 >> raio >> r >> g >> b >> a;
            figs.push_back(new cutSphere(x0, y0, z0, raio, r, g, b, a));
        }
        else if(s.compare("putellipsoid") == 0){
            float x0, y0, z0, raioX, raioY, raioZ, r, g, b, a;
            fin >> x0 >> y0 >> z0 >> raioX >> raioY >> raioZ >> r >> g >> b >> a;
            figs.push_back(new putEllipsoid(x0, y0, z0, raioX, raioY, raioZ, r, g, b, a));
        }
        else if(s.compare("cutellipsoid") == 0){
            float x0, y0, z0, raioX, raioY, raioZ, r, g, b, a;
            fin >> x0 >> y0 >> z0 >> raioX >> raioY >> raioZ >> r >> g >> b >> a;
            figs.push_back(new cutEllipsoid(x0, y0, z0, raioX, raioY, raioZ, r, g, b, a));
        }
        else if(s.compare("putvoxel") == 0){
            float x, y, z, r, g, b, a;
            fin >> x >> y >> z >> r >> g >> b >> a;
            figs.push_back(new putVoxel(x, y, z, r, g, b, a));
        }
        else if(s.compare("cutvoxel") == 0){
            float x, y, z, r, g, b, a;
            fin >> x >> y >> z >> r >> g >> b >> a;
            figs.push_back(new cutVoxel(x, y, z, r, g, b, a));
        }
    }

   Sculptor *s = new Sculptor(x,y,z);

    for(int i=0; i<figs.size(); i++){
        figs[i]->draw(*s);
    }

    for(int i=0; i<figs.size(); i++){
        delete figs[i];
    }

    s->writeOFF("projeto.off");

    delete s;

    return 0;
}