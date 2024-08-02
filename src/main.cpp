#include "Board.h"
#include "King.h"
#include "Queen.h"
#include <iostream>

int main()
{
    Board board;

    board.placePiece(new King(true), 4, 0);
    board.placePiece(new King(false), 4, 7);
    board.placePiece(new Queen(true), 3, 7);

    board.print();

    if (board.isCheckmate(true))
    {
        std::cout << "White King is in checkmate" << std::endl;
    } else {
        std::cout << "White King is not in checkmate" << std::endl;
    }

    if (board.isCheckmate(false))
    {
        std::cout << "Black King is in checkmate" << std::endl;
    } else {
        std::cout << "Black King is not in checkmate" << std::endl;
    }

    return 0;
}
