#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 100010, M = N * 2, INF = 0x3f3f3f3f;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
vector<int> delay[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a]; h[a] = idx++;
}

int add_delay(int ver, int distance)
{
    for (int t: delay[ver])
        if (t == distance) distance ++ ;
        else if (t > distance) break;
    return distance;
}

void dijkstra()
{
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.y;
        if (st[ver]) continue;
        st[ver] = true;

        int distance = add_delay(ver, t.x);
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m -- ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    for (int i = 1; i <= n; i ++ )
    {
        int cnt;
        cin >> cnt;
        delay[i].resize(cnt);
        for (int j = 0; j < cnt; j ++ ) cin >> delay[i][j];
    }

    dijkstra();

    if (dist[n] == INF) puts("-1");
    else cout << dist[n] << endl;
    return 0;
}
