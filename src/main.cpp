#include <iostream>
#include <string>
#include "game.hpp"

int main(int argc, char * argv[]){
    
    Game game;
    game.setPlayer1("Tygrysek");
    game.setPlayer2("Pantera");
    game.startGame();
    return 0;
}