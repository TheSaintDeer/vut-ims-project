//
// Created by max on 2.12.22.
//

#include "PointN.h"

class SecondDerivativeN {

public:
    virtual PointN GetValue(double t, PointN y, PointN dy) = 0;
};

//.h file code:


class NystromN {

private:
    SecondDerivativeN *secondDerivative;
    double t0 = 0.0;
    double h = 0.0;
    PointN y0 = PointN(2);
    PointN dy0 = PointN(2);
    PointN d2y0 = PointN(2);

public:
    NystromN(SecondDerivativeN *secondDerivative, double t0, PointN y0, PointN dy0, double h, PointN d2y0);

    int Step(double &t1, PointN &y1, PointN &dy1, PointN &d2y1);
};

//.cpp file code:





