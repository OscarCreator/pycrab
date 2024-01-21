#include "crab.h"
#include "point.h"
#include <math.h>
#include <stdbool.h>

// return steps to reach target
// return -1 if target cannot be reached
int crab_steps_to_target(Crab* crab, Point* target) {
    Point a = point_diff(target, &crab->position);
    int div_count = is_divisible(&a, &crab->direction);
    if (div_count == 0) {
        return -1;
    }
    return div_count;
}

// return true if crab can reach target
bool crab_can_reach(Crab* crab, Point* target) {
    return crab_steps_to_target(crab, target) != -1;
}
