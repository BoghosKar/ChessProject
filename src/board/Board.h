#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
    Board();
    void printBoard();
    void placePiece(char piece, int row, int col);
    bool isCheckmate() const;

private:
    char grid[8][8];
};

#endif // BOARD_H