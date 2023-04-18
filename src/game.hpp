#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include "player.hpp"


class Game
{
private:
    Player* player1 = nullptr;
    Player* player2 = nullptr;
    
public:
    Game(){
        player1 = new Player();
        player2 = new Player();
        std::cout << "Welcome in game Pentago!" << std::endl;
    };
    ~Game(){
        delete player1;
        delete player2;
    };

    void setPlayer1(std::string playerName){
        player1->setPlayerName(playerName);
    }
    void setPlayer2(std::string playerName){
        player2->setPlayerName(playerName);
    }

    Player getPlayer1(){
        return *player1;
    }

    Player getPlayer2(){
        return *player2;
    }

    void startGame();
};


#endif