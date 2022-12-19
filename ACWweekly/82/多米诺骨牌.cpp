#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    string str;
    cin >> n >> str;

    int l = 0;
    while (l < n && str[l] == '.') l ++ ;

    int res = 0;
    if (l == n) res = n;
    else
    {
        if (str[l] == 'R') res = l;
        int r = n - 1;
        while (str[r] == '.') r -- ;
        if (str[r] == 'L') res += n - 1 - r;

        for (int i = l + 1, cnt = 0; i <= r; i ++ )
            if (str[i] == '.') cnt ++ ;
            else
            {
                if (str[i] == 'L') res += cnt % 2;
                else res += cnt;
                cnt = 0;
            }
    }

    cout << res << endl;
    return 0;
}
