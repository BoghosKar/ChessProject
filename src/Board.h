#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Piece.h"

class Board
{
public:
    static const int SIZE = 8;
    Board();
    ~Board();
    void placePiece(Piece* piece, int x, int y);
    void print() const;
    bool isCheckmate(bool is_white);

private:
    std::vector<std::vector<Piece*>> board;
    bool isKingInCheck(bool is_white);
    bool canKingMoveToEscape(int king_x, int king_y, bool is_white);
};

#endif // BOARD_H
