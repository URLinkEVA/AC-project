#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 1010;

int n, m;
int w[N], a[M], p[N];
bool st[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) cin >> w[i];
    for (int i = 0; i < m; i ++ )
    {
        scanf("%d", &a[i]);
        a[i] -- ;
    }

    int res = 0, k = 0;
    for (int i = 0; i < m; i ++ )
    {
        int j = a[i];
        if (st[j])
        {
            for (int u = 0; u < k; u ++ )
            {
                if (p[u] != j) res += w[p[u]];
                else
                {
                    for (int v = u; v > 0; v -- )
                        p[v] = p[v - 1];
                    p[0] = j;
                    break;
                }
            }
        }
        else
        {
            for (int u = k; u > 0; u -- )
            {
                p[u] = p[u - 1];
                res += w[p[u]];
            }
            p[0] = j;
            st[j] = true;
            k ++ ;
        }
    }

    printf("%d\n", res);
    return 0;
}
