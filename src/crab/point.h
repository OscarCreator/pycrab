#pragma once

typedef struct {
    int x, y;
} Point;

// get the difference between two points
Point point_diff(Point* p1, Point* p2);
