//
// Created by ivan on 4.12.22.
//
#pragma once

#include <iostream>

#include "FlyingBall.h"
#include "Wind.h"

class Test {

public:
    double t = 0.0;
    FlyingBall projectile;
    NystromN integrator;
    PointN position = PointN(3);
    PointN velocity = PointN(3);
    PointN acceleration = PointN(3);

    Test(PointN direction, const Wind& w, double dB, double roB, double cD, double g, double roA);
    void Start();
};
