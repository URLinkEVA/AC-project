#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int c, d, n, m, k;
    cin >> c >> d;
    cin >> n >> m;
    cin >> k;
    if(k >= n * m) cout << "0";
    else
    {
        int res = 1e8;
        for (int i = 0; i <= m; i ++ )
        {
            int t = c * i;
            if (k + n * i < n * m)
                t += (n * m - n * i - k) * d;
            res = min(res, t);
        }
        cout << res << endl;
    }
    
    return 0;
}
