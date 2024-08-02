#include "Board.h"
#include <iostream>

Board::Board() : board(SIZE, std::vector<Piece*>(SIZE, nullptr)) {}

Board::~Board()
{
    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            delete board[y][x];
        }
    }
}

void Board::placePiece(Piece* piece, int x, int y)
{
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE)
    {
        delete board[y][x];
        board[y][x] = piece;
    }
}

void Board::print() const
{
    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            if (board[y][x])
            {
                std::cout << board[y][x]->getSymbol() << ' ';
            } else
            {
                std::cout << ". ";
            }
        }
        std::cout << '\n';
    }
}

bool Board::isKingInCheck(bool is_white)
{
    int king_x = -1, king_y = -1;

    // Find king position
    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            if (board[y][x] && board[y][x]->getSymbol() == (is_white ? 'K' : 'k'))
            {
                king_x = x;
                king_y = y;
                break;
            }
        }
        if (king_x != -1) break;
    }

    if (king_x == -1)
    {
        return false; // king not found no check
    }

    //analyeze for check
    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            if (board[y][x] && board[y][x]->isWhite() != is_white)
            {
                if (board[y][x]->canMove(x, y, king_x, king_y))
                {
                    return true; //king in check
                }
            }
        }
    }

    return false; // king not in check
}

bool Board::canKingMoveToEscape(int king_x, int king_y, bool is_white)
{
    for (int dy = -1; dy <= 1; ++dy)
    {
        for (int dx = -1; dx <= 1; ++dx)
        {
            int new_x = king_x + dx;
            int new_y = king_y + dy;
            if (new_x >= 0 && new_x < SIZE && new_y >= 0 && new_y < SIZE)
            {
                Piece* target = board[new_y][new_x];
                
                //check to see if there are moves
                if (!target || target->isWhite() != is_white)
                {
                    Piece* temp = target;
                    board[new_y][new_x] = board[king_y][king_x];
                    board[king_y][king_x] = nullptr;
                    bool still_in_check = isKingInCheck(is_white);
                    board[king_y][king_x] = board[new_y][new_x];
                    board[new_y][new_x] = temp;
                    if (!still_in_check) return true;
                }
            }
        }
    }
    return false; // no moves
}

bool Board::isCheckmate(bool is_white)
{
    int king_x = -1, king_y = -1;

    // find king
    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            if (board[y][x] && board[y][x]->getSymbol() == (is_white ? 'K' : 'k'))
            {
                king_x = x;
                king_y = y;
                break;
            }
        }
        if (king_x != -1) break;
    }

    if (!isKingInCheck(is_white))
    {
        return false;
    }

    return !canKingMoveToEscape(king_x, king_y, is_white);
}
