cdef extern from "point.h":
    ctypedef struct Point:
        int x
        int y
    Point point_diff(Point* point, Point* point)

cdef extern from "crab.h":
    ctypedef struct Crab:
        Point position
        Point direction

    int crab_steps_to_target(Crab* crab, Point* target)
    bint crab_can_reach(Crab* crab, Point* target)
