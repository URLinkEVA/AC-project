#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

long long n, sum = 0;
long long w[200010], h[200010], hh[200010];

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> w[i] >> h[i];
        sum += w[i];
    }
    memcpy(hh, h, sizeof(h));

    sort(h + 1, h + 1 + n);

    for(int i = 1;i <= n;i++)
    {
        if(hh[i] != h[n]) cout << (sum - w[i]) * h[n] << " ";
        else cout << (sum - w[i]) * h[n - 1] << " ";
    }
    return 0;
}
