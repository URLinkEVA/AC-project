#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    printf("%.4lf", (a*b)/(b+c));
    return 0;
}
