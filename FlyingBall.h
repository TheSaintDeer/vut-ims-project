#pragma once

#include <cmath>
#include "Nystrom.h"

class FlyingBall : public SecondDerivativeN {

private:
    double dB = 0.0;
    double roB = 0.0;
    double cD = 0.0;
    double g = 0.0;
    double roA = 0.0;
    double mB = 0.0;
    double aB = 0.0;
    Point wind = Point(3);

public:
    FlyingBall(double dB, double roB, double cD, double g, double roA, Point w);

    FlyingBall();

    Point GetValue(double t, Point y, Point v) override;
};


