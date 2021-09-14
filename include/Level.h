#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <map>

class Level{
	/*
		TODO implementação dos atributos e métodos
	*/
  private:

    std::pair<int, int> dimensoes;
    int comidaTotal;
    int comidaColetada = 0;
    std::pair<int, int> playerSpawn;
    std::map< int, std::pair<int, int> > posComidas;

  public:

    //Constructor
    Level(void);
    Level(std::pair<int, int> dimensoes, int comidaTotal);

    //Adder
    /**
    * @brief gera n posições randômicas válidas em que as comidas podem surgir.
    **/
    void inicializarComidas(std::vector<std::vector<int>> &m);

    //Adder
    void aumentarComidaColetada();

    //Getters

    int getDimensaoRow();

    int getDimensaoCol();

    std::pair<int,int> & getPlayerSpawn();

    int getComidasColetada();

    int getComidasTotal();

    int getComidasRestantes();

    int getPosComidaAtualRow();

    int getPosComidaAtualCol();

    //Setters

    void gerarPlayerSpawn(std::vector<std::vector<int>> &m);

    void setPlayerSpawn (std::pair<int, int> playerSpawn);

    /**
    * @brief adiciona a próxima comida no mapa.
    **/
    void adicionarComidaNoMapa(std::vector<std::vector<int>> &m);

};

#endif
