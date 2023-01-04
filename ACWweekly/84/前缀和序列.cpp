#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n, m;
int a[N], b[N];
LL s1[N], s2[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);

    for (int i = 1; i <= n; i ++ )
    {
        s1[i] = s1[i - 1] + a[i];
        s2[i] = s2[i - 1] + b[i];
    }

    scanf("%d", &m);
    while (m -- )
    {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1)
            printf("%lld\n", s1[r] - s1[l - 1]);
        else
            printf("%lld\n", s2[r] - s2[l - 1]);
    }

    return 0;
}
