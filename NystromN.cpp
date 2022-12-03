//
// Created by max on 2.12.22.
//

#include "NystromN.h"

NystromN::NystromN(SecondDerivativeN *secondDerivative, double t0, PointN y0, PointN dy0, double h, PointN d2y0)
{
    this->secondDerivative = secondDerivative;
    this->t0 = t0;
    this->y0 = y0;
    this->dy0 = dy0;
    this->h = h;
    this->d2y0 = d2y0;
}

int NystromN::Step(double &t1, PointN &y1, PointN &dy1, PointN &d2y1)
{
    double h2 = h * h;

    PointN k1 = d2y0;
    PointN k2 = secondDerivative->GetValue(t0+h/2, y0+dy0 * (h/2)+k1*(h2/8), dy0+k1*(h/2));

    PointN k3 = secondDerivative->GetValue(t0+h/2, y0+dy0*(h/2)+k2*(h2/8), dy0+k2*(h/2));

    PointN k4 = secondDerivative->GetValue(t0+h, y0+dy0*h+k3*(h2/2), dy0+k3*h);

    t1 = this->t0 + h;
    y1 = this->y0 + this->dy0*h + (k1+k2+k3)*(h2/6);
    dy1 = this->dy0 + (k1+k2*2+k3*2+k4)*(h/6);
    d2y1 = secondDerivative->GetValue(t1, y1, dy1);

    this->t0 = t1;
    this->y0 = y1;
    this->dy0 = dy1;
    this->d2y0 = d2y1;


    return 0;
}