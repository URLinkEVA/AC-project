#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 100010;
int n;
LL s[N], f[N];

int main()
{
    cin >> n;
    while (n -- )
    {
        int x;
        cin >> x;
        s[x] += x;
    }
    for (int i = 1; i < N; i ++ )
        f[i] = max(f[i - 1], f[max(0, i - 2)] + s[i]);
        
    cout << (LL)f[N - 1] << endl;
    return 0;
}
