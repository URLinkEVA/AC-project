#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int cnt[N];

int main()
{
    cin >> n >> m;
    int tot = 0;
    while (m -- )
    {
        int x;
        cin >> x;
        if (!cnt[x]) tot ++ ;
        cnt[x] ++ ;

        if (tot == n)
        {
            cout << "1";
            for (int i = 1; i <= n; i ++ )
                if ( -- cnt[i] == 0)
                    tot -- ;
        }
        else cout << "0";
    }

    return 0;
}
