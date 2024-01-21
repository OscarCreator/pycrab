#pragma once

typedef struct {
    int x, y;
} Point;

// get the difference between two points
Point point_diff(Point* p1, Point* p2);

// if point a is divisble by b
// return the divisible count
int is_divisible(Point* a, Point* b);
