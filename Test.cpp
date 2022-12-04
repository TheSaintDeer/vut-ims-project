//
// Created by ivan on 4.12.22.
//

#include "Test.h"

Test::Test(PointN direction, const Wind& w, double dB, double roB, double cD, double g, double roA) {
    this->t = 0.0;

    this->projectile = FlyingBall(dB, roB, cD, g, roA, w.forceDirection);
    SecondDerivativeN *accelFunction = &(projectile);

    double h = 0.5;

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

    do {
        this->integrator.Step(t, position, velocity, acceleration);
        std::cout << t << " " << position.x[0] << " " << position.x[1] << " " << position.x[2] << endl;
    } while (position.x[2] > 0);
}
