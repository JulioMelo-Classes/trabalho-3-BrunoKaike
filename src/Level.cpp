#include "../include/Level.h"
#include <iostream>

using namespace std;

    //Constructor
    Level::Level(void){


    }

    Level::Level(std::pair<int, int> dimensoes, int comidaTotal, int comidaColetada){

      this->dimensoes = dimensoes;
      this->comidaTotal = comidaTotal;
      this->comidaColetada = comidaColetada;
      this->playerSpawn = playerSpawn;

    }

    void Level::adicionarComidaNoMapa(vector<vector<int>> &m){
      
      m[this->posComidas[this->comidaColetada].second][this->posComidas[this->comidaColetada].first] = 4;

    }

    //Adder

    void Level::aumentarComidaColetada(){

      this->comidaColetada++;

    }

    void Level::inicializarComidas(vector<vector<int>> &m){

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

    int Level::getDimensaoRow(){

      return this->dimensoes.first;

    }

    int Level::getDimensaoCol(){

      return this->dimensoes.second;

    }

    pair<int,int> Level::getPlayerSpawn(){

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