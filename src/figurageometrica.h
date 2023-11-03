/**
 * @file FiguraGeometrica.h
 * @brief Declaração da classe FiguraGeometrica, responsável por representar figuras geométricas em um ambiente tridimensional.
 */

#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"

/**
 * @brief Classe abstrata que representa uma figura geométrica tridimensional.
 * As classes derivadas devem implementar a função pura draw() para desenhar a figura no objeto Sculptor fornecido.
 */
class FiguraGeometrica {
protected:
    float r, g, b, a; ///< Cores da figura (componentes RGBA).
public:
    /**
     * @brief Destrutor virtual da classe FiguraGeometrica.
     */
    virtual ~FiguraGeometrica(){};

    /**
     * @brief Função pura virtual para desenhar a figura no objeto Sculptor.
     * @param s Referência para o objeto Sculptor onde a figura será desenhada.
     */
    virtual void draw(Sculptor &s) = 0;
};

#endif // FIGURAGEOMETRICA_H
