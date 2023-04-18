#include "game.hpp"

void Game::startGame(){
    std::cout << "Welcome " << Game::player1->getPlayerName() << " and " << Game::player2->getPlayerName() << std::endl;
    std::cout << "The game now begins! Have fun!" << std::endl;
}