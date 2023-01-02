#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main() {
    srand(0);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T; T -= 1) {
        int k, n, m;
        cin >> k >> n >> m;
        vector<pair<int, int>> G(m);
        for (auto& [u, v] : G) cin >> u >> v;
        if (k == 1) {
            cout << "1\n1 1\n";
            continue;
        }
        vector<int> p(k + 1), u(k + 1), v(k + 1);
        vector<string> t(k + 1);
        vector<vector<int>> Tr(k + 1);
        for (int i = 2; i <= k; i += 1) {
            cin >> p[i] >> t[i] >> u[i] >> v[i];
            Tr[p[i]].push_back(i);
        }
        vector<int> time(k + 1);
        time[1] = m - 1;
        function<void(int)> DFST = [&](int x){
            if (x != 1) {
                time[x] = G.size();
                if (t[x] == "add") G.emplace_back(u[x], v[x]);
                else G.emplace_back(-u[x], -v[x]);
            }
            for (int y : Tr[x]) DFST(y);
            if (x != 1) {
                if (t[x] == "add") G.emplace_back(-u[x], -v[x]);
                else G.emplace_back(u[x], v[x]);
            }
        };
        DFST(1);
        int gn = G.size() - 1;
        vector<vector<pair<int, int>>> op((gn + 1) << 2);
        function<void(int, int, int, int, int, int, int)> add = [&](int v, int tl, int tr, int L, int R, int x, int y) {
            if (tl >= L and tr <= R) {
                op[v].emplace_back(x, y);
                return;
            }
            int tm = (tl + tr) / 2;
            if (L <= tm) add(v << 1, tl, tm, L, R, x, y);
            if (R > tm) add(v << 1 | 1, tm + 1, tr, L, R, x, y);
        };
        map<pair<int, int>, int> rmt;
        for (int i = gn; i >= 0; i -= 1) {
            if (G[i].first < 0) rmt[{-G[i].first, -G[i].second}] = i;
            else {
                if (not rmt.count(G[i])) rmt[G[i]] = gn + 1;
                add(1, 0, gn, i, rmt[G[i]] - 1, G[i].first, G[i].second);
            }
        }
        vector<vector<int>> base(2, vector<int>(n + 1));
        base[0][0] = base[1][0] = 1;
        base[0][1] = rand() % mod;
        base[1][1] = rand() % mod;
        for (int i = 0; i < 2; i += 1)
            for (int j = 1; j <= n; j += 1)
                base[i][j] = (LL)base[i][j - 1] * base[i][1] % mod;
        vector<int> mn(n + 1), sz(n + 1), pr(n + 1);
        for (int i = 1; i <= n; i += 1) {
            mn[i] = pr[i] = i;
            sz[i] = 1;
        }
        vector<int> h(2);
        for (int i = 0; i < 2; i += 1)
            for (int j = 1; j <= n; j += 1)
                h[i] = (h[i] + (LL)base[i][j] * mn[j]) % mod;
        auto init = h;
        vector<vector<int>> vh;
        function<int(int)> fp = [&](int u) {
            return pr[u] == u ? u : fp(pr[u]);
        };
        function<void(int, int, int)> DFS = [&](int v, int tl, int tr) {
            stack<pair<int*, int>> s;
            auto change = [&](int& x, int y){
                s.push({&x, x});
                x = y;
            };
            for (auto [x, y] : op[v]) {
                int px = fp(x), py = fp(y);
                if (px == py) continue;
                if (sz[px] > sz[py]) swap(px, py);
                for (int i = 0; i < 2; i += 1)
                    change(h[i], (h[i] + mod * 2 - (LL)base[i][px] * mn[px] % mod - (LL)base[i][py] * mn[py] % mod) % mod);
                change(mn[py], min(mn[px], mn[py]));
                change(sz[py], sz[px] + sz[py]);
                change(pr[px], py);
                for (int i = 0; i < 2; i += 1) {
                    change(base[i][py], (base[i][px] + base[i][py]) % mod);
                    change(h[i], (h[i] + (LL)base[i][py] * mn[py]) % mod);
                }
            }
            if (tl == tr)
                vh.push_back(h);
            else{
                int tm = (tl + tr) / 2;
                DFS(v << 1, tl, tm);
                DFS(v << 1 | 1, tm + 1, tr);
            }
            while (not s.empty()) {
                *s.top().first = s.top().second;
                s.pop();
            }
        };
        DFS(1, 0, gn);
        map<vector<int>, vector<int>> mp;
        for (int i = 1; i <= k; i += 1) {
            if (i == 1 and time[i] == -1) mp[init].push_back(i);
            else mp[vh[time[i]]].push_back(i);
        }
        cout << mp.size() << "\n";
        for (auto& [_, v] : mp) {
            cout << v.size();
            for (int x : v) cout << " " << x;
            cout << "\n";
        }
    }
}
