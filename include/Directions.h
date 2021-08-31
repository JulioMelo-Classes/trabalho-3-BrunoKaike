#ifndef DIRECTIONS_H
#define DIRECTIONS_H
#include <iostream>

  enum class Directions{
      CIMA, //<! quando o jogo está executando o estado é RUNNING
      BAIXO, //<! quando o jogo deve terminar o estado é GAME_OVER
      DIREITA,
      ESQUERDA //<! quando o jogo deve esperar por uma entrada do usuário o estado é WAITING_USER
    };

#endif