#include "../include/Level.h"
#include <iostream>
#include <time.h>

using namespace std;

    //Constructor
    Level::Level(void){


    }

    Level::Level(std::pair<int, int> dimensoes, int comidaTotal){

      this->dimensoes = dimensoes;
      this->comidaTotal = comidaTotal;
      this->playerSpawn = playerSpawn;

    }

    void Level::adicionarComidaNoMapa(vector<vector<int>> &m){

      srand(time(NULL));

      while(m[this->posComidas[this->comidaColetada].first][this->posComidas[this->comidaColetada].second]==2 || m[this->posComidas[this->comidaColetada].first][this->posComidas[this->comidaColetada].second]==0){

        this->posComidas[this->comidaColetada].first = rand()%this->dimensoes.first;
        this->posComidas[this->comidaColetada].second = rand()%this->dimensoes.second;

        
      }
      
      m[this->posComidas[this->comidaColetada].first][this->posComidas[this->comidaColetada].second] = 4;


    }

    //Adder

    void Level::aumentarComidaColetada(){

      this->comidaColetada++;

    }

    void Level::inicializarComidas(vector<vector<int>> &m){

      srand(time(NULL));

      for(int x = 0; x < this->comidaTotal; x++){
        int rf, cf;
        
        do{
          rf = rand()%this->dimensoes.first;
          cf = rand()%this->dimensoes.second;

        }while(m[rf][cf]!=1);

        this->posComidas[x] = std::make_pair(rf,cf);

      }

    }

    //Getters

    int Level::getPosComidaAtualRow(){

      return this->posComidas[this->comidaColetada].first;

    }

    int Level::getComidasRestantes(){

      return this->comidaTotal-this->comidaColetada;

    }

    int Level::getPosComidaAtualCol(){

      return this->posComidas[this->comidaColetada].second;


    }

    int Level::getDimensaoRow(){

      return this->dimensoes.first;

    }

    int Level::getDimensaoCol(){

      return this->dimensoes.second;

    }

    std::pair<int,int> & Level::getPlayerSpawn(){

      return this->playerSpawn;

    }

    int Level::getComidasTotal(){

      return this->comidaTotal;

    }

    int Level::getComidasColetada(){

      return this->comidaColetada;

    }

    //Setters

    void Level::setPlayerSpawn (std::pair<int, int> playerSpawn){

      this->playerSpawn = playerSpawn;

    }

    void Level::gerarPlayerSpawn(std::vector<std::vector<int>> &m){
      
      srand(time(NULL));

      int r, c;
        
      do{
        r = rand()%this->dimensoes.first;
        c = rand()%this->dimensoes.second;

      }while(m[r][c]!=1);

      this->setPlayerSpawn(std::make_pair(r, c));

    }