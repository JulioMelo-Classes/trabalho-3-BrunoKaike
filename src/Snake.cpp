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

    string Snake::executarSolucao(vector<vector<int>> &m,int dimRows, int dimCols, int rFinish, int cFinish){

      IA.setarSolucao(m, dimRows, dimCols , this->cauda.begin()->second.first, this->cauda.begin()->second.second, rFinish, cFinish);
      string saida;
      saida = mover(IA.proximoMovimento(), m, rFinish, cFinish);
      return saida;

    }

    //Subtraction

    void Snake::diminuirVida(){

      this->vidas--;

    }

    //adders

    void Snake::aumentarScore(){

      this->score += 50;

    }

    void Snake::iniciarPlayer(int R, int C, vector<vector<int>> &m){

      this->cauda[this->numCauda] = std::make_pair(R, C);
      m[R][C] = 2;
      this->numCauda++;

    }

    bool Snake::aumentarCauda(vector<vector<int>> &m){
      if(possuiRabo){

        auto last = this->cauda.end();
        last--;
        if(m[last->second.first-1][last->second.second] == 1 && this->ultimoMovimento != Directions::CIMA){

          this->cauda[this->numCauda] = std::make_pair(last->second.first-1, last->second.second);
          m[last->second.first-1][last->second.second] = 2;

        } else if(m[last->second.first+1][last->second.second] == 1 && this->ultimoMovimento != Directions::BAIXO){

          this->cauda[this->numCauda] = std::make_pair(last->second.first+1, last->second.second);
          m[last->second.first+1][last->second.second] = 2;

        } else if(m[last->second.first][last->second.second+1] == 1 && this->ultimoMovimento != Directions::DIREITA){

          this->cauda[this->numCauda] = std::make_pair(last->second.first, last->second.second+1);
          m[last->second.first][last->second.second+1] = 2;

        } else if(m[last->second.first][last->second.second-1] == 1 && this->ultimoMovimento != Directions::ESQUERDA){

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

    string Snake::mover(Directions d, vector<vector<int>> &m, int rFinish, int cFinish){
    //cout << this->cauda.begin()->second.first << " - " << this->cauda.begin()->second.second << endl;
    if(this->cauda.begin()->second.first == rFinish && this->cauda.begin()->second.second == cFinish){
      return "chegou";

    }

    if(d == Directions::BAIXO){
      if(m[this->cauda.begin()->second.first+1][this->cauda.begin()->second.second] == 1 || m[this->cauda.begin()->second.first+1][this->cauda.begin()->second.second] == 4){
          pair<int,int> aux;
          pair<int,int> aux2;
          for(auto x = this->cauda.begin(); x != this->cauda.end();x++){
            
            if(x==this->cauda.begin()){

              aux = std::make_pair(x->second.first, x->second.second);
              m[x->second.first][x->second.second] = 1;
              this->cauda[x->first] = std::make_pair(x->second.first+1, x->second.second);
              m[x->second.first][x->second.second] = 2;


            } else {

              aux2 = std::make_pair(x->second.first, x->second.second);
              m[x->second.first][x->second.second] = 1;
              this->cauda[x->first] = std::make_pair(aux.first, aux.second);
              m[x->second.first][x->second.second] = 2;

              aux = aux2;

            }

          }

          this->ultimoMovimento = Directions::BAIXO;

        } else if(m[this->cauda.begin()->second.first+1][this->cauda.begin()->second.second] == 2){

          return "\033[1;31mVocê bateu em você mesma!\033[0m";

        }  else if(m[this->cauda.begin()->second.first+1][this->cauda.begin()->second.second] == 0){

          return "\033[1;31mVocê bateu em uma parede!\033[0m";

        }

    } else if(d == Directions::CIMA){
      if(m[this->cauda.begin()->second.first-1][this->cauda.begin()->second.second] == 1 || m[this->cauda.begin()->second.first-1][this->cauda.begin()->second.second] == 4){
        pair<int,int> aux;
        pair<int,int> aux2;
        for(auto x = this->cauda.begin(); x != this->cauda.end();x++){

          if(x==this->cauda.begin()){

            aux = std::make_pair(x->second.first, x->second.second);
            m[x->second.first][x->second.second] = 1;
            this->cauda[x->first] = std::make_pair(x->second.first-1, x->second.second);
            m[x->second.first][x->second.second] = 2;


          } else {

            aux2 = std::make_pair(x->second.first, x->second.second);
            m[x->second.first][x->second.second] = 1;
            this->cauda[x->first] = std::make_pair(aux.first, aux.second);
            m[x->second.first][x->second.second] = 2;

            aux = aux2;

          }

        }

        this->ultimoMovimento = Directions::CIMA;

      } else if(m[this->cauda.begin()->second.first-1][this->cauda.begin()->second.second] == 2){

        return "\033[1;31mVocê bateu em você mesma!\033[0m";

      } else if(m[this->cauda.begin()->second.first-1][this->cauda.begin()->second.second] == 0){

        return "\033[1;31mVocê bateu em uma parede!\033[0m";

      }

    } else if(d == Directions::ESQUERDA){
      if(m[this->cauda.begin()->second.first][this->cauda.begin()->second.second-1] == 1 || m[this->cauda.begin()->second.first][this->cauda.begin()->second.second-1] == 4){
        pair<int,int> aux;
        pair<int,int> aux2;
        for(auto x = this->cauda.begin(); x != this->cauda.end();x++){

          if(x==this->cauda.begin()){

            aux = std::make_pair(x->second.first, x->second.second);
            m[x->second.first][x->second.second] = 1;
            this->cauda[x->first] = std::make_pair(x->second.first, x->second.second-1);
            m[x->second.first][x->second.second] = 2;


          } else {

            aux2 = std::make_pair(x->second.first, x->second.second);
            m[x->second.first][x->second.second] = 1;
            this->cauda[x->first] = std::make_pair(aux.first, aux.second);
            m[x->second.first][x->second.second] = 2;

            aux = aux2;

          }

        }

        this->ultimoMovimento = Directions::ESQUERDA;

      } else if(m[this->cauda.begin()->second.first][this->cauda.begin()->second.second-1] == 2){

        return "\033[1;31mVocê bateu em você mesma!\033[0m";

      } else if(m[this->cauda.begin()->second.first][this->cauda.begin()->second.second-1] == 0){

        return "\033[1;31mVocê bateu em uma parede!\033[0m";

      }

    } else if(d == Directions::DIREITA){
      if(m[this->cauda.begin()->second.first][this->cauda.begin()->second.second+1] == 1 || m[this->cauda.begin()->second.first][this->cauda.begin()->second.second+1] == 4){
        pair<int,int> aux;
        pair<int,int> aux2;
        for(auto x = this->cauda.begin(); x != this->cauda.end();x++){

          if(x==this->cauda.begin()){

            aux = std::make_pair(x->second.first, x->second.second);
            m[x->second.first][x->second.second] = 1;
            this->cauda[x->first] = std::make_pair(x->second.first, x->second.second+1);
            m[x->second.first][x->second.second] = 2;

          } else {

            aux2 = std::make_pair(x->second.first, x->second.second);
            m[x->second.first][x->second.second] = 1;
            this->cauda[x->first] = std::make_pair(aux.first, aux.second);
            m[x->second.first][x->second.second] = 2;

            aux = aux2;

            }

          }

          this->ultimoMovimento = Directions::DIREITA;

        } else if(m[this->cauda.begin()->second.first][this->cauda.begin()->second.second+1] == 2){

          return "\033[1;31mVocê bateu em você mesma!\033[0m";

        } else if(m[this->cauda.begin()->second.first][this->cauda.begin()->second.second+1] == 0){

          return "\033[1;31mVocê bateu em uma parede!\033[0m";

        }
    } 

    return "";
}

    void Snake::resetarCauda(vector<vector<int>> &m, pair<int,int> &spawn){

      for(auto x = this->cauda.begin(); x != this->cauda.end(); x++){

        m[x->second.first][x->second.second] = 1;

      }

      for(int x = numCauda; x >= 0; x--){
          auto it = this->cauda.find(x);             
	        this->cauda.erase ( this->cauda.begin() , it );   

      }

      this->numCauda = 0;
      iniciarPlayer(spawn.first, spawn.second, m);

    }

    //Getters

    int Snake::getVidas(){

      return this->vidas;

    }

    int Snake::getScore(){

      return this->score;

    }

    