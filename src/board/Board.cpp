#include "Board.h"
#include <iostream>

Board::Board()
{
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            grid[i][j] = '.';
        }
    }
}

void Board::printBoard()
{
    std::cout << std::endl;

    for(int i = 0; i < 8; ++i)
    {
        std::cout << 8 - i << "  ";
        for(int j = 0; j < 8; ++j)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "   A B C D E F G H" << std::endl;
}

void Board::placePiece(char piece, int row, int col)
{
    if(row >= 0 && row < 8 && col >= 0 && col < 8)
    {
        grid[row][col] = piece;
    }else
    {
        std::cerr << "Invalid position" << std::endl;
    }
}

bool Board::isCheckmate() const
{
    return false;
}