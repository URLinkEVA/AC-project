#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-8;

int cmp(double x, double y)
{
    if (fabs(x - y) < eps) return 0;
    if (x < y) return -1;
    return 1;
}

int main()
{
    double r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    double dx = x1 - x2;
    double dy = y1 - y2;
    double d = sqrt(dx * dx + dy * dy);
    if (cmp(d, r) >= 0) printf("%lf %lf %lf\n", x1, y1, r);
    else
    {
        if (!cmp(x1, x2) && !cmp(y1, y2))
            printf("%lf %lf %lf\n", x1 + r / 2, y1, r / 2);
        else
        {
            double r2 = (r + d) / 2;
            double x = x2 + (x1 - x2) / d * r2;
            double y = y2 + (y1 - y2) / d * r2;
            printf("%lf %lf %lf\n", x, y, r2);
        }
    }

    return 0;
}
