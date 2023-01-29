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
    Nystrom integrator;
    Point position = Point(3);
    Point velocity = Point(3);
    Point acceleration = Point(3);

    Test(Point direction, const Wind& w, double dB, double roB, double cD, double g, double roA);
    void Start();
};
