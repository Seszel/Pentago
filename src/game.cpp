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
        << playersMatrix[0]->getPlayerName() << " and " << playersMatrix[1]->getPlayerName() << "!"
        << std::endl << std::endl;

    int counter = 0;
    int playerIdx = 0;
    Move move;
    while (!win && counter < 36){
        playerIdx = counter%2;
        if (counter%2==0) {
            std::cout << "Round number: " << counter / 2 << std::endl << std::endl;
        }
        std::cout << playersMatrix[playerIdx]->getPlayerName() << "'s move, " << playersMatrix[playerIdx]->getColorName() << std::endl;

        playersMatrix[playerIdx]->setMove(gameBoard.getAvailableMoves(), playerIdx);

        move = playersMatrix[playerIdx]->getMove();

        makeAMove(move);

        gameBoard.setAvailableMoves();

        gameBoard.printBoard();

        checkWin(playerIdx);

        counter++;

    }

    if (win){
        for (int winnerIdx : winner){
            std::cout << "The winner is " << playersMatrix[winnerIdx]->getPlayerName() << " with color " << playersMatrix[winnerIdx]->getColorName() << std::endl;
        }
    } else {
        std::cout << "Nobody won. Try again!" << std::endl;
    }
}


void Game::makeAMove(Move move){
    gameBoard.changeBoard(move);
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

            blackCount = count(gameBoardMatrix[i].begin(), gameBoardMatrix[i].end(), Color::black);
            if (blackCount == 5){
                if (gameBoardMatrix[i][0] != Color::black || gameBoardMatrix[i][gameBoardMatrix[i].size()-1] != Color::black){
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
                if (gameBoard.getBoardMatrix()[j][i] == Color::black){
                    blackCount++;
                }
            }
            if (blackCount == 5){
                if (gameBoardMatrix[0][i] != Color::black || gameBoardMatrix[gameBoardMatrix[i].size()-1][i] != Color::black){
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

            whiteCount = count(gameBoardMatrix[i].begin(), gameBoardMatrix[i].end(), Color::white);
            if (whiteCount == 5){
                if (gameBoardMatrix[i][0] != Color::white || gameBoardMatrix[i][gameBoardMatrix[i].size()-1] != Color::white){
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
                if (gameBoardMatrix[j][i] == Color::white){
                    whiteCount++;
                }
            }
            if (whiteCount == 5){
                if (gameBoardMatrix[0][i] != Color::white || gameBoardMatrix[gameBoardMatrix[i].size()-1][i] != Color::white){
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
                (gameBoardMatrix[0][1] == Color::black 
                && gameBoardMatrix[1][2] == Color::black 
                && gameBoardMatrix[2][3] == Color::black 
                && gameBoardMatrix[3][4] == Color::black 
                && gameBoardMatrix[4][5] == Color::black)
                ||
                (gameBoardMatrix[1][0] == Color::black
                && gameBoardMatrix[2][1] == Color::black 
                && gameBoardMatrix[3][2] == Color::black
                && gameBoardMatrix[4][3] == Color::black
                && gameBoardMatrix[5][4] == Color::black)
                ||
                (gameBoardMatrix[4][0] == Color::black 
                && gameBoardMatrix[3][1] == Color::black 
                && gameBoardMatrix[2][2] == Color::black 
                && gameBoardMatrix[1][3] == Color::black 
                && gameBoardMatrix[0][4] == Color::black)
                ||
                (gameBoardMatrix[5][1] == Color::black
                && gameBoardMatrix[4][2] == Color::black 
                && gameBoardMatrix[3][3] == Color::black
                && gameBoardMatrix[2][4] == Color::black
                && gameBoardMatrix[1][5] == Color::black)
            ) {
                win = true;
                winner.push_back(0);
                black = true;
            }
        } 
        if (!black){
            if (
                (gameBoardMatrix[0][0] == Color::black 
                && gameBoardMatrix[1][1] == Color::black 
                && gameBoardMatrix[2][2] == Color::black 
                && gameBoardMatrix[3][3] == Color::black 
                && gameBoardMatrix[4][4] == Color::black)
                ||
                (gameBoardMatrix[1][1] == Color::black
                && gameBoardMatrix[2][2] == Color::black 
                && gameBoardMatrix[3][3] == Color::black
                && gameBoardMatrix[4][4] == Color::black
                && gameBoardMatrix[5][5] == Color::black)
                ||
                (gameBoardMatrix[4][1] == Color::black 
                && gameBoardMatrix[3][2] == Color::black 
                && gameBoardMatrix[2][3] == Color::black 
                && gameBoardMatrix[1][4] == Color::black 
                && gameBoardMatrix[0][5] == Color::black)
                ||
                (gameBoardMatrix[5][0] == Color::black 
                && gameBoardMatrix[4][1] == Color::black 
                && gameBoardMatrix[3][2] == Color::black 
                && gameBoardMatrix[2][3] == Color::black 
                && gameBoardMatrix[1][4] == Color::black)
            ) {
                win = true;
                winner.push_back(0);
                black = true;
            }
        }

        if (!white){
            if (
                (gameBoardMatrix[0][1] == Color::white
                && gameBoardMatrix[1][2] == Color::white 
                && gameBoardMatrix[2][3] == Color::white 
                && gameBoardMatrix[3][4] == Color::white 
                && gameBoardMatrix[4][5] == Color::white)
                ||
                (gameBoardMatrix[1][0] ==  Color::white
                && gameBoardMatrix[2][1] == Color::white
                && gameBoardMatrix[3][2] == Color::white
                && gameBoardMatrix[4][3] == Color::white 
                && gameBoardMatrix[5][4] == Color::white)
                ||
                (gameBoardMatrix[4][0] == Color::white 
                && gameBoardMatrix[3][1] == Color::white 
                && gameBoardMatrix[2][2] == Color::white 
                && gameBoardMatrix[1][3] == Color::white 
                && gameBoardMatrix[0][4] == Color::white)
                ||
                (gameBoardMatrix[5][1] == Color::white
                && gameBoardMatrix[4][2] == Color::white
                && gameBoardMatrix[3][3] == Color::white
                && gameBoardMatrix[2][4] == Color::white
                && gameBoardMatrix[1][5] == Color::white)
            ) {
                win = true;
                winner.push_back(1);
                white = true;
            }
        }
        if (!white){
            if (
                (gameBoardMatrix[0][0] == Color::white 
                && gameBoardMatrix[1][1] == Color::white 
                && gameBoardMatrix[2][2] == Color::white
                && gameBoardMatrix[3][3] == Color::white 
                && gameBoardMatrix[4][4] == Color::white)
                ||
                (gameBoardMatrix[1][1] == Color::white 
                && gameBoardMatrix[2][2] == Color::white 
                && gameBoardMatrix[3][3] == Color::white 
                && gameBoardMatrix[4][4] == Color::white 
                && gameBoardMatrix[5][5] == Color::white)
                ||
                (gameBoardMatrix[4][1] == Color::white 
                && gameBoardMatrix[3][2] == Color::white 
                && gameBoardMatrix[2][3] == Color::white 
                && gameBoardMatrix[1][4] == Color::white 
                && gameBoardMatrix[0][5] == Color::white)
                ||
                (gameBoardMatrix[5][0] == Color::white 
                && gameBoardMatrix[4][1] == Color::white 
                && gameBoardMatrix[3][2] == Color::white 
                && gameBoardMatrix[2][3] == Color::white 
                && gameBoardMatrix[1][4] == Color::white)
            ) {
                win = true;
                winner.push_back(1);
                white = true;
            }
        }
}
