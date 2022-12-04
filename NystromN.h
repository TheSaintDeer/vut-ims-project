//
// Created by max on 2.12.22.
//
#pragma once

#include "PointN.h"

class SecondDerivativeN {

public:
    virtual PointN GetValue(double t, PointN y, PointN dy) = 0;
};

class NystromN {

private:
    SecondDerivativeN *secondDerivative{};
    double t0 = 0.0;
    double h = 0.0;
    PointN y0 = PointN(3);
    PointN dy0 = PointN(3);
    PointN d2y0 = PointN(3);

public:
    NystromN(SecondDerivativeN *secondDerivative, double t0, PointN y0, PointN dy0, double h, PointN d2y0);

    NystromN();

    int Step(double &t1, PointN &y1, PointN &dy1, PointN &d2y1);
};





