#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include "Player.h"
#include "Directions.h"

class Snake{
	/*
		TODO implementação dos atributos e métodos
	*/
  private:

    int vidas = 5;
    int numCauda = 0;
    std::map< int, std::pair<int, int> > cauda;
    int score = 0;
    bool possuiRabo;
    Directions ultimoMovimento;
    Player IA;

  public:

    //Constructor
    Snake(void);

    Snake(std::pair<int,int> spawn, bool possuiRabo);
    
    //Getters


    int getVidas();

    int getScore();

    //adders

    void iniciarPlayer(int R, int C, std::vector<std::vector<int>> &m);

    /**
    * @brief adiciona mais uma unidade de corpo na cobra.
    **/
    bool aumentarCauda(std::vector<std::vector<int>> &m);

    /**
    * @brief aumenta o score atual.
    **/
    void aumentarScore();

    //subtraction

    void diminuirVida();

    //Operations

    /**
    * @brief Recebe uma direção e executa a movimentação de todo o corpo da cobra baseado nessa direção.
    **/
    std::string mover(Directions d, std::vector<std::vector<int>> &m, int rFinish, int cFinish);

    /**
    * @brief reinicia o corpo da cobra na posição de spawn inicial.
    **/
    void resetarCauda(std::vector<std::vector<int>> &m, std::pair<int,int> &spawn);

    /**
    * @brief solicita uma solução a IA, executa e retorna uma resposta de sucesso ou falha.
    **/
    std::string executarSolucao(std::vector<std::vector<int>> &m,int dimRows, int dimCols, int rFinish, int cFinish);

};

#endif
