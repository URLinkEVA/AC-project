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
        int n;
        cin >> n;
        int x;
        cin >> x;

        bool first_min = true;
        for (int i = 2; i <= n; i ++ )
        {
            int y;
            cin >> y;
            if (y < x) first_min = false;
        }

        if (first_min) puts("Bob");
        else puts("Alice");
    }

    return 0;
}
