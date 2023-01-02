#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T; T -= 1) {
        int n;
        cin >> n;
        vector<vector<int>> G(n + 1);
        for (int i = 1, u, v; i < n; i += 1) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> size(n + 1), ms(n + 1);
        function<void(int, int)> findroot = [&](int u, int p) {
            size[u] = 1;
            for (int v : G[u]) if (v != p) {
                findroot(v, u);
                ms[u] = max(size[v], ms[u]);
                size[u] += size[v];
            }
            ms[u] = max(ms[u], n - size[u]);
        };
        findroot(1, 0);
        int mn = *min_element(ms.begin() + 1, ms.end());
        vector<int> root;
        for (int i = 1; i <= n; i += 1)
            if (mn == ms[i])
                root.push_back(i);
        vector<int> height(n + 1), p(n + 1);
        vector<vector<int>> H(n);
        vector<pair<int, int>> h(n + 1);
        vector<vector<pair<int, int>>> sh(n + 1);
        function<void(int)> DFS = [&](int u) {
            for (int v : G[u]) {
                if (v != p[u]) {
                    p[v] = u;
                    DFS(v);
                    height[u] = max(height[v] + 1, height[u]);
                }
            }
            H[height[u]].push_back(u);
        };
        DFS(root[0]);
        for (int i = 0; i < n; i += 1) {
            map<vector<pair<int, int>>, int> mp;
            for (int j : H[i]) {
                for (int k : G[j]) if (k != p[j])
                    sh[j].push_back(h[k]);
                sort(sh[j].begin(), sh[j].end());
                mp[sh[j]] = 0;
            }
            int m = 0;
            for (auto& [x, y] : mp) y = m ++;
            for (int j : H[i]) h[j] = {height[j], mp[sh[j]]};
        }
        if (root.size() == 2) {
            vector<pair<int, int>> s;
            for (int v : G[root[0]])
                if (v != root[1]) s.push_back(h[v]);
            sort(s.begin(), s.end());
            if (s == sh[root[1]]) {
                vector<int> d(n + 1), hh(n + 1);
                vector<int> ch(n + 1);
                function<void(int)> DFS = [&](int u) {
                    hh[u] = ch[abs(d[u])] ++;
                    vector<int> s;
                    for (int v : G[u]) if (v != root[1] and v != p[u])
                        s.push_back(v);
                    sort(s.begin(), s.end(), [&](int u, int v){
                        return h[u] < h[v];
                    });
                    for (int v : s) {
                        d[v] = d[u] + (d[u] > 0 ? 1 : -1);
                        DFS(v);
                    }
                };
                d[root[0]] = 1;
                DFS(root[0]);
                fill(ch.begin(), ch.end(), 0);
                d[root[1]] = -1;
                DFS(root[1]);
                cout << "YES\n";
                for (int i = 1; i <= n; i += 1)
                    cout << d[i] << " " << hh[i] << "\n";
                cout << "1 0 0\n";
                continue;
            }
        }
        map<pair<int, int>, int> cntr;
        for (int v : G[root[0]]) {
            cntr[h[v]] += 1;
        }
        vector<pair<int, int>> sp;
        for (auto [x, y] : cntr) {
            if (y & 1) sp.push_back(x);
        }
        if (sp.size() >= 3) {
            cout << "NO\n";
            continue;
        }
        vector<vector<int>> v;
        int fail = 0;
        for (int i = 0; i < sp.size(); i += 1) {
            v.emplace_back();
            function<void(int)> DFS = [&](int u) {
                v.back().push_back(u);
                map<pair<int, int>, int> cntr;
                for (int v : G[u]) if (v != p[u])
                    cntr[h[v]] += 1;
                vector<pair<int, int>> sp;
                for (auto [x, y] : cntr)
                    if (y & 1) sp.push_back(x);
                if (sp.size() > 1) {
                    fail = 1;
                    return;
                }
                if (sp.size() == 1)
                    for (int v : G[u])
                        if (h[v] == sp[0]) {
                            DFS(v);
                            break;
                        }
            };
            for (int j : G[root[0]])
                if (h[j] == sp[i]) {
                    DFS(j);
                    break;
                }
        }
        if (fail) {
            cout << "NO\n";
            continue;
        }
        {
            vector<int> ph = {root[0]};
            if (v.size() >= 1) {
                for (int x : v[0]) ph.push_back(x);
                if (v.size() == 2) {
                    reverse(ph.begin(), ph.end());
                    for (int x : v[1]) ph.push_back(x);
                }
            }
            vector<int> d(n + 1), hh(n + 1), inp(n + 1), pch(n + 1), mch(n + 1);
            for (int i = 0; i < ph.size(); i += 1) {
                hh[ph[i]] = i;
                inp[ph[i]] = 1;
            }
            function<void(int)> DFS = [&](int u) {
                vector<int> s;
                for (int v : G[u]) if (not inp[v] and v != p[u])
                    s.push_back(v);
                sort(s.begin(), s.end(), [&](int u, int v){
                    return h[u] < h[v];
                });
                if (d[u] == 0) {
                    for (int i = 0; i < s.size(); i += 2) {
                        d[s[i]] = 1;
                        DFS(s[i]);
                        d[s[i + 1]] = -1;
                        DFS(s[i + 1]);
                    }
                }
                if (d[u] > 0) {
                    hh[u] = pch[d[u]] ++;
                    for (int v : s) {
                        d[v] = d[u] + 1;
                        DFS(v);
                    }
                }
                if (d[u] < 0) {
                    hh[u] = mch[-d[u]] ++;
                    for (int v : s) {
                        d[v] = d[u] - 1;
                        DFS(v);
                    }
                }
            };
            for (int u : ph)
                DFS(u);
            cout << "YES\n";
            for (int i = 1; i <= n; i += 1)
                cout << d[i] << " " << hh[i] << "\n";
            cout << "1 0 0\n";
        }
    }
}
