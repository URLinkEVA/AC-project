#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
int cnt[N];

int main()
{
    int n;
    cin >> n;
    int res = 0;
    while (n -- )
    {
        int h, m;
        cin >> h >> m;
        int t = h*60 + m;
        res = max(res, ++ cnt[t]);
    }
    cout << res << endl;
    return 0;
}
