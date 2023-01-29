#include <getopt.h>

#include "Wind.h"
#include "FlyingBall.h"
#include "Point.h"
#include "Test.h"

using namespace std;

int main(int argc, char *argv[]) {

    Point direction(4);
    double cD = 0.0;
    double wForce = 0.0;
    Point dir = Point(3);

    double d = 0.0;
    double ro = 0.0;

    const char* short_options = "x:y:a:v:c:w:b:i:f:l:r:";

    const struct option long_options[] = {
            { "mx", required_argument, NULL, 'x' },
            { "my", required_argument, NULL, 'y' },
            { "ma", required_argument, NULL, 'a' },
            { "v",  required_argument, NULL, 'v' },
            { "cd", required_argument, NULL, 'c' },
            { "wx", required_argument, NULL, 'w' },
            { "wy", required_argument, NULL, 'b' },
            { "wz", required_argument, NULL, 'i' },
            { "wf", required_argument, NULL, 'd' },
            { "d",  required_argument, NULL, 'l' },
            { "ro",required_argument, NULL, 'r' },
            { NULL, 0, NULL, 0}
    };

    int result;
    int option_index;

    while ((result=getopt_long(argc,argv,short_options,long_options,&option_index)) != -1) {

        switch(result) {
            case 'x': {
                direction.x[0] = stod(optarg);
                break;
            }
            case 'y': {
                direction.x[1] = stod(optarg);
                break;
            }
            case 'a': {
                direction.x[2] = (stod(optarg)/180.0)* M_PI;
                break;
            }
            case 'v': {
                direction.x[3] = stod(optarg);
                break;
            }
            case 'c': {
                cD = stod(optarg);
                break;
            }
            case 'w': {
                dir.x[0] = stod(optarg);
                break;
            }
            case 'b': {
                dir.x[1] = stod(optarg);
                break;
            }
            case 'i': {
                dir.x[2] = stod(optarg);
                break;
            }
            case 'f': {
                wForce = stod(optarg);
                break;
            }
            case 'l': {
                d = stod(optarg);
                break;
            }
            case 'r': {
                ro = stod(optarg);
                break;
            }
            default: {
            }
        }
    }

    Wind wind(dir, wForce);

    Test t(direction, wind, d, ro, cD, 9.81, 1.29);
    t.Start();

    return 0;
}
