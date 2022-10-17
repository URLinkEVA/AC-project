#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010, M = N * 2;

int n;
int h[N], e[M], w[M], ne[M], idx;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs(int u, int fa)
{
    int res = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j == fa) continue;
        res = max(res, dfs(j, u) + w[i]);
    }

    return res;
}

int main()
{
    scanf("%d", &n);
    memset(h, -1, sizeof h);

    LL sum = 0;
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
        sum += c * 2;
    }

    printf("%lld\n", sum - dfs(1, -1));

    return 0;
}
