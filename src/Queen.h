#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(bool is_white) : Piece(is_white) {}
    char getSymbol() const override { return is_white ? 'Q' : 'q'; }
    bool canMove(int from_x, int from_y, int to_x, int to_y) const override;
};

#endif // QUEEN_H
