#include "board.hpp"

void Board::printBoard()
{

    for (int i=0; i<Board::boardMatrix.size(); i++){

        if (i == 0 || i == 3){
            for (int j=0; j<Board::boardMatrix[i].size(); j++){
                if (j == 0){
                    std::cout << " -";
                } else {
                    std::cout << "---";
                }
            } 
            std::cout << std::endl;
        }
        
        

        for (int j=0; j<Board::boardMatrix[i].size(); j++){
            if (j == 3 || j == 0){
                std::cout << "|" << " " << Board::boardMatrix[i][j] << " ";
            } else {
                std::cout << Board::boardMatrix[i][j] << " ";
            }
             
        }
        std::cout << "|" << std::endl;

        if (i == Board::boardMatrix.size() - 1){
            for (int j=0; j<Board::boardMatrix[i].size(); j++){
                if (j == 0){
                    std::cout << " -";
                } else {
                    std::cout << "---";
                }
            } 
        }
    }
    
    std::cout << std::endl << std::endl;
}
