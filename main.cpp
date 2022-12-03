#include <iostream>
#include <iomanip>
#include "FlyingBall.h"
#include "Wind.h"

void set_dir(PointN &direction, Wind &wind) {
    cout << "Enter your direction (x, m/s): ";
    cin >> direction.x[0];
    cout << "Enter your direction (y, m/s): ";
    cin >> direction.x[1];
    cout << "Enter your angle: ";
    cin >> direction.x[2];

    while (true) {
        cout << "Turn on wind? (y/n) ";
        char switch_wind;
        cin >> switch_wind;
        if (tolower(switch_wind) == 'y') {

            cout << "Enter direction of wind (N, S, NW...): ";
            string w;
            cin >> w;
            Wind newWind(w);

            cout << "Enter your force of wind (m/s): ";
            double force;
            cin >> force;
            newWind.setForce(force);

            wind = newWind;
            break;
        } else if (tolower(switch_wind) == 'n') {
            break;
        } else {
            cout << "Incorrect value!";
        }
    }
}

void count_position(PointN pos, PointN dir, Wind w, double time, double c) {
    double x, y, z;
    x = sqrt( pow(pos.x[0], 2)/c ) * dir.x[0] + w.force[0]*time;
    y = sqrt( pow(pos.x[0], 2)/c ) * dir.x[1] + w.force[1]*time;
    z = pos.x[1];

    cout << "x: " << x << " y: " << y << " z: " << z << endl;
}

int main() {

//    FlyingBall projectileA = FlyingBall(0.1, 600, 0.0, 9.81, 1.29);
    FlyingBall projectileB = FlyingBall(0.1, 600, 0.5, 9.81, 1.29);

//    SecondDerivativeN *accelFunctionA = &(projectileA);
    SecondDerivativeN *accelFunctionB = &(projectileB);

    PointN direction(3);
    Wind wind;
    set_dir(direction, wind);

    double t0 = 0;
    double tmax = 12;
    double h = 0.5;

    PointN startPosition = PointN(2);
    startPosition.x[0] = 0;
    startPosition.x[1] = 0;

    PointN startVelocity = PointN(2);
    startVelocity.x[0] = 50 * sin(direction.x[2]);
    startVelocity.x[1] = 50 * cos(direction.x[2]);

//    PointN startAccelerationA = accelFunctionA->GetValue(t0, startPosition, startVelocity);
    PointN startAccelerationB = accelFunctionB->GetValue(t0, startPosition, startVelocity);

//    NystromN integratorA = NystromN(accelFunctionA, t0, startPosition, startVelocity, h, startAccelerationA);
    NystromN integratorB = NystromN(accelFunctionB, t0, startPosition, startVelocity, h, startAccelerationB);

     cout << fixed << setprecision(2);
     cout << "TEST1 - Flight of projectile" << endl;
     cout << " t,s xA,m yA,m xB,m yB,m" << endl;
     cout << t0 << " " << startPosition.x[0] << " " << startPosition.x[1] << " " << startPosition.x[0] << " " << startPosition.x[1] << " " << endl;

    double t;
//    PointN positionA(2), velocityA(2), accelerationA(2);
    PointN positionB(2), velocityB(2), accelerationB(2);

    double coef = pow(direction.x[0], 2) + pow(direction.x[1], 2);

    do {
//        integratorA.Step(t, positionA, velocityA, accelerationA);
        integratorB.Step(t, positionB, velocityB, accelerationB);
//        wcout << fixed << setw(4) << setprecision(1) << t << dec << fixed << setw(8) << setprecision(2) << positionA[0] << dec << fixed << setw(8) << setprecision(2) << positionA[1] << dec << fixed << setw(8) << setprecision(2) << positionB[0] << dec << fixed << setw(8) << setprecision(2) << positionB[1] << dec << endl;

//        cout << t << " " << positionB.x[0] << " " << positionB.x[1] << endl;
//        cout << " x: " << sqrt(pow(positionB.x[0], 2) / coef) * direction.x[0] << " y: " << sqrt(pow(positionB.x[0], 2) / coef) * direction.x[1] << endl;
//        cout << " x: " << wind.force[0]*t << " y: " << wind.force[1] * t << endl;
//        cout << " x: " << sqrt(pow(positionB.x[0], 2) / coef) * direction.x[0] + wind.force[0]*t << " y: " << sqrt(pow(positionB.x[0], 2) / coef) * direction.x[1] + wind.force[1] * t << endl;

        // cout << t << " " << positionA.x[0] << " " << positionA.x[1] << " " << endl;
        // cout << t << " " << positionA.x[0] << " " << positionA.x[1] << " " << positionB.x[0] << " " << positionB.x[1] << " " << endl;

        count_position(positionB, direction, wind, t, coef);
    } while (t < tmax);
    wcout << endl;




//    cxxplot::Kwargs args;
//    args.add_kwarg("color", "r");
//    args.add_kwarg("marker", "o");
//
//    std::vector<int> x_int{1, 2};
//    std::vector<int> y_int{2, 3};
//
//    std::vector<int> x_int2{4, 4};
//    std::vector<int> y_int2{5, 6};
//
//    std::vector<int> x_int3{1, 2};
//    std::vector<int> y_int3{4, 3};
//
//    cxxplot::Plot<int> plot_int(x_int, y_int, args);
//
//    plot_int.set_xlabel("x label");
//    plot_int.set_ylabel("y label");
//
//    plot_int.add_data(x_int2, y_int2);
//    plot_int.add_data(x_int3, y_int3);
//
//    plot_int.show();

    return 0;
}
