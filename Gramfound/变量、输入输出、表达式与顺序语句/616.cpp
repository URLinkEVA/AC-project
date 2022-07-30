#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    double a,b,c,d;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    printf("%.4lf", sqrt((c-a)*(c-a)+(d-b)*(d-b)));
    return 0;
}
