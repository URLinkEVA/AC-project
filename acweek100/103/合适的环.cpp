#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 4010;
int n, m;
int d[N];
bool g[N][N];
struct Edge{
    int a, b;
}edge[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
        d[a] ++, d[b] ++ ;
        edge[i] = {a, b};
    }

    int res = -1;
    for (int i = 0; i < m; i ++ )
    {
        int a = edge[i].a, b = edge[i].b;
        for (int c = 1; c <= n; c ++ )
            if (g[a][c] && g[b][c])
            {
                int cnt = d[a] + d[b] + d[c] - 6;
                if (res == -1 || res > cnt)
                    res = cnt;
            }
    }
    cout << res;
    return 0;
}
