//
// Created by ivan on 3.12.22.
//
#pragma once

#include <cstring>
#include "FlyingBall.h"

class Wind {

public:
    PointN direction = PointN(3);
    double force = 0.0;
    PointN forceDirection = PointN(3);

    Wind();
    explicit Wind(const PointN&, double);
};