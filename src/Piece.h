#ifndef PIECE_H
#define PIECE_H

class Piece
{
public:
    Piece(bool is_white) : is_white(is_white) {}
    virtual ~Piece() = default;
    virtual char getSymbol() const = 0;
    virtual bool canMove(int from_x, int from_y, int to_x, int to_y) const = 0;
    bool isWhite() const { return is_white; }
protected:
    bool is_white;
};

#endif // PIECE_H
