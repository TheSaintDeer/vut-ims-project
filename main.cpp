#include <iostream>
#include <iomanip>
#include "FlyingBall.h"

void set_arg(PointN &direction) {
    cout << "Enter your direction (x): ";
    cin >> direction.x[0];
    cout << "Enter your direction (y): ";
    cin >> direction.x[1];
    cout << "Enter your angle: ";
    cin >> direction.x[2];
}

int main() {

//    FlyingBall projectileA = FlyingBall(0.1, 600, 0.0, 9.81, 1.29);
    FlyingBall projectileB = FlyingBall(0.1, 600, 0.5, 9.81, 1.29);

//    SecondDerivativeN *accelFunctionA = &(projectileA);
    SecondDerivativeN *accelFunctionB = &(projectileB);

    double t0 = 0;
    double tmax = 12;
    double h = 0.5;

    PointN startPosition = PointN(2);
    startPosition.x[0] = 0;
    startPosition.x[1] = 0;

    PointN startVelocity = PointN(2);
    startVelocity.x[0] = 50;
    startVelocity.x[1] = 50;

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

    do
    {
//        integratorA.Step(t, positionA, velocityA, accelerationA);
        integratorB.Step(t, positionB, velocityB, accelerationB);
//        wcout << fixed << setw(4) << setprecision(1) << t << dec << fixed << setw(8) << setprecision(2) << positionA[0] << dec << fixed << setw(8) << setprecision(2) << positionA[1] << dec << fixed << setw(8) << setprecision(2) << positionB[0] << dec << fixed << setw(8) << setprecision(2) << positionB[1] << dec << endl;
        cout << t << "x: " << positionB.x[0] << "y: " << positionB.x[1] << endl;
        // cout << t << " " << positionA.x[0] << " " << positionA.x[1] << " " << endl;
        // cout << t << " " << positionA.x[0] << " " << positionA.x[1] << " " << positionB.x[0] << " " << positionB.x[1] << " " << endl;
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
