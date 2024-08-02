#include "Queen.h"

bool Queen::canMove(int from_x, int from_y, int to_x, int to_y) const
{
    int dx = to_x - from_x;
    int dy = to_y - from_y;
    return (dx == 0 || dy == 0 || dx == dy || dx == -dy || dy == -dx || dy == dx);
}
