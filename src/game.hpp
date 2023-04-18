#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include "player.hpp"


class Game
{
private:
    Player player1;
    Player player2;
    
public:
    Game(){
        std::cout << "Welcome in game Pentago!" << std::endl;
    };
    ~Game(){};

    void setPlayer1(){
        std::string playerName;
        std::cout << "Nickname for the player 1: ";
        getline(std::cin, playerName);
        player1.setPlayerName(playerName);
    }
    void setPlayer2(){
        std::string playerName;
        std::cout << "Nickname for the player 2: ";
        getline(std::cin, playerName);
        player2.setPlayerName(playerName);
    }

    Player getPlayer1(){
        return player1;
    }

    Player getPlayer2(){
        return player2;
    }

    void startGame();
};


#endif