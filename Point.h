#pragma once

#include <vector>
#include <memory>
using namespace std;
#pragma once
class Point {

private:
    int n = 0;

public:
    Point(int n);
    Point(Point const &a);

    double operator [](int i);
    Point operator + (const Point &b);
    Point operator *(double c);

    std::vector<double> x;
};




