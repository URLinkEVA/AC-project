#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int N = 100010, M = N * 2;
int h[N], e[M], ne[M], idx;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

PII dfs(int u, int fa)
{
    PII res = {0, u};
    for (int i = h[u]; ~i; i = ne[i])
    {
        int ver = e[i];
        if (ver == fa) continue;
        auto t = dfs(ver, u);
        t.first ++ ;
        if (res < t) res = t; 
    }
    return res;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    int a = dfs(1, -1).second;
    int b = dfs(a, -1).first;
    printf("%d", b);

    return 0;
}
