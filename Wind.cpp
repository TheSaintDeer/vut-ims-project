//
// Created by ivan on 3.12.22.
//

#include <iomanip>

#include "Wind.h"

Wind::Wind(const PointN& dir, double force) {
    this->direction = dir;
    this->force = force;

    double x = force / sqrt(dir.x[0]*dir.x[0] + dir.x[1]*dir.x[1] + dir.x[2]*dir.x[2]);

    this->forceDirection.x[0] = x * dir.x[0];
    this->forceDirection.x[1] = x * dir.x[1];
    this->forceDirection.x[2] = x * dir.x[2];
}

Wind::Wind() = default;
