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
    for (int i = 0; i < n - 1; i ++ ) cin >> q[i];
    int s = 0;
    int a, b;
    cin >> a >> b;
    for (int i = a - 1; i < b - 1; i ++ )
        s += q[i];
    
    cout << s << endl;
    return 0;
}
