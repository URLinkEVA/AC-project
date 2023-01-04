#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    if (n == 1)
    {
        if (m == 0) puts("1");
        else puts("-1");
    }
    else if (m < n / 2) puts("-1");
    else
    {
        int d = m - (n / 2 - 1);
        printf("%d %d ", d, d * 2);
        for (int i = 1; i <= n - 2; i ++ )
            printf("%d ", 2 * d + i);
    }
    return 0;
}
