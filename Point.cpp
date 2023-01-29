//
// Created by max on 2.12.22.
//

#include "Point.h"

/**
 * Creates n-dimensional point
 *
 * @param n number of dimensions
 */
Point::Point(int n) {
    this->n = n;
    this->x = vector<double>(n);
}

Point::Point(Point const &a) {
    this->n = a.n;
    this->x = vector<double>(a.n);
    for (int i = 0; i < this->n; i++)
        this->x[i] = a.x[i];
}

double Point::operator [](int i) {
    if (i < 0 || i >= n)
        return 0;
    else
        return x[i];
}

Point Point::operator +(const Point &b) {
    int n = this->n;
    Point r(n);
    for (int i = 0; i < n; i++)
        r.x[i] = this->x[i] + b.x[i];

    return r;
}

Point Point::operator *(double c) {
    int n = this->n;
    Point res(n);
    for (int i = 0; i < n; i++)
        res.x[i] = this->x[i] * c;

    return res;
}


