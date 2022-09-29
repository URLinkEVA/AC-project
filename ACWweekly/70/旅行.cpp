#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 300010, M = N * 2;

int n;
int v[N];
int h[N], e[M], w[M], ne[M], idx;
LL f[N];
LL ans;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u, int fa)
{
    LL max1 = 0, max2 = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa) continue;
        dfs(j, u);
        if (f[j] - w[i] >= max1)
        {
            max2 = max1;
            max1 = f[j] - w[i];
        }
        else if (f[j] - w[i] > max2)
        {
            max2 = f[j] - w[i];
        }
    }

    ans = max(ans, v[u] + max1 + max2);
    f[u] = v[u] + max1;
}

int main()
{
    scanf("%d", &n);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &v[i]);

    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }

    dfs(1, -1);

    printf("%lld\n", ans);
    return 0;
}
