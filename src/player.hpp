#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>

struct Move {
    std::pair<int, int> placeOnBoard;
    int numberOfSquare;
    int direction;
    int color;
};

// enum Color {
//     black,
//     white
// } color;

// enum Direction {
//     left,
//     right
// } direction;

class Player
{
private:
    std::string playerName;
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

    virtual void setMove(std::vector<std::pair<int, int>> & availableMoves, int playerIdx){
        std::cout << "Set move" << std::endl;
    }

    Move getMove(){
        return move;
    }

};


#endif