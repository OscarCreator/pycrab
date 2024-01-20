#pragma once

#include "point.h"
#include "stdbool.h"

// a crab library to calculate how many steps util a crab reaches a target

typedef struct {
    Point position;
    Point direction;
} Crab;

int crab_steps_to_target(Crab* crab, Point* target);

bool crab_can_reach(Crab* crab, Point* target);
