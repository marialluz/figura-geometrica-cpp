/**
 * @file cutSphere.h
 * @brief Declaração da classe cutSphere, responsável por realizar um corte em forma de esfera em um objeto Sculptor tridimensional.
 */
#ifndef CUTESFERA_H
#define CUTESFERA_H

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Classe derivada de FiguraGeometrica que desativa todos os voxels que satisfazem a equação da esfera
 * As coordenadas (x0, y0, z0) representam o centro da esfera e raio é o raio da esfera a ser cortada.
 * A cor do corte é determinada pelos valores de r, g, b e a passados no construtor.
 */

class cutSphere : public FiguraGeometrica{
    float x0, y0, z0, raio;
public:
  /**
   * @brief Construtor da classe cutEsfera.
   * @param x0_ Coordenada x do centro da esfera.
   * @param y0_ Coordenada y do centro da esfera.
   * @param z0_ Coordenada z do centro da esfera.
   * @param raio_ Raio da esfera a ser cortada.
   * @param r Componente vermelha da cor do corte.
   * @param g Componente verde da cor do corte.
   * @param b Componente azul da cor do corte.
   * @param a Componente alfa (transparência) da cor do corte.
   */
  cutSphere(float x0_, float y0_, float z0_, float raio_, float r, float g, float b, float a);
    /**
    * @brief Função para realizar o corte em forma de esfera no objeto Sculptor.
     * @param s Referência para o objeto Sculptor onde o corte será aplicado.
     */
    void draw(Sculptor &s);
};

#endif // CUTESFERA_H