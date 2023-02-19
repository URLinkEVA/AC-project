#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int b[N];

int main()
{
    scanf("%d%d", &n, &m);

    while (m -- )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        b[l] ++, b[r + 1] -- ;
    }

    for (int i = 1; i <= n; i ++ )
    {
        b[i] += b[i - 1];
        if (b[i] != 1)
        {
            printf("%d %d\n", i, b[i]);
            return 0;
        }
    }

    puts("OK");

    return 0;
}
