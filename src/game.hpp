#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include "player.hpp"
#include "board.hpp"


class Game
{
private:
    std::vector<Player> playersMatrix;
    
public:
    Game(){
        for (int i=0; i<2; i++){
            playersMatrix.push_back(Player());
        }
        std::cout << "Welcome in game Pentago!" << std::endl;
    };
    ~Game(){
    };

    void setPlayer1(std::string playerName){
        playersMatrix[0].setPlayerName(playerName);
    }
    void setPlayer2(std::string playerName){
        playersMatrix[1].setPlayerName(playerName);
    }

    std::vector<Player> getPlayersMatrix(){
        return playersMatrix;
    }

    void startGame();
};


#endif