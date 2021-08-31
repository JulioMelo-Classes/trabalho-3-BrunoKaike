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
    int comidaColetada;
    std::pair<int, int> playerSpawn;
    std::map< int, std::pair<int, int> > posComidas;

  public:

    //Constructor
    Level(void);
    Level(std::pair<int, int> dimensoes, int comidaTotal, int comidaRestante);

    //Adder
    void inicializarComidas(std::vector<std::vector<int>> &m);

    //Adder
    void aumentarComidaColetada();

    //Getters

    int getDimensaoRow();

    int getDimensaoCol();

    std::pair<int,int> getPlayerSpawn();

    int getComidasColetada();

    int getComidasTotal();

    //Setters

    void setPlayerSpawn (std::pair<int, int> playerSpawn);

    void adicionarComidaNoMapa(std::vector<std::vector<int>> &m);

};

#endif
