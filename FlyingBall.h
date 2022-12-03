#include <cmath>
#include "NystromN.h"
//#include <cxxplot/cxxplot>
#include "cxxplot.hpp"

class FlyingBall : public SecondDerivativeN
{
private:
    double dB = 0.0;
    double roB = 0.0;
    double cD = 0.0;
    double g = 0.0;
    double roA = 0.0;
    double mB = 0.0;
    double aB = 0.0;

public:
    FlyingBall(double dB, double roB, double cD, double g, double roA);

    PointN GetValue(double t, PointN y, PointN v) override;
};


