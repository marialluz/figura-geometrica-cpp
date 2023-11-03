/**
 * @file cutEllipsoid.h
 * @brief Declaração da classe cutElipsoide, responsável por realizar um corte em forma de elipsoide em um objeto Sculptor tridimensional.
 */
#ifndef CUTELIPSOIDE_H
#define CUTELIPSOIDE_H

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Classe derivada de FiguraGeometrica que desativa todos os voxels que satisfazem a equação do elipsóide
 * As coordenadas (x0, y0, z0) representam o centro do elipsoide e raioX, raioY e raioZ são os semieixos do elipsoide a ser cortado.
 * A cor do corte é determinada pelos valores de r, g, b e a passados no construtor.
 */
class cutEllipsoid : public FiguraGeometrica{
    float x0, y0, z0, raioX, raioY, raioZ;
public:
/**
 * @brief Construtor da classe cutElipsoide.
 * @param x0_ Coordenada x do centro do elipsoide.
 * @param y0_ Coordenada y do centro do elipsoide.
 * @param z0_ Coordenada z do centro do elipsoide.
 * @param raioX_ Semieixo X do elipsoide.
 * @param raioY_ Semieixo Y do elipsoide.
 * @param raioZ_ Semieixo Z do elipsoide.
 * @param r Componente vermelha da cor do corte.
 * @param g Componente verde da cor do corte.
 * @param b Componente azul da cor do corte .
 * @param a Componente alfa (transparência) da cor do corte .
 */
  cutEllipsoid(float x0_, float y0_, float z0_, float raioX_, float raioY_, float raioZ_, float r, float g, float b, float a);

/**
 * @brief Função para realizar o corte em forma de elipsoide no objeto Sculptor.
 * @param s Referência para o objeto Sculptor onde o corte será aplicado.
 */
    void draw(Sculptor &s);
};

#endif // CUTELIPSOIDE_H