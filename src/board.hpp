#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <iostream>

#include "player.hpp"

class Board
{
private:
    std::vector<std::vector<char>> boardMatrix;
    std::vector<std::pair<int, int>> availableMoves; 
public:
    Board(){
        for (int i=0; i<6; i++){
            boardMatrix.push_back(std::vector<char>(6,'O'));
        }
    };
    ~Board(){};

    std::vector<std::vector<char>> & getBoardMatrix(){
        return boardMatrix;
    }  

    void printBoard();

    void setAvailableMoves();

    std::vector<std::pair<int, int>> & getAvailableMoves(){
        return availableMoves;
    }

    void changeBoard(Move move);

};


#endif