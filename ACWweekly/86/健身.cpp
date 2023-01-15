#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int s[3] = {0};
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        s[i % 3] += x;
    }

    int k = 0;
    for (int i = 1; i < 3; i ++ )
        if (s[i] > s[k])
            k = i;

    if (k == 0) puts("chest");
    else if (k == 1) puts("biceps");
    else puts("back");

    return 0;
}
