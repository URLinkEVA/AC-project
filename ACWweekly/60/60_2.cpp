#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, k;
int w[N];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);
    sort(w + 1, w + n + 1);
    n = unique(w + 1, w + n + 1) - w - 1;

    for (int i = 1; i <= k; i ++ )
        if (i <= n) printf("%d\n", w[i] - w[i - 1]);
        else printf("%d\n", 0);
    return 0;
}
