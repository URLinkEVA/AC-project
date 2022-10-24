#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int q[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> q[i];
    int res = 1000;
    for (int i = 0; i < n; i ++ )
        res = min(res, abs(q[i] - q[(i+1)%n]));
        
    cout << res << endl;
    return 0;
}
