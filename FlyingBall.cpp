//
// Created by max on 2.12.22.
//
#include "FlyingBall.h"

PointN FlyingBall::GetValue(double t, PointN y, PointN v) {

    double vx = v[0] - wind.x[0];
    double vy = v[1] - wind.x[1];
    double vz = v[2] - wind.x[2];

    double vxSqr = vx * vx;
    double vySqr = vy * vy;
    double vzSqr = vz * vz;

    double vSqr = vxSqr + vySqr + vzSqr;
    double vTotal = sqrt(vSqr);

    double cosX = 1;
    double cosY = 0;
    double cosZ = 0;

    if (vTotal > 1.0e-12) {
        cosX = vx / vTotal;
        cosY = vy / vTotal;
        cosZ = vz / vTotal;
    }

    double drag = 0.5 * cD * roA * vSqr * aB;
    double dragX = -drag * cosX;
    double dragY = -drag * cosY;
    double dragZ = -drag * cosZ;

    PointN force = PointN(3);
    force.x[0] = dragX;
    force.x[1] = dragY;
    force.x[2] = -mB * g + dragZ;

    force.x[0] /= mB;
    force.x[1] /= mB;
    force.x[2] /= mB;

    PointN acceleration = force;

    return acceleration;
}

FlyingBall::FlyingBall(double dB, double roB, double cD, double g, double roA, PointN w) {
    this->dB = dB;
    this->roB = roB;
    this->cD = cD;
    this->g = g;
    this->roA = roA;
    this->wind = w;

    double v = M_PI * pow(dB, 3) / 6;
    this->mB = roB * v;
    this->aB = 0.25 * M_PI * dB * dB;
}

FlyingBall::FlyingBall() = default;
