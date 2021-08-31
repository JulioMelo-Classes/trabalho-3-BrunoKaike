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

    bool aumentarCauda(std::vector<std::vector<int>> &m);

    std::string mover(Directions d, std::vector<std::vector<int>> &m);

    void resetarCauda(std::vector<std::vector<int>> &m);


};

#endif
