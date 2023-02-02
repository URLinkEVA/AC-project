#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[10];

bool check(int x)
{
    memset(a, 0, sizeof a);
    while (x)
    {
        a[x % 10] ++ ;
        if (a[x % 10] > 1) return false;
        x /= 10;
    }
    return true;
}

int main()
{
    int a;
    cin >> a;
    for (int i = a + 1; ; i ++ )
    {
        if (check(i))
        {
            cout << i;
            return 0;
        }
    }
}
