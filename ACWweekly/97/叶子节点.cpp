#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = N * 2; // 无向边，每个边存两遍

int n, m;
int h[N], w[N], e[M], ne[M], idx; // w表示颜色

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u, int fa, int cnt, bool valid)
{
    if(w[u]) cnt++;
    else cnt = 0;
    if(cnt > m) valid = false;
    
    int res = 0, sons = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(j == fa) continue;
        sons ++;
        res += dfs(j, u, cnt, valid);
    }
    
    if(!sons && valid) res++;
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b); // 读入两个边两个点
        add(a,b), add(b,a); // 无向边建两个方向
    }
    
    printf("%d\n", dfs(1, -1, 0, true));
    return 0;
}
