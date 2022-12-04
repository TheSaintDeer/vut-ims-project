//
// Created by max on 2.12.22.
//

#include "PointN.h"

/**
 * Creates n-dimensional point
 *
 * @param n number of dimensions
 */
PointN::PointN(int n) {
    this->n = n;
    this->x = vector<double>(n);
}

PointN::PointN(PointN const &a) {
    this->n = a.n;
    this->x = vector<double>(a.n);
    for (int i = 0; i < this->n; i++)
        this->x[i] = a.x[i];
}

double PointN::operator [](int i) {
    if (i < 0 || i >= n)
        return 0;
    else
        return x[i];
}

PointN PointN::operator +(const PointN &b) {
    int n = this->n;
    PointN r(n);
    for (int i = 0; i < n; i++)
        r.x[i] = this->x[i] + b.x[i];

    return r;
}

PointN PointN::operator *(double c) {
    int n = this->n;
    PointN res(n);
    for (int i = 0; i < n; i++)
        res.x[i] = this->x[i] * c;

    return res;
}


