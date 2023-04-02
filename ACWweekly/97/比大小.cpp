#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

LL get()
{
    int n, b;
    cin >> n >> b;
    LL res = 0;
    while(n--)
    {
        int x;
        cin >> x;
        res = res * b + x; // pow也可
    }
    return res;
}

int main()
{
    LL x = get();
    cout << x << endl;
    LL y = get();
    if(x < y) cout << "<";
    if(x > y) cout << ">";
    else cout << "=";
    return 0;
}
