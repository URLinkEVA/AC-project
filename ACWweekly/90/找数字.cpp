#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int m, s;
    cin >> m >> s;
    if (s > m * 9 || !s && m > 1) puts("-1 -1");
    else
    {
        string a(m, ' '), b(m, ' ');
        int sum = s;
        for (int i = m - 1; i; i -- )
        {
            int t = min(9, sum - 1);
            a[i] = t + '0';
            sum -= t;
        }
        a[0] = sum + '0';
        sum = s;
        for (int i = 0; i < m; i ++ )
        {
            int t = min(9, sum);
            b[i] = t + '0';
            sum -= t;
        }
        cout << a << ' ' << b << endl;
    }

    return 0;
}
