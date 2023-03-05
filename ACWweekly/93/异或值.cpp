#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 3000010, INF = 2e9;

int n;
int tr[N][2], idx;

void insert(int x)
{
    int p = 0;
    for (int i = 29; i >= 0; i -- )
    {
        int u = x >> i & 1;
        if (!tr[p][u]) tr[p][u] = ++ idx;
        p = tr[p][u];
    }
}

int dfs(int u, int d)
{
    if (d == -1) return 0;
    int f[2];
    for (int i = 0; i < 2; i ++ )
    {
        int p = tr[u][i];
        if (p) f[i] = dfs(p, d - 1);
        else f[i] = -1;
    }

    int res = INF;
    for (int i = 0; i < 2; i ++ )
    {
        int t = 0;
        for (int j = 0; j < 2; j ++ )
            if (f[j] != -1)
                t = max(t, f[j] + ((i ^ j) << d));
        res = min(res, t);
    }

    return res;
}

int main()
{
    scanf("%d", &n);
    while (n -- )
    {
        int x;
        scanf("%d", &x);
        insert(x);
    }

    printf("%d\n", dfs(0, 29));
    return 0;
}
