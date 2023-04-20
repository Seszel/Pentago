#include <iostream>
#include <string>
#include <vector>
#include "game.hpp"

int main(int argc, char * argv[]){
    
    Game game({"randomPlayer", "Player"});
    game.startGame(); 
    
    return 0;
}