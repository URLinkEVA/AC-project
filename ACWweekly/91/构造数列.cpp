#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T -- )
    {
        string str;
        cin >> str;

        int cnt = 0;
        for (auto c: str)
            if (c != '0')
                cnt ++ ;

        cout << cnt << endl;
        for (int i = str.size() - 1, t = 1; i >= 0; i --, t *= 10)
            if (str[i] != '0')
                cout << (str[i] - '0') * t << ' ';
        cout << endl;
    }

    return 0;
}
