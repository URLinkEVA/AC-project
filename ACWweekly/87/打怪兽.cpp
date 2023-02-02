#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int a[N],b[N];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
    {
        int mm = 0;
        scanf("%d", &a[i]);
        for (int j = 1; j <= i; j ++ ) b[j] = a[j];
        sort(b + 1, b + i + 1, cmp);
        for (int j = 1; j <= i; j += 2) mm += b[j];
        if (m < mm)
        {
            printf("%d", i - 1);
            return 0;
        }
    }
    printf("%d", n);
    return 0;
}
