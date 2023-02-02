#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
int a[N], f[N][3];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    memset(f, 0x3f, sizeof f);

    f[0][2] = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if (a[i - 1] == 2 || a[i - 1] == 3)
        {
            f[i][1] = min(f[i][1], f[i - 1][0]);
            f[i][2] = min(f[i][2], f[i - 1][0] + 1);
        }
        if (a[i - 1] == 1 || a[i - 1] == 3)
        {
            f[i][0] = min(f[i][0], f[i - 1][1]);
            f[i][2] = min(f[i][2], f[i - 1][1] + 1);
        }
        f[i][0] = min(f[i][0], f[i - 1][2]);
        f[i][1] = min(f[i][1], f[i - 1][2]);
        f[i][2] = min(f[i][2], f[i - 1][2] + 1);
    }

    int res = f[n][2];
    if (a[n] == 1) res = min(res, f[n][1]);
    if (a[n] == 2) res = min(res, f[n][0]);
    if (a[n] == 3) res = min(res, min(f[n][0], f[n][1]));

    cout << res;

    return 0;
}
