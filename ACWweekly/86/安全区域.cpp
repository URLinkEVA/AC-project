#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;
int n, m;
bool h[N], v[N]; // hor行，ver列

int main()
{
    cin >> n >> m;
    int r = 0, c = 0;
    while (m -- ){
        int x, y;
        cin >> x >> y;
        if(!h[x]) r++, h[x] = true;
        if(!v[y]) c++, v[y] = true;
        cout << (LL)(n-r)*(n-c) << " ";
    }
    return 0;
}
