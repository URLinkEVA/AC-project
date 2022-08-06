#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        LL a, b, c;
        cin >> a >> b >> c;
        cout << (a+b+c)/2 <<endl;
    }
    return 0;
}
