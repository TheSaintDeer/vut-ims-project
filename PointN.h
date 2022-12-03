#include <vector>
#include <memory>
using namespace std;


class PointN {

private:
    int n = 0;

public:
    PointN(int n);
    PointN(PointN const &a);

    double operator [](int i);
    PointN operator + (const PointN &b);
    PointN operator *(double c);

    std::vector<double> x;
};




