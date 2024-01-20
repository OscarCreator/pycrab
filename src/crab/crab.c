#include "crab.h"
#include "point.h"
#include <stdbool.h>
#include <stdlib.h>

// return steps to reach target
// return -1 if target cannot be reached
int crab_steps_to_target(Crab* crab, Point* target) {
    Point a = point_diff(&crab->direction, target);
    if (crab->direction.x % a.x != 0 || crab->direction.y % a.y != 0) {
        return -1;
    }
    return (crab->direction.x / a.x);
}

// return true if crab can reach target
bool crab_can_reach(Crab* crab, Point* target) {
    return crab_steps_to_target(crab, target) != -1;
}
