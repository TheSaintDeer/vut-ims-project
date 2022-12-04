//
// Created by max on 3.12.22.
//

#include "TargetAimer.h"

 vector<double> TargetAimer::getAngleForTarget2D(const PointN &target, double v, double g) {

    double v2 = pow(v, 2);
    double v4 = pow(v, 4);

    double very_difficult_part = sqrt( v4 - g * ( g * pow(target.x[0], 2) + 2 * v2 * target.x[1] ) );

    double first_first_part = v2 + very_difficult_part;
    double first_second_part = v2 - very_difficult_part;

    double second_part = g * target.x[0];

    double param1 = first_first_part / second_part;
    double param2 = first_second_part / second_part;

    double angle1 = atan(param1) * 180 / PI;
    double angle2 = atan(param2) * 180 / PI;

     vector<double> result;
     result.push_back(angle1);
     result.push_back(angle2);
    return result;
}

