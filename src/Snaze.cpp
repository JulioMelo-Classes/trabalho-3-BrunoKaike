#include <iostream>
#include <string.h>
#include "SnakeGame.h"

using namespace std;

int main(int argc, char *argv[]){
    SnakeGame game(argv[1]);
    
    if(strncmp(argv[2],"comRabo", 7) == 0){

      game.setComRabo(true);

    } else {

      game.setComRabo(false);

    }
    
    game.loop(); //bloqueia aqui e só saí quando o jogo termina

    return 0;
}