#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 2010;

int n, m;
bool g[N][N];
int dist[N][N];

void bfs()
{
    memset(dist, 0x3f, sizeof dist);
    queue<PII> q;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            if (g[i][j])
            {
                q.push({i, j});
                dist[i][j] = 0;
            }

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while (q.size())
    {
        auto t = q.front();
        q.pop();

        int distance = dist[t.x][t.y];

        for (int i = 0; i < 4; i ++ )
        {
            int x = t.x + dx[i], y = t.y + dy[i];
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (dist[x][y] > distance + 1)
            {
                dist[x][y] = distance + 1;
                q.push({x, y});
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int k;
    scanf("%d", &k);
    while (k -- )
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x][y] = true;
    }

    bfs();

    int x = 1, y = 1;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            if (dist[x][y] < dist[i][j])
            {
                x = i;
                y = j;
            }

    printf("%d %d\n", x, y);
    return 0;
}
