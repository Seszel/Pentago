#include "randomPlayer.hpp"

void RandomPlayer::setMove(std::vector<std::pair<int, int>> & availableMoves, int playerIdx){

    int randomPlace = rand() % availableMoves.size();
    RandomPlayer::move.placeOnBoard = availableMoves[randomPlace];

    int randomDirection = rand() % 2;
    RandomPlayer::move.direction = randomDirection;

    int randomSquare = rand() % 4;
    RandomPlayer::move.numberOfSquare = randomSquare;

    RandomPlayer::move.color = playerIdx;
}
