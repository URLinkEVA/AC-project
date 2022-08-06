//二进制枚举 O(n2^n)
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;

int n;
int w[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> w[i];

    bool res = false;
    for (int i = 0; i < 1 << n; i ++ )
    {
        int s = 0;
        for (int j = 0; j < n; j ++ )
            if (i >> j & 1)
                s += w[j];
            else
                s -= w[j];

        if (s % 360 == 0)
        {
            res = true;
            break;
        }
    }

    if (res) cout << "YES";
    else cout << "NO";

    return 0;
}


//DFS O(2n)
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;

int n;
int w[N];

bool dfs(int u, int s)
{
    if (u == n) return s % 360 == 0;

    if (dfs(u + 1, s + w[u])) return true;
    if (dfs(u + 1, s - w[u])) return true;
    return false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> w[i];

    if (dfs(0, 0)) cout << "YES";
    else cout << "NO";

    return 0;
}
