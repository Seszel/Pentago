#ifndef REAL_PLAYER_HPP
#define REAL_PLAYER_HPP

#include "player.hpp"

class RealPlayer : public Player
{
private:
    /* data */
public:
    RealPlayer(){};
    ~RealPlayer(){};

    void setMove(std::vector<std::pair<int, int>> & availableMoves, int playerIdx);

};



#endif