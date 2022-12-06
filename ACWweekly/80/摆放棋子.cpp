#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 11, MOD = 1e8;

int n1, n2, k1, k2;
int f[N][N][M][M];

int main()
{
    cin >> n1 >> n2 >> k1 >> k2;

    f[0][0][0][0] = 1;
    for (int i = 0; i <= n1; i ++ )
        for (int j = 0; j <= n2; j ++ )
            for (int k = 0; k <= k1; k ++ )
                for (int u = 0; u <= k2; u ++ )
                {
                    int v = f[i][j][k][u];
                    if (i + 1 <= n1 && k + 1 <= k1)
                        f[i + 1][j][k + 1][0] = (f[i + 1][j][k + 1][0] + v) % MOD;
                    if (j + 1 <= n2 && u + 1 <= k2)
                        f[i][j + 1][0][u + 1] = (f[i][j + 1][0][u + 1] + v) % MOD;
                }

    int res = 0;
    for (int i = 0; i <= k1; i ++ )
        for (int j = 0; j <= k2; j ++ )
            res = (res + f[n1][n2][i][j]) % MOD;

    cout << res << endl;

    return 0;
}
