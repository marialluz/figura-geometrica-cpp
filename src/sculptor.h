/**
 * @file sculptor.h
 * @brief Declaração da classe Sculptor e da estrutura Voxel para criação e manipulação de esculturas tridimensionais.
 */
#ifndef SCULPTOR_H
#define SCULPTOR_H

/**
 * @brief é uma Struct que armazena as cores e a transparência de um voxel
*/
struct Voxel {
  float r, g, b;  /**< Cores (canais vermelho, verde e azul). */
  float a;        /**< Cores (canais vermelho, verde e azul). */
  bool show;     /**< Indica se o voxel deve ser exibido (true) ou não (false). */

};

/**
 * @brief A classe Sculptor é responsável por criar uma matriz 3D de voxels e realizar operações sobre ela.
 */
class Sculptor {

private:
  int nx, ny, nz;   /**< Matriz 3D de voxels. */
  float r, g, b, a; /**< Cores e transparência utilizadas para desenho. */

public:
  Voxel ***v;       /**< Matriz 3D de voxels. */

  /**
   * @brief Construtor da classe Sculptor
   * @param _nx Dimensão em x
   * @param _ny Dimensão em y
   * @param _nz Dimensão em z
   */
  Sculptor(int _nx, int _ny, int _nz);

  /**
   * @brief Destrutor da classe Sculptor
   */
  ~Sculptor();

  /**
   * @brief Define a cor atual do desenho
   * @param r Canal vermelho
   * @param g Canal verde
   * @param b Canal azul
   * @param alpha Canal alpha (transparência)
   */
  void setColor(float r, float g, float b, float a);

  /**
   * @brief Ativa um voxel na posição (x,y,z), torna show = true e atribui a cor atual de desenho
   * @param x Posição x
   * @param y Posição y
   * @param z Posição z
   */
  void putVoxel(int x, int y, int z);

  /**
   * @brief Desativa um voxel na posição (x,y,z), torna show = false
   * @param x Posição x
   * @param y Posição y
   * @param z Posição z
   */
  void cutVoxel(int x, int y, int z);

/**
 * @brief Exporta a escultura para um arquivo no formato OFF.
 * @param filename Nome do arquivo para salvar a escultura.
 */
  void writeOFF(const char *filename);

  int getNx();

  int getNy();

  int getNz();
};

#endif