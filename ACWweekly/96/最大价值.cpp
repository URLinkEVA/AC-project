#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int f[N];

int main()
{
    int v, w;
    scanf("%d%d%d%d", &n, &m, &v, &w);
    for (int i = v; i <= n; i ++ ) f[i] = f[i - v] + w;

    for (int i = 1; i <= m; i ++ )
    {
        int l, h;
        scanf("%d%d%d%d", &l, &h, &v, &w);
        for (int j = n; j > 0; j -- )
            for (int k = 1; k <= l / h && k * v <= j; k ++ )
                f[j] = max(f[j], f[j - k * v] + k * w);
    }

    printf("%d\n", f[n]);
    return 0;
}
