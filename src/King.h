#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
public:
    King(bool is_white) : Piece(is_white) {}
    char getSymbol() const override { return is_white ? 'K' : 'k'; }
    bool canMove(int from_x, int from_y, int to_x, int to_y) const override;
};

#endif // KING_H
