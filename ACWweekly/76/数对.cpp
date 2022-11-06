#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 10010;
int q[N];

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i ++ ) ++q[s[i]];
    long long ans = 0;
    for (int i = 0; i <= 128; i ++ ) ans += 1ll*q[i]*q[i];
    cout << ans;
    return 0;
}
