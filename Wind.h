//
// Created by ivan on 3.12.22.
//
#pragma once

#include <cstring>
#include "FlyingBall.h"

class Wind {

public:
    Point direction = Point(3);
    double force = 0.0;
    Point forceDirection = Point(3);

    Wind();
    explicit Wind(const Point&, double);
};