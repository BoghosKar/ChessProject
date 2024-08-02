#include "King.h"

bool King::canMove(int from_x, int from_y, int to_x, int to_y) const
{
    int dx = to_x - from_x;
    int dy = to_y - from_y;
    return ((dx == 0 || dx == 1 || dx == -1) && (dy == 0 || dy == 1 || dy == -1) && !(dx == 0 && dy == 0));
}
