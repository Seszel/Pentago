#include "game.hpp"

void Game::startGame(){
    
    setPlayer1("Tygrysek");
    setPlayer2("Pantera");

    std::cout 
        << "The game now begins! Have fun " 
        << Game::playersMatrix[0].getPlayerName() << " and " << playersMatrix[1].getPlayerName() << "!"
        << std::endl;

    Board board;

    int counter = 0;
    int playerIdx = 0;
    while (counter < 36){
        playerIdx = counter%2;
        // std::cout << playersMatrix[playerIdx].getPlayerName() << std::endl;

        counter++;
    }
}