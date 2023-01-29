//
// Created by max on 2.12.22.
//
#pragma once
#include "Point.h"

class SecondDerivativeN {

public:
    virtual Point GetValue(double t, Point y, Point dy) = 0;
};

class Nystrom {

public:
    SecondDerivativeN *secondDerivative{};
    double t0 = 0.0;
    double h = 0.0;
    Point y0 = Point(3);
    Point dy0 = Point(3);
    Point d2y0 = Point(3);

    Nystrom(SecondDerivativeN *secondDerivative, double t0, Point y0, Point dy0, double h, Point d2y0);

    Nystrom();

    int Step(double &t1, Point &y1, Point &dy1, Point &d2y1);
};





