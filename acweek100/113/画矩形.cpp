#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1010, MOD = 1e9 + 7;

int n, m, k;
int C[N][N];

int main()
{
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j <= i; j ++ )
            if (!j) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;

    scanf("%d%d%d", &n, &m, &k);
    if (k * 2 > n - 1 || k * 2 > m - 1)
        puts("0");
    else
        printf("%lld\n", (LL)C[n - 1][k * 2] * C[m - 1][k * 2] % MOD);

    return 0;
}
