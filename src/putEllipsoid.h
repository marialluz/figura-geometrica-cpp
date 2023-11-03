/**
 * @file putEllipsoid.h
 * @brief Declaração da classe putEllipsoid, responsável por ativar voxels que satisfazem a equação do elipsoide e atribuir a cor atual de desenho.
 */
#ifndef ELIPSOIDE_H
#define ELIPSOIDE_H

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Classe derivada de FiguraGeometrica que representa a ação de ativar voxels em forma de elipsoide tridimensional.
 * As coordenadas (x0, y0, z0) representam o centro do elipsoide e raioX, raioY e raioZ são os semieixos do elipsoide.
 */
class putEllipsoid : public FiguraGeometrica{
    float x0, y0, z0, raioX, raioY, raioZ;
public:
/**
 * @brief Construtor da classe putElipsoide.
 * @param x0_ Coordenada x do centro do elipsoide.
 * @param y0_ Coordenada y do centro do elipsoide.
 * @param z0_ Coordenada z do centro do elipsoide.
 * @param raioX_ Semieixo X do elipsoide.
 * @param raioY_ Semieixo Y do elipsoide.
 * @param raioZ_ Semieixo Z do elipsoide.
 * @param r Componente vermelha da cor a ser atribuída aos voxels ativados.
 * @param g Componente verde da cor a ser atribuída aos voxels ativados.
 * @param b Componente azul da cor a ser atribuída aos voxels ativados.
 * @param a Componente alfa (transparência) da cor a ser atribuída aos voxels ativados.
 */
  putEllipsoid(float x0_, float y0_, float z0_, float raioX_, float raioY_, float raioZ_, float r, float g, float b, float a);

/**
 * @brief Função para ativar os voxels em forma de elipsoide no objeto Sculptor.
 * @param s Referência para o objeto Sculptor onde a ação será realizada.
 */
  void draw(Sculptor &s);
};

#endif // ELIPSOIDE_H