#include "point.h"

Point point_diff(Point* p1, Point* p2) {
    Point diff;
    diff.x = p1->x - p2->x;
    diff.y = p1->y - p2->y;
    return diff;
}
