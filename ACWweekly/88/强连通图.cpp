#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 30;
int n, m, tot;
int L[N], C[N];
bool st[N][N];

void dfs(int x, int y)
{
    if (st[x][y]) return;
    tot ++ , st[x][y] = true;
    if (L[x] && y > 1) dfs(x, y - 1);
    if (!L[x] && y < m) dfs(x, y + 1);
    if (C[y] && x > 1) dfs(x - 1, y);
    if (!C[y] && x < n) dfs(x + 1, y);
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i ++ )
    {
        char c;
        cin >> c;
        if (c == '<') L[i] = 1;
    }

    for (int i = 1; i <= m; i ++ )
    {
        char c;
        cin >> c;
        if (c == '^') C[i] = 1;
    }

    bool flag = true;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
        {
            memset(st, 0, sizeof st);
            tot = 0;
            dfs(i, j);
            if (tot != n * m) flag = false;
        }

    puts(flag ? "YES" : "NO");

    return 0;
}
