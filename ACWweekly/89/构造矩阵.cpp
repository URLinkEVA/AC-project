#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int a[N][N], b[N][N];

bool check()
{
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            if (b[i][j])
            {
                int cnt = 0;
                for (int k = 0; k < m; k ++ ) cnt += a[i][k];
                for (int k = 0; k < n; k ++ ) cnt += a[k][j];
                if (!cnt) return false;
            }
    return true;
}

int main()
{
    cin >> n >> m;

    memset(a, -1, sizeof a);
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
        {
            cin >> b[i][j];
            if (!b[i][j])
            {
                for (int k = 0; k < m; k ++ ) a[i][k] = 0;
                for (int k = 0; k < n; k ++ ) a[k][j] = 0;
            }
        }

    if (check())
    {
        puts("YES");
        for (int i = 0; i < n; i ++ )
        {
            for (int j = 0; j < m; j ++ )
                printf("%d ", !!a[i][j]);
            puts("");
        }
    }
    else
    {
        puts("NO");
    }

    return 0;
}
