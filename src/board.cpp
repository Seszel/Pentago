#include "board.hpp"

void Board::printBoard()
{

    for (int i=0; i<boardMatrix.size(); i++){

        if (i == 0 || i == 3){
            for (int j=0; j<boardMatrix[i].size(); j++){
                if (j == 0){
                    std::cout << " -";
                } else if (j == 3) {
                    std::cout << " --";
                } else {
                    std::cout << "---";
                }
            } 
            std::cout << std::endl;
        }
        

        for (int j=0; j<boardMatrix[i].size(); j++){
            if (j == 3 || j == 0){
                std::cout << "|" << " " << boardMatrix[i][j] << " ";
            } else {
                std::cout << boardMatrix[i][j] << " ";
            }
             
        }
        std::cout << "|" << std::endl;

        if (i == boardMatrix.size() - 1){
            for (int j=0; j<boardMatrix[i].size(); j++){
                if (j == 0){
                    std::cout << " -";
                } else if (j == 3) {
                    std::cout << " --";
                } else {
                    std::cout << "---";
                }
            } 
        }
    }
    
    std::cout << std::endl << std::endl;
}

void Board::setAvailableMoves()
{
    availableMoves.clear();
    for (int i=0; i<boardMatrix.size(); i++){
        for (int j=0; j<boardMatrix[i].size(); j++){
            if (boardMatrix[i][j] == 'O'){
                availableMoves.push_back({i,j});
            }
        }
    }
}

void rotate(std::vector<std::vector<char>> & myMatrix, Move move) 
{
    int row, column;
    switch (move.numberOfSquare) {
        case 0:
            row = 0;
            column = 0;
            break;
        case 1:
            row = 0;
            column = 3;
            break;
        case 2:
            row = 3;
            column = 0;
            break;
        case 3:
            row = 3;
            column = 3;
            break;
    }
    size_t sizeOfSquare = 3;
    std::vector<std::vector<int>> square;


    for (int r=row; r < row + sizeOfSquare; r++){
        std::vector<int> temp;
        for (int c=column; c < column + sizeOfSquare; c++){
            temp.push_back(myMatrix[r][c]);
        }
        square.push_back(temp);
        temp.clear();
    }

    if (move.direction == Direction::left){

        reverse(square.begin(), square.end());

        for (int i = 0; i < sizeOfSquare; ++i){
            for (int j = i+1; j < sizeOfSquare; ++j){
                std::swap(square[i][j], square[j][i]);
            }
	    }

    } else {
         for (int i = 0; i < sizeOfSquare; ++i){
                std::swap(square[i][2], square[i][0]);
            }
        for (int i = 0; i < sizeOfSquare; ++i){
            for (int j = i+1; j < sizeOfSquare; ++j){
                std::swap(square[i][j], square[j][i]);
            }
	    }   
    }

    for (int i=0; i < sizeOfSquare; i++){
        for (int j=0; j < sizeOfSquare; j++){
            myMatrix[i+row][j+column] = square[i][j];
        }
    }
}


void Board::changeBoard(Move move)
{
    boardMatrix[move.placeOnBoard.first][move.placeOnBoard.second] = move.color;
    rotate(boardMatrix, move);

}
