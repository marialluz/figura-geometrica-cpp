/**
 * @file putSphere.h
 * @brief Declaração da classe putSphere, responsável por ativar voxels que satisfazem a equação da esfera e atribuir a cor atual de desenho.
 */
#ifndef ESFERA_H
#define ESFERA_H

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Classe derivada de FiguraGeometrica que representa a ação de ativar voxels em forma de esfera tridimensional.
 *
 * Esta classe é responsável por ativar todos os voxels que satisfazem a equação da esfera com centro em (x0, y0, z0) e raio raio_ e atribuir a cor atual de desenho.
 */
class putSphere : public FiguraGeometrica{
    float x0, y0, z0, raio;
public:
/**
 * @brief Construtor da classe putEsfera.
 * @param x0_ Coordenada x do centro da esfera.
 * @param y0_ Coordenada y do centro da esfera.
 * @param z0_ Coordenada z do centro da esfera.
 * @param raio_ Raio da esfera.
 * @param r Componente vermelha da cor a ser atribuída aos voxels ativados.
 * @param g Componente verde da cor a ser atribuída aos voxels ativados.
 * @param b Componente azul da cor a ser atribuída aos voxels ativados.
 * @param a Componente alfa (transparência) da cor a ser atribuída aos voxels ativados.
 */
  putSphere(float x0_, float y0_, float z0_, float raio_, float r, float g, float b, float a);
/**
 * @brief Função para ativar os voxels em forma de esfera no objeto Sculptor.
 * @param s Referência para o objeto Sculptor onde a ação será realizada.
 */
    void draw(Sculptor &s);
};

#endif // ESFERA_H