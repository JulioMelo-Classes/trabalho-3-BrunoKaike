#include "SnakeGame.h"
#include "../include/Level.h"
#include "../include/Snake.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep
#include <string>

using namespace std;

SnakeGame::SnakeGame(string diretorio){
    choice = "";
    frameCount = 0;
    initialize_game(diretorio);
}

void SnakeGame::resetarLevel(vector<int> &levelData, int &lineCount, int &qtdSpawnPlayer){

    maze.clear();
    levelData.clear();
    lineCount = 0;
    qtdSpawnPlayer = 0;

}

void SnakeGame::lerLevel(std::ifstream& levelFile){

    Level level;
    int temp;
    int lineCount = 0;
    string linha;
    stringstream ss;
    int qtdSpawnPlayer = 0;
    vector<int> levelData;

    if(levelFile.is_open()){
        while(getline(levelFile, linha)){
            if(lineCount > 0){

                for(int r = 0; r < levelData[0]; r++){

                    maze.push_back(std::vector<int>());

                    for(int c = 0; c < levelData[1]; c++){

                        if(linha[c] == '#'){

                            maze[r].push_back(0);

                        } else if(linha[c] == ' '){

                            maze[r].push_back(1);

                        } else if(linha[c] == '*'){

                            maze[r].push_back(2);
                            level.setPlayerSpawn(std::make_pair(r, c));
                            qtdSpawnPlayer++;

                        } else if(linha[c] == '.'){

                            maze[r].push_back(3);

                        }
                    }

                    if(r < levelData[0]-1){
                        getline(levelFile, linha);
                    }
                    lineCount++;

                }
                if(qtdSpawnPlayer==1){
                    levels.push_back(level);
                    levelAtual++;
                    return;

                } else if(qtdSpawnPlayer==0){
                  levels.push_back(level);
                  levels[levelAtual].gerarPlayerSpawn(maze);
                  levelAtual++;
                  return;

                } else {

                    resetarLevel(levelData, lineCount, qtdSpawnPlayer);

                }
                resetarLevel(levelData, lineCount, qtdSpawnPlayer);

            } else {

                size_t start;
                size_t end = 0;

                while ((start = linha.find_first_not_of(" ", end)) != std::string::npos){
                    end = linha.find(" ", start);
                    ss.clear();
                    ss << linha.substr(start, end - start);
                    ss >> temp;
                    levelData.push_back(temp);
                }

                level = Level(std::make_pair(levelData[0],levelData[1]), levelData[2]);

                if(levelData[0] <= 0 || levelData[1] <= 0){

                    cout << "\033[1;31mNúmero de linhas e/ou colunas inválidos(Dimensões inferiores ou iguais 0)\033[0m" << endl;
                    state = GAME_OVER;
                    game_over();
                    break;

                } else if(levelData[0] > 100 || levelData[1] > 100){

                    cout << "\033[1;31mNúmero de linhas e/ou colunas inválidos(Dimensões superiores a 100)\033[0m" << endl;
                    state = GAME_OVER;
                    game_over();
                    break;

                }

                lineCount++;
            }


        }

    }


}

void SnakeGame::initialize_game(string diretorio){
    //carrega o nivel ou os níveis
    ifstream levelFile; //só dá certo se o jogo for executado dentro da raíz do diretório (vc vai resolver esse problema pegando o arquivo da linha de comando)
    levelFile.open(diretorio);
    lerLevel(levelFile);

    if(state != GAME_OVER){
      this->s = Snake(levels[levelAtual-1].getPlayerSpawn(), this->comRabo);
      s.resetarCauda(maze, levels[levelAtual-1].getPlayerSpawn());
      levels[levelAtual-1].inicializarComidas(maze);
      levels[levelAtual-1].adicionarComidaNoMapa(maze);
      
      imprimirMapa(levels[levelAtual-1].getDimensaoRow(), levels[levelAtual-1].getDimensaoCol());

      state = RUNNING;

    }
    //state = GAME_OVER;
}



