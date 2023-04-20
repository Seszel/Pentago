#ifndef RANDOM_PLAYER_HPP
#define RANDOM_PLAYER_HPP

#include "player.hpp"
#include <iostream>
#include <vector>

class RandomPlayer : public Player
{
private:
    /* data */
public:
    RandomPlayer(){};
    ~RandomPlayer(){};

    void setMove(std::vector<std::pair<int, int>> & availableMoves, int playerIdx);

};



#endif