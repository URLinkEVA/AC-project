#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T; T -= 1) {
        int n, m, p, x, a, b, c;
        cin >> n >> m >> p >> x >> a >> b >> c;
        auto next = [&](){
            x = ((LL)a * x % p * x + (LL)b * x + c) % p;
            return x;
        };
        vector<int> s(n), t(m);
        for (int& si : s) si = next();
        for (int& ti : t) ti = next();
        int cyc = -1, sp = 0;
        for (int i = 0; i < m; i += 1)
            if (t[i] == s.back()) {
                cyc = i + 1;
                break;
            }
        if (cyc == -1) {
            for (int i = n - 1; i >= 0; i -= 1)
                if (t.back() == s[i]) {
                    cyc = m + n - i - 1;
                    break;
                }
        }
        if (cyc != -1) {
            int i = n - 1, j = cyc - 1;
            while (i >= 0 and j >= -n) {
                int x = s[i], y = j >= 0 ? (j >= m ? x : t[j]) : s[n + j];
                if (x == y) {
                    i -= 1;
                    j -= 1;
                }
                else break;
            }
            i += 1;
            j += 1;
            j = (j % cyc + cyc) % cyc;
            int ans = 0;
            while (i < n) {
                ans = max(ans, min(n - i, m - j));
                i += 1;
                j += 1;
                if (j == cyc) j = 0;
            }
            cout << ans << "\n";
            continue;
        }
        else cout << "0\n";
    }
}
