#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int p[N], s[N];
int sz[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) p[i] = i, s[i] = 1;

    int cnt = 0;
    for (int i = 1; i <= m; i ++ )
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x = find(x), y = find(y);

        if (x != y)
        {
            s[y] += s[x];
            p[x] = y;
        }
        else cnt ++ ;

        int tt = 0;
        for (int j = 1; j <= n; j ++ )
            if (find(j) == j)
                sz[tt ++ ] = s[j];

        sort(sz, sz + tt, greater<int>());
        int sum = 0;
        for (int j = 0; j < tt && j < cnt + 1; j ++ )
            sum += sz[j];
        printf("%d\n", sum - 1);
    }

    return 0;
}
