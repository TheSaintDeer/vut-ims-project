#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <getopt.h>
#include "Wind.h"
#include "FlyingBall.h"
#include "NystromN.h"
#include "PointN.h"
#include "Test.h"

using namespace std;

void set_dir(PointN &direction, Wind &wind) {
    cout << "Enter your direction (x, m/s): ";
    cin >> direction.x[0];
    cout << "Enter your direction (y, m/s): ";
    cin >> direction.x[1];
    cout << "Enter your angle: ";
    double angle;
    cin >> angle;
    direction.x[2] = angle/180*M_PI;
    cout << "Enter your velocity: ";
    cin >> direction.x[3];
//
    while (true) {
        cout << "Turn on wind? (y/n) ";
        char switch_wind;
        cin >> switch_wind;
        if (tolower(switch_wind) == 'y') {

            PointN w = PointN(3);
//            cout << "Enter direction of wind (x): ";
//            cin >> w.x[0];
//
//            cout << "Enter direction of wind (y): ";
//            cin >> w.x[1];
//
//            cout << "Enter direction of wind (z): ";
//            cin >> w.x[2];
//
//            double f = 0.0;
//            cout << "Enter force of wind (m/s): ";
//            cin >> f;
//
//            Wind newWind(w, f);
//            wind = newWind;
//            break;
        } else if (tolower(switch_wind) == 'n') {
            wind.forceDirection.x[0] = 0.0;
            wind.forceDirection.x[1] = 0.0;
            wind.forceDirection.x[2] = 0.0;
            break;
        } else {
            cout << "Incorrect value!";
        }
    }
}

int main(int argc, char *argv[] ) {

//    int flag_t1 = 0;
//    int flag_t2 = 0;
//    int flag_t3 = 0;
//    int flag_t4 = 0;
//
//    const char* short_options = "abcd";
//
//    const struct option long_options[] = {
//            { "T1", no_argument, &flag_t1, 'a'},
//            { "T2", no_argument, &flag_t2, 'b' },
//            { "T3", no_argument, &flag_t3, 'c' },
//            { "T4", no_argument, &flag_t4, 'd' },
//            { NULL, 0, NULL, 0}
//    };
//
//    while (getopt_long(argc, argv, short_options,long_options, NULL)!=-1);
//
//    cout <<
//    printf("flag_a = %d\n",flag_t1);
//    printf("flag_b = %d\n",flag_t2);
//    printf("flag_c = %d\n",flag_t3);
//    printf("flag_d = %d\n",flag_t4);
//    printf("\n");

    PointN direction(4);
    Wind wind;
    set_dir(direction, wind);
//
    Test t(direction, wind, 0.1, 600, 0.5, 9.81, 1.29);
    t.Start();

    return 0;
}
