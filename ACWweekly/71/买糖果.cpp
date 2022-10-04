#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 200010;

int n;
LL T;
int w[N];

int main()
{
    cin >> n >> T;
    for (int i = 0; i < n; i ++ ) cin >> w[i];

    LL res = 0;
    while (true)
    {
        LL cnt = 0, sum = 0;
        for (int i = 0; i < n; i ++ )
            if (sum + w[i] <= T)
            {
                sum += w[i];
                cnt ++ ;
            }

        if (!sum) break;

        res += T / sum * cnt;
        T %= sum;
    }

    cout << res;
    return 0;
}
