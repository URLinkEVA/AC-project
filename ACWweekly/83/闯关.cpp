#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 110;

int n, m;
int w[N], id[N];
bool st[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    for (int i = 0; i < m; i ++ )
    {
        cin >> id[i];
        st[id[i]] = true;
    }

    sort(id, id + m, [&](int a, int b) {
        return w[a] > w[b];
    });

    LL res = 0;
    for (int i = 1; i <= n; i ++ )
        if (!st[i])
            res += w[i];

    for (int i = 0; i < m; i ++ )
        res = max(res * 2, res + w[id[i]]);

    cout << res << endl;
    return 0;
}
