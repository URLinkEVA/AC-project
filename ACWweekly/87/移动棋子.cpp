#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int pi, pj;
    for (int i = 0; i < 5; i ++ )
        for (int j = 0; j < 5; j ++ )
        {
            int x;
            cin >> x;
            if(x) pi = i, pj = j;
        }
    cout << abs(pi-2) + abs(pj-2);
    return 0;
}
