#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 20;
int n, l, r, x;
int w[N];

int dfs(int u, int cnt, int sum, int minw, int maxw)
{
    if (u == n)
    {
        if (cnt >= 2 && sum >= l && sum <= r && maxw - minw >= x)
            return 1;
        return 0;
    }

    int res = 0;
    res += dfs(u + 1, cnt, sum, minw, maxw);
    res += dfs(u + 1, cnt + 1, sum + w[u], min(minw, w[u]), max(maxw, w[u]));

    return res;
}

int main()
{
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i ++ ) cin >> w[i];

    cout << dfs(0, 0, 0, 1e7, 0) << endl;
    return 0;
}
