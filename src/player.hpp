#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>

struct Move {
    std::pair<int, int> placeOnBoard;
    int numberOfSquare;
    std::string direction;
};

enum Direction {
    left,
    right
};

class Player
{
private:
    Move move;
    std::string playerName;

public:
    Player(){
    }
    ~Player(){}

    void setPlayerName(const std::string playerName){
        this->playerName = playerName;
    }

    std::string getPlayerName(){
        return this->playerName;
    }

    virtual void setMove(){
        std::cout << "Set move" << std::endl;
    }

};


#endif