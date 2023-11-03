/**
 * @file PutBox.h
 * @brief Declaração da classe PutBox, responsável por ativar todos os voxels em um intervalo e atribuir a cor atual de desenho.
 */
#ifndef BOX_H
#define BOX_H

#include "figurageometrica.h"
#include "sculptor.h"

/**
 * @brief Classe derivada de FiguraGeometrica que representa a ação de ativar todos os voxels em um intervalo tridimensional.
 * As coordenadas (x0, y0, z0) representam o canto inferior esquerdo do intervalo e (x1, y1, z1) representam o canto superior direito do intervalo.
 */
class PutBox : public FiguraGeometrica{
    float x0, x1, y0, y1, z0, z1;
public:
/**
 * @brief Construtor da classe PutBox.
 * @param x0_ Coordenada x do canto inferior esquerdo do intervalo.
 * @param x1_ Coordenada x do canto superior direito do intervalo.
 * @param y0_ Coordenada y do canto inferior esquerdo do intervalo.
 * @param y1_ Coordenada y do canto superior direito do intervalo.
 * @param z0_ Coordenada z do canto inferior esquerdo do intervalo.
 * @param z1_ Coordenada z do canto superior direito do intervalo.
 * @param r Componente vermelha da cor a ser atribuída aos voxels ativados.
 * @param g Componente verde da cor a ser atribuída aos voxels ativados.
 * @param b Componente azul da cor a ser atribuída aos voxels ativados.
 * @param a Componente alfa (transparência) da cor a ser atribuída aos voxels ativados.
 */
    explicit PutBox(float x0_, float x1_, float y0_, float y1_, float z0_, float z1_, float r, float g, float b, float a);
/**
 * @brief Função para ativar todos os voxels no intervalo e atribuir a cor atual de desenho.
 * @param s Referência para o objeto Sculptor onde a ação será realizada.
 */
    void draw(Sculptor &s);
};

#endif // BOX_H