#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 30;

int n, v;
int a[N], b[N];

int main()
{
    scanf("%d%d", &n, &v);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &b[i]);

    double x = 1e8, sum = 0;
    for (int i = 1; i <= n; i ++ )
    {
        x = min(x, (double)b[i] / a[i]);
        sum += a[i];
    }

    x = min(x, v / sum);
    printf("%lf\n", x * sum);

    return 0;
}
