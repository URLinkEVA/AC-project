#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, k, a, b, q;
int d[N];
int tr1[N], tr2[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int tr[], int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += v;
}

int query(int tr[], int x)
{
    int sum = 0;
    for (int i = x; i; i -= lowbit(i))
        sum += tr[i];
    return sum;
}

int main()
{
    scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
    while (q -- )
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            add(tr1, x, min(d[x] + y, b) - min(d[x], b));
            add(tr2, x, min(d[x] + y, a) - min(d[x], a));
            d[x] += y;
        }
        else
        {
            int p;
            scanf("%d", &p);
            printf("%d\n", query(tr1, p - 1) + query(tr2, n) - query(tr2, p + k - 1));
        }
    }

    return 0;
}
