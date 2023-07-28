#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int q[100010], w[100010];
int n, m;

void insert(int l, int r, int c)
{
    w[l] += c;
    w[r + 1] -= c;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> q[i];
    for (int i = 1; i <= n; i ++ ) insert(i, i, q[i]);
    while(m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }
    for (int i = 1; i <= n; i ++ ) w[i] += w[i - 1];
    for (int i = 1; i <= n; i ++ ) cout << w[i] << ' ';
    return 0;
}
