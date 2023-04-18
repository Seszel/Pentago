#include <iostream>
#include <string>
#include "game.hpp"

int main(int argc, char * argv[]){
    
    Game game;
    game.setPlayer1();
    game.setPlayer2();
    std::cout << game.getPlayer1().getPlayerName();
    // game.startGame();
    return 0;
}