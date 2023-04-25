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

class Player
{
private:
    std::string playerName;
    std::string colorName;
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

    std::string getColorName(){
        return colorName;
    }

    void setColorName(std::string colorName){
        this->colorName = colorName;
    }

    virtual void setMove(std::vector<std::pair<int, int>> & availableMoves, int playerIdx){
        std::cout << "Set move" << std::endl;
    }

    Move getMove(){

        // auto white = Color::white;
        return move;
    }

};


#endif