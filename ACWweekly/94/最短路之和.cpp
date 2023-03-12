#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 510;

int n;
int d[N][N];
int p[N];
LL ans[N];
bool st[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            cin >> d[i][j];

    for (int i = 1; i <= n; i ++ ) cin >> p[i];

    for (int u = n; u; u -- )
    {
        int k = p[u];
        st[k] = true;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                if (st[i] && st[j])
                    ans[u] += d[i][j];
    }

    for (int i = 1; i <= n; i ++ ) printf("%lld ", ans[i]);
    return 0;
}
