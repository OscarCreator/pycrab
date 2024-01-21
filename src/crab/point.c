#include "point.h"
#include <stdbool.h>

Point point_diff(Point* p1, Point* p2) {
    Point diff;
    diff.x = p1->x - p2->x;
    diff.y = p1->y - p2->y;
    return diff;
}

// check if point a is divisble with point b
// return the divisble count
int is_divisible(Point* a, Point* b) {
    bool x = false;
    bool y = false;

    // handle when b is zero
    if (b->x == 0) {
        if (a->x != 0) {
            return 0;
        }
        if ((a->y % b->y) == 0) {
            return a->y / b->y;
        }
    }
    if (b->y == 0) {
        if (a->y != 0) {
            return 0;
        }
        if ((a->x % b->x) == 0) {
            return a->x / b->x;
        }
    }
    // check both
    if ((a->x % b->x) != 0) {
        return 0;
    }
    if ((a->y % b->y) != 0) {
        return 0;
    }
    int yd = a->y / b->y;
    int xd = a->x / b->x;
    if (xd == yd) {
        return xd;
    }
    return 0;
}
