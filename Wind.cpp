//
// Created by ivan on 3.12.22.
//

#include <iomanip>
#include <cctype>

#include "Wind.h"

Wind::Wind(const string& direct) {
    this->dir = direct;

    if (direct == "None") {
        windDir.x[0] = 0;
        windDir.x[1] = 0;
    } else if (direct == "N") {
        windDir.x[0] = 1;
        windDir.x[1] = 0;
    } else if (direct == "S") {
        windDir.x[0] = -1;
        windDir.x[1] = 0;
    } else if (direct == "E") {
        windDir.x[0] = 0;
        windDir.x[1] = 1;
    } else if (direct == "W") {
        windDir.x[0] = 0;
        windDir.x[1] = -1;
    } else if (direct == "NE") {
        windDir.x[0] = 1;
        windDir.x[1] = 1;
    } else if (direct == "NW") {
        windDir.x[0] = 1;
        windDir.x[1] = -1;
    } else if (direct == "SE") {
        windDir.x[0] = -1;
        windDir.x[1] = 1;
    } else if (direct == "SW") {
        windDir.x[0] = -1;
        windDir.x[1] = -1;
    }
}

void Wind::setForce(double f) {

    if (this->dir == "None") {
        return;
    } else if (this->dir.length() == 1) {
        this->force.x[0] = f * this->windDir.x[0];
        this->force.x[1] = f * this->windDir.x[1];
    } else if (this->dir.length() == 2) {
        this->force.x[0] = f * this->windDir.x[0] / sqrt(2);
        this->force.x[1] = f * this->windDir.x[1] / sqrt(2);
    }
}

Wind::Wind() = default;
