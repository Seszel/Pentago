#include "randomPlayer.hpp"

void RandomPlayer::setMove(std::vector<std::pair<int, int>> & availableMoves, int playerIdx){

    int randomPlace = rand() % availableMoves.size();
    int size = availableMoves.size();
    move.placeOnBoard = availableMoves[randomPlace];

    int randomDirection = rand() % 2;
    if (randomDirection == 0){
        move.direction = 'L';
    } else {
        move.direction = 'R';
    }

    int randomSquare = rand() % 4;
    move.numberOfSquare = randomSquare;

    if (playerIdx == 0){
        move.color = 'B';
    } else {
        move.color = 'W';
    }
}
