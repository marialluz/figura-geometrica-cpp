/**
 * @file cutBox.h
 * @brief Declaração da classe cutBox, responsável por realizar um corte em forma de caixa em um objeto Sculptor tridimensional.
 */
#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Classe derivada de FiguraGeometrica que desativa todos os voxels no intervalo [x0,x1], [y0,y1], [z0,z1]
 * As coordenadas (x0, y0, z0) representam o canto inferior esquerdo da caixa e (x1, y1, z1) representam o canto superior direito da caixa a ser cortada.
 */
class cutBox : public FiguraGeometrica{
    float x0, x1, y0, y1, z0, z1;
public:
/**
 * @brief Construtor da classe cutBox.
 * @param x0_ Coordenada x do canto inferior esquerdo da caixa.
 * @param x1_ Coordenada x do canto superior direito da caixa.
 * @param y0_ Coordenada y do canto inferior esquerdo da caixa.
 * @param y1_ Coordenada y do canto superior direito da caixa.
 * @param z0_ Coordenada z do canto inferior esquerdo da caixa.
 * @param z1_ Coordenada z do canto superior direito da caixa.
 * @param r Componente vermelha da cor do corte.
 * @param g Componente verde da cor do corte.
 * @param b Componente azul da cor do corte.
 * @param a Transparência da cor do corte.
 */
    cutBox(float x0_, float x1_, float y0_, float y1_, float z0_, float z1_, float r, float g, float b, float a);
/**
 * @brief Função para realizar o corte em forma de caixa no objeto Sculptor.
 * @param s Referência para o objeto Sculptor onde o corte será aplicado.
 */
    void draw(Sculptor &s);
};

#endif // CUTBOX_H