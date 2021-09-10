#ifndef SnakeGame_h
#define SnakeGame_h
#include <iostream>
#include <fstream>
#include <vector>
#include "Level.h"
#include "Snake.h"

class SnakeGame{
    public:
        /**
        * @brief descreve os possíveis estados do jogo, fique à vontade para adicionar outros se necessário
        **/
        enum GameStates{
            RUNNING, //<! quando o jogo está executando o estado é RUNNING
            GAME_OVER, //<! quando o jogo deve terminar o estado é GAME_OVER
            WAITING_USER //<! quando o jogo deve esperar por uma entrada do usuário o estado é WAITING_USER
        };

    private:
        int levelAtual = 0;
        Snake s;
        std::vector<Level> levels;
        //<! atributos adicione outros se quiser
        std::vector<std::vector<int>> maze; //<! vector contendo o labirinto atual, pode ser interpretado como uma matriz
        int frameCount; //<! contador de frames, usado apenas como exemplo
        std::string choice; //<! usado na função process_actions para guardar a escolha do usuário
        GameStates state; //<! guarda o estado do jogo

    public:
        /**
        * @brief construtor padrão, fique à vontade para adicionar parâmetros se desejar
        **/
        SnakeGame();

        /**
        * @brief chamado no main, este loop executa o jogo indefinidamente até que o usuário escolha terminar!
        */
        void loop();

    private:

        void imprimirCabecalho();

        void imprimirMapa(int col, int row);

        void resetarLevel(std::vector<int> &levelData, int &lineCount, int &qtdSpawnPlayer);

        void lerLevel(std::ifstream& levelFile);
        /**
        * @brief realiza a inicialização geral do jogo, fique à vontade para adicionar parâmetros se achar que deve
        **/
        void initialize_game();

        /**
        * @brief atualiza o estado do jogo, basicamente movendo os objetos, sorteando novas posições de comida
        **/
        void update();

        /**
        * @brief processa as entradas do jogador
        **/
        void process_actions();

        /**
        * @brief testa o estado do jogo e desenha a tela correspondente
        **/
        void render();

        /**
        * @brief é chamada quando o jogo termina a fim de destruir/resetar elementos do estado do jogo
        **/
        void game_over();
};

#endif //SnakeGame_h
