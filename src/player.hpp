#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
private:
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
};


#endif