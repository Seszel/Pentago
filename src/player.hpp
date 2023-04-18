#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player
{
private:
    std::string playerName;
public:
    Player(){};
    ~Player(){};

    void setPlayerName(std::string playerName){
        playerName = playerName;
    }

    std::string getPlayerName(){
        return playerName;
    }
};


#endif