#include "game.hpp"

Game::Game(std::vector<std::string> playerType){

    gameBoard = Board();

    std::map<std::string, int> playersTypeMap{
        {"randomPlayer", 0},
        {"realPlayer", 1}
    };

    for (int i=0; i<2; i++){
        switch (playersTypeMap[playerType[i]]) {
            case 0:
                playersMatrix.push_back(RandomPlayer());
                break;
            case 1: 
                playersMatrix.push_back(RealPlayer());
                break;
        }
    }
    std::cout << std::endl << "Welcome in game Pentago!" << std::endl;
    };

void Game::startGame(){
    
    setPlayer1("Tygrysek");
    setPlayer2("Pantera");

    std::cout 
        << "The game now begins! Have fun " 
        << Game::playersMatrix[0].getPlayerName() << " and " << playersMatrix[1].getPlayerName() << "!"
        << std::endl << std::endl;

    int counter = 0;
    int playerIdx = 0;
    while (counter < 2){
        playerIdx = counter%2;
        std::cout << "Round number: " << counter << std::endl;
        Game::gameBoard.printBoard();

        counter++;
    }
}