//
// Created by ivan on 3.12.22.
//
#pragma once

#include <cstring>
#include "FlyingBall.h"

enum directionWind{
    None, N, NW, W, SW, S, SE, E, NE
};

class Wind {

public:
    string dir;
    PointN windDir = PointN(2);
    PointN force = PointN(2);

    Wind();
    explicit Wind(const string&);

    void setForce(double);
};