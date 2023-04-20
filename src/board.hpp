#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <iostream>

class Board
{
private:
    std::vector<std::vector<int>> boardMatrix;
public:
    Board(){
        for (int i=0; i<6; i++){
            boardMatrix.push_back(std::vector<int>(6,0));
        }
    };
    ~Board(){};

    std::vector<std::vector<int>> & getBoardMatrix(){
        return boardMatrix;
    }  

    void printBoard();

};


#endif