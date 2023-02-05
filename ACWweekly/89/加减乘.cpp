#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e7 + 10;

int n, x, y;
LL f[N];

int main()
{
    cin >> n >> x >> y;
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for (int i = 1; i <= n; i ++ )
        if (i % 2)
            f[i] = min(f[(i + 1) / 2] + x + y, f[i - 1] + x);
        else
            f[i] = min(f[i / 2] + y, f[i - 1] + x);
    printf("%lld\n", f[n]);

    return 0;
}
