#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 50010, M = N * 2;

int n, r1, r2;
int h[N], e[M], ne[M], idx;
int p[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u, int fa)
{
    p[u] = fa;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == fa) continue;
        dfs(j, u);
    }
}

int main()
{
    scanf("%d%d%d", &n, &r1, &r2);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++ )
        if (i != r1)
        {
            int fa;
            scanf("%d", &fa);
            add(i, fa), add(fa, i);
        }

    dfs(r2, -1);

    for (int i = 1; i <= n; i ++ )
        if (i != r2)
            printf("%d ", p[i]);

    return 0;
}
