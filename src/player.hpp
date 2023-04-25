#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>

struct Move {
    std::pair<int, int> placeOnBoard;
    int numberOfSquare;
    char direction;
    char color;
};

class Player
{
private:
    std::string playerName;
    char color;
protected:
    Move move;

public:
    Player(){}
    ~Player(){}

    void setPlayerName(const std::string playerName){
        this->playerName = playerName;
    }

    std::string getPlayerName(){
        return this->playerName;
    }

    char getColorName(){
        return color;
    }

    void setColorName(char color){
        this->color = color;
    }

    virtual void setMove(std::vector<std::pair<int, int>> & availableMoves, int playerIdx){
        std::cout << "Set move" << std::endl;
    }

    Move getMove(){
        return move;
    }

};


#endif