void SnakeGame::process_actions(){
    //processa as entradas do jogador de acordo com o estado do jogo
    //nesse exemplo o jogo tem 3 estados, WAITING_USER, RUNNING e GAME_OVER.
    //no caso deste trabalho temos 2 tipos de entrada, uma que vem da classe Player, como resultado do processamento da IA
    //outra vem do próprio usuário na forma de uma entrada do teclado.
    switch(state){
        case WAITING_USER: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
            cin>>std::ws>>choice;
            break;
        case RUNNING:
            
            if(s.getVidas()>0){
              if(levels[levelAtual-1].getComidasRestantes() > 0){
                string saida = s.executarSolucao(maze, levels[levelAtual-1].getDimensaoRow(), levels[levelAtual-1].getDimensaoCol(), levels[levelAtual-1].getPosComidaAtualRow(), levels[levelAtual-1].getPosComidaAtualCol());
                if(saida == "chegou"){
                  render();
                  if(this->comRabo){
                    s.aumentarCauda(maze);
                  }
                  s.aumentarScore();
                  levels[levelAtual-1].aumentarComidaColetada();
                  //state = GAME_OVER;
                  //game_over();
                  levels[levelAtual-1].adicionarComidaNoMapa(maze);

                } else if(saida == ""){
                  
                
                } else {
                  //state = GAME_OVER;
                  //game_over();
                  cout << saida << endl;
                  s.diminuirVida();
                  s.resetarCauda(maze, levels[levelAtual-1].getPlayerSpawn());

                }

              } else {
                
                cout << "Você venceu!" << endl;
                state = GAME_OVER;
                game_over();

              }

            } else {
              cout << "Suas vidas acabaram" << endl;
              state = GAME_OVER;
              game_over();

            }
          
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

void SnakeGame::update(){
    //atualiza o estado do jogo de acordo com o resultado da chamada de "process_input"
    switch(state){
        case RUNNING:
            if(frameCount>0 && frameCount%10 == 0) //depois de 10 frames o jogo pergunta se o usuário quer continuar
                //state = WAITING_USER;
            break;
        case WAITING_USER: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if(choice == "n"){
                state = GAME_OVER;
                game_over();
            }
            else{
                //pode fazer alguma coisa antes de fazer isso aqui
                state = RUNNING;
            }
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

/**
 * @brief função auxiliar para fazer o programa esperar por alguns milisegundos
 * @param ms a quantidade de segundos que o programa deve esperar
 */
void wait(int ms){
    this_thread::sleep_for(chrono::milliseconds(ms));
}

/**
 * @brief função auxiliar para limpar o terminal
 */
void clearScreen(){
//some C++ voodoo here ;D
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void SnakeGame::render(){
    clearScreen();
    switch(state){
        case RUNNING:
            //desenha todas as linhas do labirinto
            imprimirCabecalho();
            imprimirMapa(levels[levelAtual-1].getDimensaoRow(), levels[levelAtual-1].getDimensaoCol());
            break;
        case WAITING_USER:
            cout<<"Você quer continuar com o jogo? (s/n)"<<endl;
            break;
        case GAME_OVER:
            cout<<"O jogo terminou!"<<endl;
            break;
    }
    frameCount++;
}

void SnakeGame::game_over(){
}

void SnakeGame::loop(){
  
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(1000);// espera 1 segundo entre cada frame
    }
}

void SnakeGame::imprimirCabecalho(){
  const char heart[] = "\xe2\x99\xa5";
  cout << "Vidas: ";

  for(int x = 0; x < this->s.getVidas(); x++){

    cout << "\033[1;31m" << heart << "\033[0m ";
    
  }

  for(int x = 0; x < 5-this->s.getVidas(); x++){

    cout << "  ";

  }

  cout << " | Score: " << this->s.getScore();
  cout << " | Comidas coletadas: " << this->levels[levelAtual-1].getComidasColetada() << " de " << this->levels[levelAtual-1].getComidasTotal();
  cout << endl;

}

void SnakeGame::imprimirMapa(int col, int row){
    const char comida[] = "\xE2\x97\x8F";
    const char cobra[] = "\xE2\xAC\xA3";

    for(int x = 0; x < col; x++){

        for(int y = 0; y < row; y++){
            if(maze[x][y]==0){
              
              cout << "\033[1;33m#\033[0m ";
              
            } else if(maze[x][y]==1){
              
              cout << "  ";

            } else if(maze[x][y]==2){
              
              cout << "\033[1;32m"<< cobra <<"\033[0m ";

            } else if(maze[x][y]==3){
              
              cout << "  ";

            } else if(maze[x][y]==4){
              
              cout << "\033[1;35m" << comida << "\033[0m ";

            }

        }

        cout << endl;
    }

}

void SnakeGame::setComRabo(bool comRabo){

  this->comRabo = comRabo;

}
