#include "game.hpp"

Game::Game(std::vector<std::string> playerType){

    win = false;

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
    while (!win || Game::gameBoard.getAvailableMoves().size() == 0){
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

        Game::checkWin(playerIdx);

        counter++;

    }

    if (win){
        for (int winnerIdx : winner){
            std::cout << "The winner is " << Game::playersMatrix[winnerIdx]->getPlayerName() << std::endl;
        }
    }
}


void Game::makeAMove(Move move){
    Game::gameBoard.changeBoard(move);
}

void Game::checkWin(int playerIdx)
{

    auto gameBoardMatrix = gameBoard.getBoardMatrix();
    int blackCount;
    int whiteCount;
    bool black = false;
    bool white = false;
    for (int i = 0; i<gameBoardMatrix.size(); i++){

        if (!black){

            blackCount = count(gameBoardMatrix[i].begin(), gameBoardMatrix[i].end(), -1);
            if (blackCount >= 5){
                if (gameBoardMatrix[i][0] != -1 || gameBoardMatrix[i][gameBoardMatrix[i].size()] != -1){
                    win = true;
                    winner.push_back(0);
                    black = true;
                }
            }
        }
        if (!black){

            blackCount = 0;
            for (int j=0; j<gameBoardMatrix[i].size(); j++){
                if (gameBoard.getBoardMatrix()[i][j] == -1){
                    blackCount++;
                }
            }
            if (blackCount >= 5){
                if (gameBoardMatrix[i][0] != -1 || gameBoardMatrix[i][gameBoardMatrix[i].size()] != -1){
                    win = true;
                    winner.push_back(0);
                    black = true;
                }
            }
        }


        if (!white){

            whiteCount = count(gameBoardMatrix[i].begin(), gameBoardMatrix[i].end(), 1);
            if (whiteCount >= 5){
                if (gameBoardMatrix[i][0] != 1 || gameBoardMatrix[i][gameBoardMatrix[i].size()] != 1){
                    win = true;
                    winner.push_back(1);
                    black = true;
                }
            }
        }
        if (!white){

            whiteCount = 0;
            for (int j=0; j<gameBoardMatrix[i].size(); j++){
                if (gameBoardMatrix[i][j] == 1){
                    whiteCount++;
                }
            }
            if (whiteCount >= 5){
                if (gameBoardMatrix[i][0] != 1 || gameBoardMatrix[i][gameBoardMatrix[i].size()] != 1){
                    win = true;
                    winner.push_back(1);
                    black = true;
                }
            }
        }

        if (black && white){
            break;
        } 
    }

    if (!black){
            if (
                (gameBoardMatrix[0][1] == -1 
                && gameBoardMatrix[1][2] == -1 
                && gameBoardMatrix[2][3] == -1 
                && gameBoardMatrix[3][4] == -1 
                && gameBoardMatrix[4][5] == -1)
                ||
                (gameBoardMatrix[1][0] == -1 
                && gameBoardMatrix[2][1] == -1 
                && gameBoardMatrix[3][2] == -1 
                && gameBoardMatrix[4][3] == -1 
                && gameBoardMatrix[5][4] == -1)
            ) {
                win = true;
                winner.push_back(0);
                black = true;
            }
        } 
        if (!black){
            if (
                (gameBoardMatrix[0][0] == -1 
                && gameBoardMatrix[1][1] == -1 
                && gameBoardMatrix[2][2] == -1 
                && gameBoardMatrix[3][3] == -1 
                && gameBoardMatrix[4][4] == -1)
                ||
                (gameBoardMatrix[1][1] == -1 
                && gameBoardMatrix[2][2] == -1 
                && gameBoardMatrix[3][3] == -1 
                && gameBoardMatrix[4][4] == -1 
                && gameBoardMatrix[5][5] == -1)
            ) {
                win = true;
                winner.push_back(0);
                black = true;
            }
        }

        if (!white){
            if (
                (gameBoardMatrix[0][1] == 1 
                && gameBoardMatrix[1][2] == 1 
                && gameBoardMatrix[2][3] == 1 
                && gameBoardMatrix[3][4] == 1 
                && gameBoardMatrix[4][5] == 1)
                ||
                (gameBoardMatrix[1][0] == 1 
                && gameBoardMatrix[2][1] == 1 
                && gameBoardMatrix[3][2] == 1 
                && gameBoardMatrix[4][3] == 1 
                && gameBoardMatrix[5][4] == 1)
            ) {
                win = true;
                winner.push_back(1);
                white = true;
            }
        }
        if (!white){
            if (
                (gameBoardMatrix[0][0] == 1 
                && gameBoardMatrix[1][1] == 1 
                && gameBoardMatrix[2][2] == 1 
                && gameBoardMatrix[3][3] == 1 
                && gameBoardMatrix[4][4] == 1)
                ||
                (gameBoardMatrix[1][1] == 1 
                && gameBoardMatrix[2][2] == 1 
                && gameBoardMatrix[3][3] == 1 
                && gameBoardMatrix[4][4] == 1 
                && gameBoardMatrix[5][5] == 1)
            ) {
                win = true;
                winner.push_back(1);
                white = true;
            }
        }
}
