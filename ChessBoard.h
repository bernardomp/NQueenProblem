

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

class ChessBoard {
public:
    virtual ~ChessBoard();
    ChessBoard(int size);
    
    void clearAll();
    void solve();
    void solveAll();
    
private:
    
    int sizeBoard;
    int **board;
    int *tiles;
    int index = 0;
    
    bool checkFreeDiagonal(int **matriz, int x, int y);
    bool checkFreeColumn(int **matriz, int x, int y);

};

#endif /* CHESSBOARD_H */

