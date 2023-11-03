#include "sculptor.h"
#include "math.h"
#include <fstream>
#include <iostream>

Sculptor::Sculptor(int _nx, int _ny, int _nz) {
  nx = _nx;
  ny = _ny;
  nz = _nz;

  v = new Voxel **[nx];

  for (int i = 0; i < nx; i++) {
    v[i] = new Voxel *[ny]; 

    for (int j = 0; j < ny; j++) {
      v[i][j] = new Voxel[nz];
    }
  }

  for (int xi = 0; xi < nx; xi++) {
    for (int yi = 0; yi < ny; yi++) {
      for (int zi = 0; zi < nz; zi++) {
        v[xi][yi][zi].show = false;
      }
    }
  }
}

Sculptor::~Sculptor() {
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      delete[] v[i][j];
    }
  }

  for (int j = 0; j < nx; j++) {
    delete[] v[j];
  }

  delete[] v;
  std::cout << "Destrutor executado!";
}

void Sculptor::setColor(float r, float g, float b, float a) {
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z) {
  if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].show = true;
  } 
  else {
    std::cout << "Coordenadas inválidas putVoxel!" << std::endl;
  }
}

void Sculptor::cutVoxel(int x, int y, int z) {
  if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
    v[x][y][z].show = false;
  }

  else {
    std::cout << "Coordenadas inválidas cutVoxel!" << std::endl;
  }
}

void Sculptor::writeOFF(const char *file) {
  // variáveis para contar o número de vértices e faces
  int n_vertices = 0, n_faces = 0;

  // variáveis para armazenar as cores
  float r, g, b, a;

  // offset para os índices dos vértices
  int index = 0;

  // ofstream permite escrever em arquivos
  std::ofstream fout(file, std::ios::out);


  if (fout.is_open()){
  // escreve o cabeçalho do arquivo
  fout << "OFF" << std::endl;

    for (int i = 0; i < nx; i++) {
      for (int j = 0; j < ny; j++) {
        for (int k = 0; k < nz; k++) {
          if (v[i][j][k].show) {
            n_vertices += 8;
            n_faces += 6;
          }
        }
      }
    }
  }
  fout << n_vertices << " " << n_faces << " " << 0 << std::endl;

  // escreve os vértices
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].show) {
          // vértices de um cubo unitário
          fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
          fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
          fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl;
          fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl;
          fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
          fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
          fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl;
          fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
        }
      }
    }
  }

  // escreve as faces e as cores
  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      for (int k = 0; k < nz; k++) {
        if (v[i][j][k].show) {
          r = v[i][j][k].r;
          g = v[i][j][k].g;
          b = v[i][j][k].b;
          a = v[i][j][k].a;

          // o primeiro numero é a quantidade de vértices que formam a
          // face, os outros números são os índices que representam os vértices.
          // o index é um offset que garante que os pontos do cubo atual não se
          // sobreponham aos pontos do cubo anterior no arquivo de saída. os
          // quatro últimos números são as cores do cubo.

          fout << 4 << " " << 0 + index << " " << 3 + index << " " << 2 + index
               << " " << 1 + index << " " << r << " " << g << " " << b << " "
               << a << std::endl;
          fout << 4 << " " << 4 + index << " " << 5 + index << " " << 6 + index
               << " " << 7 + index << " " << r << " " << g << " " << b << " "
               << a << std::endl;
          fout << 4 << " " << 0 + index << " " << 1 + index << " " << 5 + index
               << " " << 4 + index << " " << r << " " << g << " " << b << " "
               << a << std::endl;
          fout << 4 << " " << 0 + index << " " << 4 + index << " " << 7 + index
               << " " << 3 + index << " " << r << " " << g << " " << b << " "
               << a << std::endl;
          fout << 4 << " " << 3 + index << " " << 7 + index << " " << 6 + index
               << " " << 2 + index << " " << r << " " << g << " " << b << " "
               << a << std::endl;
          fout << 4 << " " << 1 + index << " " << 2 + index << " " << 6 + index
               << " " << 5 + index << " " << r << " " << g << " " << b << " "
               << a << std::endl;

          index += 8;
        }
      }
    }
  }

  fout.close();
}

int Sculptor::getNx() { return nx; }

int Sculptor::getNy() { return ny; }

int Sculptor::getNz() { return nz; }