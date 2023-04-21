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

            blackCount = count(gameBoardMatrix[i].begin(), gameBoardMatrix[i].end(), 'B');
            if (blackCount == 5){
                if (gameBoardMatrix[i][0] != 'B' || gameBoardMatrix[i][gameBoardMatrix[i].size()-1] != 'B'){
                    win = true;
                    winner.push_back(0);
                    black = true;
                }
            } else if (blackCount == 6){
                win = true;
                winner.push_back(0);
                black = true;
            }
        }
        if (!black){

            blackCount = 0;
            for (int j=0; j<gameBoardMatrix[i].size(); j++){
                if (gameBoard.getBoardMatrix()[i][j] == 'B'){
                    blackCount++;
                }
            }
            if (blackCount == 5){
                if (gameBoardMatrix[0][i] != 'B' || gameBoardMatrix[gameBoardMatrix[i].size()-1][i] != 'B'){
                    win = true;
                    winner.push_back(0);
                    black = true;
                }
            }
            else if (blackCount == 6){
                win = true;
                winner.push_back(0);
                black = true;
            }
        }


        if (!white){

            whiteCount = count(gameBoardMatrix[i].begin(), gameBoardMatrix[i].end(), 'W');
            if (whiteCount == 5){
                if (gameBoardMatrix[i][0] != 'W' || gameBoardMatrix[i][gameBoardMatrix[i].size()-1] != 'W'){
                    win = true;
                    winner.push_back(1);
                    white = true;
                }
            }
            else if (whiteCount == 6){
                win = true;
                winner.push_back(1);
                white = true;
            }
        }
        if (!white){

            whiteCount = 0;
            for (int j=0; j<gameBoardMatrix[i].size(); j++){
                if (gameBoardMatrix[i][j] == 'W'){
                    whiteCount++;
                }
            }
            if (whiteCount == 5){
                if (gameBoardMatrix[0][i] != 'W' || gameBoardMatrix[gameBoardMatrix[i].size()-1][i] != 'W'){
                    win = true;
                    winner.push_back(1);
                    white = true;
                }
            }
            else if (whiteCount == 6){
                win = true;
                winner.push_back(1);
                white = true;
            }
        }

        if (black && white){
            break;
        } 
    }

    if (!black){
            if (
                (gameBoardMatrix[0][1] == 'B' 
                && gameBoardMatrix[1][2] == 'B' 
                && gameBoardMatrix[2][3] == 'B' 
                && gameBoardMatrix[3][4] == 'B' 
                && gameBoardMatrix[4][5] == 'B')
                ||
                (gameBoardMatrix[1][0] == 'B'
                && gameBoardMatrix[2][1] == 'B' 
                && gameBoardMatrix[3][2] == 'B'
                && gameBoardMatrix[4][3] == 'B'
                && gameBoardMatrix[5][4] == 'B')
                ||
                (gameBoardMatrix[4][0] == 'B' 
                && gameBoardMatrix[3][1] == 'B' 
                && gameBoardMatrix[2][2] == 'B' 
                && gameBoardMatrix[1][3] == 'B' 
                && gameBoardMatrix[0][4] == 'B')
                ||
                (gameBoardMatrix[5][1] == 'B'
                && gameBoardMatrix[4][2] == 'B' 
                && gameBoardMatrix[3][3] == 'B'
                && gameBoardMatrix[2][4] == 'B'
                && gameBoardMatrix[1][5] == 'B')
            ) {
                win = true;
                winner.push_back(0);
                black = true;
            }
        } 
        if (!black){
            if (
                (gameBoardMatrix[0][0] == 'B' 
                && gameBoardMatrix[1][1] == 'B' 
                && gameBoardMatrix[2][2] == 'B' 
                && gameBoardMatrix[3][3] == 'B' 
                && gameBoardMatrix[4][4] == 'B')
                ||
                (gameBoardMatrix[1][1] == 'B'
                && gameBoardMatrix[2][2] == 'B' 
                && gameBoardMatrix[3][3] == 'B'
                && gameBoardMatrix[4][4] == 'B'
                && gameBoardMatrix[5][5] == 'B')
                ||
                (gameBoardMatrix[4][1] == 'B' 
                && gameBoardMatrix[3][2] == 'B' 
                && gameBoardMatrix[2][3] == 'B' 
                && gameBoardMatrix[1][4] == 'B' 
                && gameBoardMatrix[0][5] == 'B')
                ||
                (gameBoardMatrix[5][0] == 'B' 
                && gameBoardMatrix[4][1] == 'B' 
                && gameBoardMatrix[3][2] == 'B' 
                && gameBoardMatrix[2][3] == 'B' 
                && gameBoardMatrix[1][4] == 'B')
            ) {
                win = true;
                winner.push_back(0);
                black = true;
            }
        }

        if (!white){
            if (
                (gameBoardMatrix[0][1] == 'W'
                && gameBoardMatrix[1][2] == 'W' 
                && gameBoardMatrix[2][3] == 'W' 
                && gameBoardMatrix[3][4] == 'W' 
                && gameBoardMatrix[4][5] == 'W')
                ||
                (gameBoardMatrix[1][0] ==  'W'
                && gameBoardMatrix[2][1] == 'W'
                && gameBoardMatrix[3][2] == 'W'
                && gameBoardMatrix[4][3] == 'W' 
                && gameBoardMatrix[5][4] == 'W')
                ||
                (gameBoardMatrix[4][0] == 'W' 
                && gameBoardMatrix[3][1] == 'W' 
                && gameBoardMatrix[2][2] == 'W' 
                && gameBoardMatrix[1][3] == 'W' 
                && gameBoardMatrix[0][4] == 'W')
                ||
                (gameBoardMatrix[5][1] == 'W'
                && gameBoardMatrix[4][2] == 'W'
                && gameBoardMatrix[3][3] == 'W'
                && gameBoardMatrix[2][4] == 'W'
                && gameBoardMatrix[1][5] == 'W')
            ) {
                win = true;
                winner.push_back(1);
                white = true;
            }
        }
        if (!white){
            if (
                (gameBoardMatrix[0][0] == 'W' 
                && gameBoardMatrix[1][1] == 'W' 
                && gameBoardMatrix[2][2] == 'W'
                && gameBoardMatrix[3][3] == 'W' 
                && gameBoardMatrix[4][4] == 'W')
                ||
                (gameBoardMatrix[1][1] == 'W' 
                && gameBoardMatrix[2][2] == 'W' 
                && gameBoardMatrix[3][3] == 'W' 
                && gameBoardMatrix[4][4] == 'W' 
                && gameBoardMatrix[5][5] == 'W')
                ||
                (gameBoardMatrix[4][1] == 'W' 
                && gameBoardMatrix[3][2] == 'W' 
                && gameBoardMatrix[2][3] == 'W' 
                && gameBoardMatrix[1][4] == 'W' 
                && gameBoardMatrix[0][5] == 'W')
                ||
                (gameBoardMatrix[5][0] == 'W' 
                && gameBoardMatrix[4][1] == 'W' 
                && gameBoardMatrix[3][2] == 'W' 
                && gameBoardMatrix[2][3] == 'W' 
                && gameBoardMatrix[1][4] == 'W')
            ) {
                win = true;
                winner.push_back(1);
                white = true;
            }
        }
}
