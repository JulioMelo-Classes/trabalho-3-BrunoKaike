#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include<stdbool.h>
#include "Directions.h"

class Player{
	/*
		TODO implementação dos atributos e métodos
	*/
  private:

    std::string ultimoCaminho;

  public:

    //operations
    /**
    * @brief verifica se a próxima direção é válida considerando dimensões do mapa, paredes e o próprio corpo da cobra.
    **/
    bool verificarViabilidade(int row, int col, std::vector<std::vector<int>> &m, int dimRows, int dimCols, std::vector<std::vector<bool>> &visited);

    /**
    * @brief monta recursivamente um cojunto de soluções que permitiriam a cobra chegar até a comida e salva a mais curta delas em uma string.
    **/
    void buscarSolucao(int row, int col, int row_finish, int col_finish, std::vector<std::vector<int>> &m,
			int dimRows, int dimCols, std::string& caminho, std::vector<std::string>&
			caminhos, std::vector<std::vector<bool>> &visited);

    /**
    * @brief seta uma string com a solução que a cobra deve executar para chegar até a comida, caso seja possível.
    **/
    bool setarSolucao(std::vector<std::vector<int>> &m, int dimRows, int dimCols, int row, int col, int rFinish, int cFinish);

    /**
    * @brief retorna o próximo movimento a ser executado pela cobra.
    **/
    Directions proximoMovimento();

};

#endif
