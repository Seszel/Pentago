#include "game.hpp"

Game::Game(std::vector<std::string> playerType){

    gameBoard = Board();

    gameBoard.setAvailableMoves();

    std::map<std::string, int> playersTypeMap{
        {"randomPlayer", 0},
        {"randomPlayer", 1}
    };

    for (int i=0; i<2; i++){
        switch (playersTypeMap[playerType[i]]) {
            case 0:
                playersMatrix.emplace_back(new RandomPlayer);
                break;
            case 1: 
                playersMatrix.emplace_back(new RandomPlayer);
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
        << Game::playersMatrix[0]->getPlayerName() << " and " << playersMatrix[1]->getPlayerName() << "!"
        << std::endl << std::endl;

    int counter = 0;
    int playerIdx = 0;
    Move move;
    while (counter < 20){
        playerIdx = counter%2;
        if (counter%2==0) {
            std::cout << "Round number: " << counter / 2 << std::endl << std::endl;
        }
        std::cout << Game::playersMatrix[playerIdx]->getPlayerName() << "'s move" << std::endl;

        Game::playersMatrix[playerIdx]->setMove(Game::gameBoard.getAvailableMoves(), playerIdx);

        move = Game::playersMatrix[playerIdx]->getMove();

        Game::makeAMove(move);

        gameBoard.setAvailableMoves();

        Game::gameBoard.printBoard();
        
        counter++;

    }
}


void Game::makeAMove(Move move){
    Game::gameBoard.changeBoard(move);
}
