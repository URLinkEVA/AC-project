#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 4000010;

int n, m;
int p[N];

int get(int x, int y)
{
    if (x == 1) return y;
    if (y == m) return m + x - 1;
    if (x == n) return m + n - 1 + m - y;
    if (y == 1) return m + n - 1 + m - 1 + n - x;
    return 0;
}

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int merge(int x, int y)
{
    x = find(x), y = find(y);
    p[x] = y;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= 2 * (n + m) - 4; i ++ ) p[i] = i;

    if (n > m) swap(n, m);

    for (int i = 1; i <= m; i ++ )
    {
        if (i <= n)
        {
            merge(get(1, i), get(i, 1));
            merge(get(n, i), get(n - i + 1, 1));
        }
        else
        {
            merge(get(1, i), get(n, i - n + 1));
            merge(get(n, i), get(1, i - n + 1));
        }

        if (m - i + 1 <= n)
        {
            merge(get(1, i), get(m - i + 1, m));
            merge(get(n, i), get(n - m + i, m));
        }
        else
        {
            merge(get(1, i), get(n, i + n - 1));
            merge(get(n, i), get(1, i + n - 1));
        }
    }

    int res = 0;
    for (int i = 1; i <= 2 * (n + m) - 4; i ++ )
        if (p[i] == i)
            res ++ ;

    cout << res << endl;
    return 0;
}
