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
            } else {
                std::cout << ". ";
            }
        }
        std::cout << '\n';
    }
}

bool Board::isKingInCheck(bool is_white) const
{
    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            Piece* piece = board[y][x];
            if (piece && piece->getSymbol() == (is_white ? 'K' : 'k'))
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        if (dx == 0 && dy == 0) continue;
                        int check_x = x + dx;
                        int check_y = y + dy;
                        while (check_x >= 0 && check_x < SIZE && check_y >= 0 && check_y < SIZE)
                        {
                            Piece* other_piece = board[check_y][check_x];
                            if (other_piece)
                            {
                                if (other_piece->isWhite() != is_white && other_piece->canMove(check_x, check_y, x, y))
                                {
                                    return true;
                                }
                                break;
                            }
                            check_x += dx;
                            check_y += dy;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Board::isCheckmate(bool is_white) const
{
    if (!isKingInCheck(is_white)) return false;
    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            Piece* piece = board[y][x];
            if (piece && piece->getSymbol() == (is_white ? 'K' : 'k'))
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        int new_x = x + dx;
                        int new_y = y + dy;
                        if (new_x >= 0 && new_x < SIZE && new_y >= 0 && new_y < SIZE)
                        {
                            Piece* target = board[new_y][new_x];
                            if (!target || target->isWhite() != is_white) {
                                Piece* temp = target;
                                board[new_y][new_x] = piece;
                                board[y][x] = nullptr;
                                bool still_in_check = isKingInCheck(is_white);
                                board[y][x] = piece;
                                board[new_y][new_x] = temp;
                                if (!still_in_check) return false;
                            }
                        }
                    }
                }
                return true;
            }
        }
    }
    return true;
}
