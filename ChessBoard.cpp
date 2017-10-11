

#include "ChessBoard.h"
#include<iostream>

ChessBoard::~ChessBoard() {
}

/**
 * Create a chessboard given its length
 * 
 * @param size Length of the chessboard
 * 
 */
ChessBoard::ChessBoard(int size) {
    sizeBoard = size;

    board = new int*[size];
    tiles = new int[size];

    for (int i = 0; i < size; ++i) {
        board[i] = new int[size];
    }
}

/**
 * Print an array with the position of the queens in each row.
 */
void ChessBoard::solve() {
    int i = 0;
    int j = 0;

    if (sizeBoard != 2 && sizeBoard != 3) {
        
        while (index > -1 && index < sizeBoard) {

            board[i][tiles[index]] = 0;

            while (index > -1 && index < sizeBoard) {

                if (j >= sizeBoard && index > 0) {
                    tiles[index] = 0;
                    --index;
                    i -= 2;
                    j = tiles[index] + 1;
                    break;
                }


                if (checkFreeColumn(board, i, j) && checkFreeDiagonal(board, i, j)) {
                    board[i][j] = 1;
                    tiles[index] = j;
                    ++index;
                    j = 0;
                    break;
                }
                ++j;
            }

            ++i;
        }

        for (int k = 0; k < sizeBoard; ++k) {
            std::cout << tiles[k] << " ";
        }
    }
    
    else {
        std::cout<<"Impossible to solve";
    }
}

/**
 * Print all the possible solutions as well as the number of solutions
 */
void ChessBoard::solveAll() {
    int i = 0;
    int j = 0;
    int counter = 0;

    if (sizeBoard != 2 && sizeBoard != 3) {
        while (index >= 0 && index < sizeBoard) {

            board[i][tiles[index]] = 0;

            while (index < sizeBoard) {

                if (j >= sizeBoard) {
                    tiles[index] = 0;
                    --index;
                    i -= 2;
                    j = tiles[index] + 1;
                    break;
                }


                if (checkFreeColumn(board, i, j) && checkFreeDiagonal(board, i, j)) {
                    board[i][j] = 1;
                    tiles[index] = j;
                    ++index;
                    j = 0;
                    break;
                }
                ++j;
            }

            ++i;

            if (index >= sizeBoard) {
                for (int c = 0; c < sizeBoard; ++c) {
                    std::cout << tiles[c] << " ";
                }

                std::cout << "\n";

                --index;
                --i;
                j = tiles[index] + 1;
                ++counter;

            }
        }

    }

    std::cout << "Total: " << counter;


}

/**
 * Checks if the position (x,y) is free of queens in their diagonals.
 * 
 * @param matriz Matrix representing the chessboard
 * @param x Position of the queen in the row x
 * @param y Position of the queen in the column y
 * @return True if the diagonals are free. Otherwise false
 */
bool ChessBoard::checkFreeDiagonal(int **matriz, int x, int y) {

    for (int i = 0; i < sizeBoard; ++i) {
        for (int j = 0; j < sizeBoard; ++j) {

            if (matriz[i][j] == 1 && (abs(x - i) == abs(y - j))) {
                return false;
            }
        }
    }

    return true;
}

/**
 * Checks if the position (x,y) is free of queens in its column.
 * 
 * @param matriz Matrix representing the chessboard
 * @param x Position of the queen in the row x
 * @param y Position of the queen in the column y
 * @return True if the column is free. Otherwise false
 */
bool ChessBoard::checkFreeColumn(int **matriz, int x, int y) {

    for (int i = 0; i < sizeBoard; ++i) {

        if (matriz[i][y] != 0 && i != x) {
            return false;
        }
    }

    return true;
}


