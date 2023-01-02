#include <bits/stdc++.h>
using namespace std;
using LL = long long;
void print(__int128_t x) {
    if (x) {
        print(x / 10);
        cout << int(x % 10);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    auto sum = [&](LL n, __int128_t x) {
        __int128_t res = 0;
        LL p = 0;
        for (int i = 59; i >= 0; i -= 1)
            if ((n >> i) & 1) {
                res += ((p ^ x) >> i << i << i) + (__int128_t)(1LL << i) * ((1LL << i) - 1) / 2;
                p += 1LL << i;
            }
        return res;
    };
    int T;
    for (cin >> T; T; T -= 1) {
        int n, m;
        string d;
        LL x;
        cin >> n >> m >> d >> x;
        LL k = 1LL << (n + m);
        __int128_t ans = 0;
        if (d == "left" or d == "right") {
            if (d == "right") x = k + 1 - x;
            LL y = (x - 1) % (1 << n) * (1 << m) ^ (x - 1) / (1 << n);
            ans = y + 1 + sum(y + 1, y);
        }
        else {
            if (d == "bottom") x = k + 1 - x;
            LL z = x;
            ans = z;
            {
                __int128_t p = 0;
                __int128_t A = (x - 1) % (1 << m);
                __int128_t B = (__int128_t)((1LL << n) - 1) * (1LL << n) / 2 * (1LL << m);
                ans += sum(z / (1 << n), A) << n;
                ans += B * (z / (1 << n)); 
            }
            {
                __int128_t A = (z - 1) / (1LL << n) ^ (x - 1);
                ans += sum(z % (1 << n), A >> m) << m;
                ans += A % (1 << m) * (z % (1 << n));   
            }
        }
        print(ans);
        cout << "\n";
    }
}
