#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <map>
#include <memory>

#include "player.hpp"
#include "randomPlayer.hpp"
#include "realPlayer.hpp"
#include "board.hpp"


class Game
{
private:
    std::vector<std::unique_ptr<Player>> playersMatrix;
    Board gameBoard;
    
public:
    Game(std::vector<std::string> playerType);
    ~Game(){
    };

    void setPlayer1(std::string playerName){
        playersMatrix[0]->setPlayerName(playerName);
    }
    void setPlayer2(std::string playerName){
        playersMatrix[1]->setPlayerName(playerName);
    }

    std::vector<std::unique_ptr<Player>> & getPlayersMatrix(){
        return playersMatrix;
    }

    void startGame();

    void makeAMove(Move move);
};


#endif