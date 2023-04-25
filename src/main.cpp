#include <iostream>
#include <string>
#include <vector>
#include "game.hpp"




int main(int argc, char * argv[]){

    srand( time( NULL ));
    
    Game game({"randomPlayer", "randomPlayer"});
    game.startGame(); 
    
    return 0;
}