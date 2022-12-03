//
// Created by max on 2.12.22.
//

#include "FlyingBall.h"

PointN FlyingBall::GetValue(double t, PointN y, PointN v) {

    double vx = v[0];
    double vy = v[1];
    double vxSqr = vx * vx;
    double vySqr = vy * vy;
    double vSqr = vxSqr + vySqr;
    double vTotal = sqrt(vSqr);

    double cosAlpha = 1;
    double cosBeta = 0;
    if (vTotal > 1.0e-12) {
        cosAlpha = vx / vTotal;
        cosBeta = vy / vTotal;
    }

    double drag = 0.5 * cD * roA * vSqr * aB;
    double dragX = -drag * cosAlpha;
    double dragY = -drag * cosBeta;

    PointN force = PointN(2);
    force.x[0] = dragX;
    force.x[1] = -mB * g + dragY;

    force.x[0] /= mB;
    force.x[1] /= mB;

    PointN acceleration = force;


    return acceleration;
}

FlyingBall::FlyingBall(double dB, double roB, double cD, double g, double roA) {
    this->dB = dB;
    this->roB = roB;
    this->cD = cD;
    this->g = g;
    this->roA = roA;

    double v = M_PI * pow(dB, 3) / 6;
    this->mB = roB * v;
    this->aB = 0.25 * M_PI * dB * dB;

}
