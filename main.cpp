#include <iostream>
#include <fstream>
#include <iomanip>
#include <unistd.h>
#include "Wind.h"
#include "FlyingBall.h"
#include "PointN.h"
#include "Test.h"

using namespace std;

int main(int argc, char *argv[] ) {
//    PointN direction(4);
//    direction.x[0] = stod(argv[1]);
//    direction.x[1] = stod(argv[2]);
//    direction.x[2] = stod(argv[3]);
//    direction.x[3] = stod(argv[4]);
//
//    double cD = stod(argv[5]);
//
//    Wind wind;
//    wind.direction.x[0] = stod(argv[6]);
//    wind.direction.x[1] = stod(argv[7]);
//    wind.direction.x[2] = stod(argv[8]);
//    wind.force = stod(argv[9]);

    PointN direction(4);
    direction.x[0] = 1;
    direction.x[1] = 0;
    direction.x[2] = (45.0/180.0) * M_PI;
    direction.x[3] = 70;

    double cD = 0.5;

    PointN dir = PointN(3);
    dir.x[0] = 0;
    dir.x[1] = 0;
    dir.x[2] = 0;
    Wind wind(dir, 0);

    Test t(direction, wind, 0.1, 600, cD, 9.81, 1.29);
    t.Start();

    return 0;
}
