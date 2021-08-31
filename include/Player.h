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

    bool verificarViabilidade(int row, int col, std::vector<std::vector<int>> &m, int dimRows, int dimCols, std::vector<std::vector<bool>> &visited);

    void buscarSolucao(int row, int col, int row_finish, int col_finish, std::vector<std::vector<int>> &m,
			int dimRows, int dimCols, std::string& caminho, std::vector<std::string>&
			caminhos, std::vector<std::vector<bool>> &visited);

    bool setarSolucao(std::vector<std::vector<int>> &m, int dimRows, int dimCols, int row, int col, int rFinish, int cFinish);

    Directions proximoMovimento();

};

#endif
