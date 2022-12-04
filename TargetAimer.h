//
// Created by max on 3.12.22.
//
#pragma once
#include <math.h>
#include "PointN.h"
#define PI 3.14159265

class TargetAimer {


public:
    vector<double> getAngleForTarget2D(PointN const &target, double v, double g);

};


