#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 100000010;

int a[N];

int main()
{
    int n, d;
    int s = 0;
    cin >> n >> d;
    for(int i = 0;i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i ++ )
        for(int j = 0; j < i; j++)
            if(abs(a[i] - a[j]) <= d) s+=2;

    cout << s << endl;
    return 0;
}
