//
// Created by ivan on 4.12.22.
//

#include <fstream>
#include "Test.h"

Test::Test(PointN direction, const Wind& w, double dB, double roB, double cD, double g, double roA) {
    this->t = 0.0;

    this->projectile = FlyingBall(dB, roB, cD, g, roA, w.forceDirection);
    SecondDerivativeN *accelFunction = &(projectile);

    double h = 0.1;

    PointN startPosition = PointN(3);
    startPosition.x[0] = 0;
    startPosition.x[1] = 0;
    startPosition.x[2] = 0;

    double c = cos(direction.x[2]) / sqrt(direction.x[1] * direction.x[1] + direction.x[0] * direction.x[0]);
    PointN startVelocity = PointN(3);
    startVelocity.x[0] = direction.x[3] * c * direction.x[0];
    startVelocity.x[1] = direction.x[3] * c * direction.x[1];
    startVelocity.x[2] = direction.x[3] * sin(direction.x[2]);

    PointN startAcceleration = accelFunction->GetValue(t, startPosition, startVelocity);

    this->integrator = NystromN(accelFunction, t, startPosition, startVelocity, h, startAcceleration);
}
void Test::Start() {

    ofstream f(R"(out.txt)", ios::out | ios::trunc);
    f << t << " " << integrator.y0.x[0] << ":" << integrator.y0.x[1] << ":" << integrator.y0.x[2] << " " << integrator.dy0.x[0] << ":" << integrator.dy0.x[1] << ":" << integrator.dy0.x[2] << "" << endl;

    do {
        this->integrator.Step(t, position, velocity, acceleration);
        f << t << " " << position.x[0] << ":" << position.x[1] << ":" << position.x[2] << " " << velocity.x[0] << ":" << velocity.x[1] << ":" << velocity.x[2] << "" << endl;
    } while (position.x[2] > 0);

    f.close();
}
