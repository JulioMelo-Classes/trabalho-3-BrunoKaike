#include "../include/Player.h"
#include "../include/Directions.h"

#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <string.h>

using namespace std;

bool Player::verificarViabilidade(int row, int col, vector<vector<int>> &m, int dimRows, int dimCols, vector<vector<bool>> &visited)
{
	if (row == -1 || row == dimRows || col == -1 ||
				col == dimCols || visited[row][col]
						|| m[row][col] == 0 || m[row][col] == 2)
		return false;

	return true;
}

void Player::buscarSolucao(int row, int col, int row_finish, int col_finish, vector<vector<int>> &m,
			int dimRows, int dimCols, string& caminho, vector<string>&
			caminhos, vector<vector<bool>> &visited)
{

	if (row == -1 || row == dimRows || col == -1
			|| col == dimCols || visited[row][col]
						|| m[row][col] == 0)
		return;

	if (row == row_finish && col == col_finish) {
		caminhos.push_back(caminho);
		caminhos[0] = *std::min_element(caminhos.begin(), caminhos.end(),
                     [] (const std::string& s1, const std::string& s2) {
                         return s1.length() < s2.length(); }
                     );
		return;
	}

	visited[row][col] = true;

	if (verificarViabilidade(row + 1, col, m, dimRows, dimCols, visited))
	{
		caminho.push_back('B');
		buscarSolucao(row + 1, col, row_finish, col_finish, m, dimRows, dimCols, caminho, caminhos, visited);
		caminho.pop_back();
	}

	if (verificarViabilidade(row, col - 1, m, dimRows, dimCols, visited))
	{
		caminho.push_back('E');
		buscarSolucao(row, col - 1, row_finish, col_finish, m, dimRows, dimCols, caminho, caminhos, visited);
		caminho.pop_back();
	}

	if (verificarViabilidade(row, col + 1, m, dimRows, dimCols, visited))
	{
		caminho.push_back('D');
		buscarSolucao(row, col + 1, row_finish, col_finish, m, dimRows, dimCols, caminho, caminhos, visited);
		caminho.pop_back();
	}

	if (verificarViabilidade(row - 1, col, m, dimRows, dimCols, visited))
	{
		caminho.push_back('C');
		buscarSolucao(row - 1, col, row_finish, col_finish, m, dimRows, dimCols, caminho, caminhos, visited);
		caminho.pop_back();
	}

	visited[row][col] = false;
}

bool Player::setarSolucao(vector<vector<int>> &m, int dimRows, int dimCols, int row, int col, int rFinish, int cFinish)
{

    string caminho;
    vector<string> caminhos;

    vector<vector<bool>> visited;

    for(int x = 0; x < dimRows; x++){
        visited.push_back(std::vector<bool>());
        for(int y = 0; y < dimCols; y++){

            visited[x].push_back(false);

        }

    }


    buscarSolucao(row, col, rFinish, cFinish, m, dimRows, dimCols, caminho,
                        caminhos, visited);

    if(caminhos.size() > 0){
        if(!caminhos[0].empty()){
            cout << "->" << caminhos[0] << endl;
            this->ultimoCaminho = caminhos[0];
            return true;
        }
    }

      this->ultimoCaminho = "";
      return false;

}

Directions Player::proximoMovimento(){
    
    Directions d;
    
    if(!ultimoCaminho.empty()){
        
        switch(ultimoCaminho.back()) {
        case 'B':
             d = Directions::BAIXO;
            break;
        case 'C':
            d = Directions::CIMA;
            break;
        case 'D':
            d = Directions::DIREITA;
            break;
        case 'E':
            d = Directions::ESQUERDA;
            break;
        }
        
    } else {
        
        d = Directions::BAIXO;
        
    }
    
    return d;

}

