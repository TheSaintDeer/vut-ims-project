#pragma once

#include <cmath>
#include "NystromN.h"

class FlyingBall : public SecondDerivativeN {

private:
    double dB = 0.0;
    double roB = 0.0;
    double cD = 0.0;
    double g = 0.0;
    double roA = 0.0;
    double mB = 0.0;
    double aB = 0.0;
    PointN wind = PointN(3);

public:
    FlyingBall(double dB, double roB, double cD, double g, double roA, PointN w);

    FlyingBall();

    PointN GetValue(double t, PointN y, PointN v) override;
};


