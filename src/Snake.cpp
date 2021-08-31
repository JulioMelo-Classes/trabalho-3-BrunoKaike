#include "../include/Snake.h"
#include "../include/Directions.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <map>

using namespace std;

    //Constructor
    Snake::Snake(void){

    }

    Snake::Snake(pair<int,int> spawn, bool possuiRabo){

      this->cauda[this->numCauda] = spawn;
      this->numCauda++;
      this->possuiRabo = possuiRabo;

    }

    //adders

    void Snake::iniciarPlayer(int R, int C, vector<vector<int>> &m){

      this->cauda[this->numCauda] = std::make_pair(R, C);
      m[R][C] = 2;
      this->numCauda++;

    }

    bool Snake::aumentarCauda(vector<vector<int>> &m){
      if(possuiRabo){
        auto last = this->cauda.end();
        last--;
        if(m[last->second.first-1][last->second.second] == 1){

          this->cauda[this->numCauda] = std::make_pair(last->second.first-1, last->second.second);
          m[last->second.first-1][last->second.second] = 2;

        } else if(m[last->second.first+1][last->second.second] == 1){

          this->cauda[this->numCauda] = std::make_pair(last->second.first+1, last->second.second);
          m[last->second.first+1][last->second.second] = 2;

        } else if(m[last->second.first][last->second.second+1] == 1){

          this->cauda[this->numCauda] = std::make_pair(last->second.first, last->second.second+1);
          m[last->second.first][last->second.second+1] = 2;

        } else if(m[last->second.first][last->second.second-1] == 1){

          this->cauda[this->numCauda] = std::make_pair(last->second.first, last->second.second-1);
          m[last->second.first][last->second.second-1] = 2;

        } else {
          
          return false;
          
        }

        this->numCauda++;
        return true;

      } else {

        return true;
      
      }

    }

    string Snake::mover(Directions d, vector<vector<int>> &m){

    if(d == Directions::BAIXO){
      if(m[this->cauda.begin()->second.first+1][this->cauda.begin()->second.second] == 1){
          pair<int,int> aux;
          for(auto x = this->cauda.begin(); x != this->cauda.end();x++){

            if(x==this->cauda.begin()){

              aux = std::make_pair(x->second.first, x->second.second);
              m[x->second.first][x->second.second] = 1;
              this->cauda[x->first] = std::make_pair(x->second.first+1, x->second.second);
              m[x->second.first][x->second.second] = 2;


            } else {

              auto aux2 = std::make_pair(x->second.first, x->second.second);
              m[x->second.first][x->second.second] = 1;
              this->cauda[x->first] = std::make_pair(aux.first, aux.second);
              m[x->second.first][x->second.second] = 2;

              aux = aux2;

            }

          }

        } else if(m[this->cauda.begin()->second.first+1][this->cauda.begin()->second.second] == 2){

          return "\033[1;31mVocê bateu em você mesma!\033[0m";

        }  else if(m[this->cauda.begin()->second.first+1][this->cauda.begin()->second.second] == 0){

          return "\033[1;31mVocê bateu em uma parede!\033[0m";

        }

    } else if(d == Directions::CIMA){
      if(m[this->cauda.begin()->second.first-1][this->cauda.begin()->second.second] == 1){
        pair<int,int> aux;
        for(auto x = this->cauda.begin(); x != this->cauda.end();x++){

          if(x==this->cauda.begin()){

            aux = std::make_pair(x->second.first, x->second.second);
            m[x->second.first][x->second.second] = 1;
            this->cauda[x->first] = std::make_pair(x->second.first-1, x->second.second);
            m[x->second.first][x->second.second] = 2;


          } else {

            auto aux2 = std::make_pair(x->second.first, x->second.second);
            m[x->second.first][x->second.second] = 1;
            this->cauda[x->first] = std::make_pair(aux.first, aux.second);
            m[x->second.first][x->second.second] = 2;

            aux = aux2;

          }

        }

      } else if(m[this->cauda.begin()->second.first-1][this->cauda.begin()->second.second] == 2){

        return "\033[1;31mVocê bateu em você mesma!\033[0m";

      } else if(m[this->cauda.begin()->second.first-1][this->cauda.begin()->second.second] == 0){

        return "\033[1;31mVocê bateu em uma parede!\033[0m";

      }

    } else if(d == Directions::ESQUERDA){
      if(m[this->cauda.begin()->second.first][this->cauda.begin()->second.second-1] == 1){
        pair<int,int> aux;
        for(auto x = this->cauda.begin(); x != this->cauda.end();x++){

          if(x==this->cauda.begin()){

            aux = std::make_pair(x->second.first, x->second.second);
            m[x->second.first][x->second.second] = 1;
            this->cauda[x->first] = std::make_pair(x->second.first, x->second.second-1);
            m[x->second.first][x->second.second] = 2;


          } else {

            auto aux2 = std::make_pair(x->second.first, x->second.second);
            m[x->second.first][x->second.second] = 1;
            this->cauda[x->first] = std::make_pair(aux.first, aux.second);
            m[x->second.first][x->second.second] = 2;

            aux = aux2;

          }

        }
      } else if(m[this->cauda.begin()->second.first][this->cauda.begin()->second.second-1] == 2){

        return "\033[1;31mVocê bateu em você mesma!\033[0m";

      } else if(m[this->cauda.begin()->second.first][this->cauda.begin()->second.second-1] == 0){

        return "\033[1;31mVocê bateu em uma parede!\033[0m";

      }

    } else if(d == Directions::DIREITA){
      if(m[this->cauda.begin()->second.first][this->cauda.begin()->second.second+1] == 1){
        pair<int,int> aux;
        for(auto x = this->cauda.begin(); x != this->cauda.end();x++){

          if(x==this->cauda.begin()){

            aux = std::make_pair(x->second.first, x->second.second);
            m[x->second.first][x->second.second] = 1;
            this->cauda[x->first] = std::make_pair(x->second.first, x->second.second+1);
            m[x->second.first][x->second.second] = 2;

          } else {

            auto aux2 = std::make_pair(x->second.first, x->second.second);
            m[x->second.first][x->second.second] = 1;
            this->cauda[x->first] = std::make_pair(aux.first, aux.second);
            m[x->second.first][x->second.second] = 2;

            aux = aux2;

            }

          }

        } else if(m[this->cauda.begin()->second.first][this->cauda.begin()->second.second+1] == 2){

          return "\033[1;31mVocê bateu em você mesma!\033[0m";

        } else if(m[this->cauda.begin()->second.first][this->cauda.begin()->second.second+1] == 0){

          return "\033[1;31mVocê bateu em uma parede!\033[0m";

        }
    }

    return "";
}

    void Snake::resetarCauda(vector<vector<int>> &m){
      int tempRow = this->cauda.begin()->second.first;
      int tempCol = this->cauda.begin()->second.second;

      for(auto x = this->cauda.begin(); x != this->cauda.end(); x++){

        m[x->second.first][x->second.second] = 1;

      }

      this->cauda.clear();
      this->numCauda = 0;
      iniciarPlayer(tempRow, tempCol, m);

    }

    //Getters

    int Snake::getVidas(){

      return this->vidas;

    }

    int Snake::getScore(){

      return this->score;

    }

    