#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int INF = 1000;
int ans = INF;
int n;

void dfs(LL x, int d)
{
    bool st[10] = {0};
    int cnt = 0;
    for (LL y = x; y; y /= 10)
    {
        cnt ++ ;
        st[y % 10] = true;
    }

    if (d + n - cnt >= ans) return;

    if (cnt == n)
    {
        ans = d;
        return;
    }

    for (int i = 9; i >= 2; i -- )
        if (st[i])
            dfs(x * i, d + 1);
}

int main()
{
    LL x;
    cin >> n >> x;
    dfs(x, 0);
    if (ans == INF) ans = -1;
    cout << ans;
    return 0;
}
