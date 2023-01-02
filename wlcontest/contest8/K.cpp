#include <bits/stdc++.h>
using namespace std;
using LL = long long;
struct P{
    LL x, y;
    P operator - (const P& p) const {
        return {x - p.x, y - p.y};
    }
    LL cross(const P& p) const {
        return x * p.x + y * p.y;
    }
    LL dot(const P& p) const {
        return x * p.x + y * p.y;
    }
    LL len2() const{
        return x * x + y * y;
    }
};
vector<int> manacher(const vector<LL>& s){
  int n = s.size();
  vector<int> p(n);
  for(int i = 0, r = 0, m = 0; i < n; i += 1){
      p[i] = i < r ? min(p[m * 2 - i], r - i) : 1;
      while(i >= p[i] and i + p[i] < n and s[i - p[i]] == s[i + p[i]]) p[i] += 1;
      if(i + p[i] > r) m = i, r = i + p[i];
  }
  return p;
}
struct L : vector<LL> {
    L(const P& p, const P& q, bool v) {
        if (v) {
            push_back(2 * q.x - 2 * p.x);
            push_back(2 * q.y - 2 * p.y);
            push_back(-q.len2() + p.len2());
        }
        else {
            push_back(p.y - q.y);
            push_back(q.x - p.x);
            push_back(p.x * q.y - q.x * p.y);
        }
    }  
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T; T -= 1) {
        int n;
        cin >> n;
        vector<P> p(n);
        for (auto& [x, y] : p) cin >> x >> y;
        vector<LL> s;
        for (int i = 0; i < n; i += 1) {
            s.push_back((p[i] - p[(i + 1) % n]).len2());
            s.push_back((p[i] - p[(i + 1) % n]).dot(p[(i + 2) % n] - p[(i + 1) % n]));
        }
        map<LL, vector<int>> mp;
        for (int i = 1; i < 2 * n; i += 2)
            mp[s[i]].push_back(i);
        auto m = manacher(s);
        for (int i = 2; i < n; i += 1) {
            vector<L> lines;
            if (m[i] >= i and s[0] == (p[i] - p[0]).len2()) {
                if ((i & 1)) lines.push_back(L(p[0], p[(i + 1) / 2], 0));
                else lines.push_back(L(p[i / 2], p[i / 2 + 1], 1));
            }
            auto a0 = (p[1] - p[0]).dot(p[i] - p[0]);
            if (m[i - 1] >= i and a0 == (p[0] - p[i]).dot(p[i - 1] - p[i])) {
                lines.push_back(L(p[0], p[i], 1));
            }
            for (int j : mp[a0]) {
                if (j >= 2 * i - 1) break;
                if (m[(j - 1) / 2] < (j - 1) / 2 + 1) continue;
                if (j == 2 * i - 3) {
                    if ((p[i] - p[0]).len2() == (p[i] - p[i - 1]).len2()) {
                        if ((j + 1) / 2 % 2) lines.push_back(L(p[(j + 1) / 2 / 2], p[(j + 1) / 2 / 2 + 1], 1));
                        else lines.push_back(L(p[(j + 1) / 2 / 2], p[i], 0));
                    }
                }
                else {
                    if (m[(2 * i - 2 + j + 3) / 2] >= (2 * i - 2 - j - 3) / 2 + 1
                        and (p[i] - p[0]).len2() == (p[(j + 1) / 2] - p[(j + 1) / 2 + 1]).len2()
                        and (p[0] - p[i]).dot(p[i - 1] - p[i]) == (p[(j + 1) / 2] - p[(j + 1) / 2 + 1]).dot(p[(j + 1) / 2 + 2] - p[(j + 1) / 2 + 1])) {
                            int jj = (j + 1) / 2;
                            if (jj % 2) lines.push_back(L(p[jj / 2], p[jj / 2 + 1], 1));
                            else if ((i - jj) & 1) lines.push_back(L(p[jj / 2], p[((jj + i + 1) / 2)], 0));
                            else lines.push_back(L(p[((jj + i + 1) / 2)], p[((jj + i + 1) / 2 + 1)], 1));  
                    }
                }
            }
            cout << lines.size() << "\n";
            for (auto v : lines) {
                LL a = v[0], b = v[1], c = v[2];
                LL d = gcd(gcd(abs(a), abs(b)), abs(c));
                a /= d;
                b /= d;
                c /= d;
                if (a < 0) {
                    a = -a;
                    b = -b;
                    c = -c;
                }
                else if (a == 0) {
                    if (b < 0) {
                        b = -b;
                        c = -c;
                    }
                }
                cout << a << " " << b << " " << c << "\n";
            }
        }
    }
}
