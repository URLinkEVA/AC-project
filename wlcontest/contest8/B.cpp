#include <bits/stdc++.h>
using namespace std;
using LL = long long;
struct Graph {
    vector<vector<int>> f;
    vector<int> dep, id;
    int h;
    void init(int n, vector<pair<int, int>> e) {
        vector<vector<int>> G(n), GT(n);
        vector<int> dfn(n), low(n);
        for (auto [x, y] : e) {
            G[x].push_back(y);
            G[y].push_back(x);
        }
        stack<int> st;
        int p = n;
        function<void(int)> DFS = [&](int u) {
            static int time = 0;
            dfn[u] = low[u] = time += 1;
            st.push(u);
            for (int v : G[u])
                if (not dfn[v]) {
                    DFS(v);
                    low[u] = min(low[u], low[v]);
                    if (low[v] >= dfn[u]) {
                        GT.emplace_back();
                        while (true) {
                            int w = st.top();
                            st.pop();
                            GT[w].push_back(p);
                            GT[p].push_back(w);
                            if (w == v) break;
                        }
                        GT[u].push_back(p);
                        GT[p].push_back(u);
                        p += 1;
                    }
                }
                else low[u] = min(low[u], dfn[v]);
        };
        for (int i = 0; i < n; i += 1) if (not dfn[i]) {
            DFS(i);
            st.pop();
        }
        vector<int> vis(p);
        id.resize(p);
        dep.resize(p);
        h = 0;
        while ((1 << h) < p) h += 1;
        f.resize(p, vector<int>(h, -1));
        function<void(int)> DFS2 = [&](int u) {
            vis[u] = 1;
            for (int i = 0; i + 1 < h and f[u][i] != -1; i += 1)
                f[u][i + 1] = f[f[u][i]][i];
            for (int v : GT[u]) if (v != f[u][0] and not vis[v]) {
                id[v] = id[u];
                f[v][0] = u;
                dep[v] = dep[u] + 1;
                DFS2(v);
            }
        };
        for (int i = 0; i < p; i += 1)
            if (not vis[i])
                DFS2(id[i] = i);
    }
    int dis(int x, int y) {
        int d = 0;
        if (dep[x] < dep[y]) swap(x, y);
        for (int i = h - 1; i >= 0; i -= 1)
            if (dep[x] - (1 << i) >= dep[y]) {
                x = f[x][i];
                d += 1 << i;
            }
        for (int i = h - 1; i >= 0; i -= 1)
            if (f[x][i] != f[y][i]) {
                x = f[x][i];
                y = f[y][i];
                d += 2 << i;
            }
        return d + (x != y ? 2 : 0);
    };
    bool get(int x, int y, int z) {
        if (id[x] != id[y]) return false;
        if (id[z] != id[x]) return true;
        return dis(x, z) + dis(y, z) != dis(x, y);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T; T -= 1) {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (auto& si : s) cin >> si;
        int bi = 0, bj = 0, pi = 0, pj = 0, tbi = 0, tbj = 0, tpi = 0, tpj = 0;
        vector<int> vx = {-1, 1, 0, 0}, vy = {0, 0, -1, 1};
        vector<int> wx = {n - 1, 0, (n - 1) / 2, (n - 1) / 2}, wy = {(m  - 1) / 2, (m - 1) / 2, m - 1, 0};
        for (int i = 0; i < n; i += 1)
            for (int j = 0; j < m; j += 1) {
                if (s[i][j] == 'b') bi = i, bj = j;
                if (s[i][j] == 'p') pi = i, pj = j;
                if (s[i][j] == '-') tbi = i, tbj = j;
                if (s[i][j] == '=') tpi = i, tpj = j;
            }
        auto checkin = [&](int x, int y) {
            return x >= 0 and x < n and y >= 0 and y < m;
        };
        auto check = [&](int x, int y) {
            return checkin(x, y) and s[x][y] != '#';
        };
        int b = bi * m + bj, p = pi * m + pj, tb = tbi * m + tbj, tp = tpi * m + tpj;
        vector<pair<int, int>> e;
        for (int i = 0; i < n; i += 1)
            for (int j = 0; j < m; j += 1)
                if (s[i][j] != '#')
                    for (int k = 0; k < 4; k += 2) {
                        int ni = i + vx[k], nj = j + vy[k];
                        if (check(ni, nj))
                            e.emplace_back(i * m + j, ni * m + nj);
                    }
        vector<Graph> graph(5);
        graph[4].init(n * m, e);
        for (int i = 0; i < m; i += 1) e.emplace_back(n * m, i);
        graph[0].init(n * m + 1, e);
        for (int i = 0; i < m; i += 1) e.pop_back();
        for (int i = 0; i < m; i += 1) e.emplace_back(n * m, (n - 1) * m + i);
        graph[1].init(n * m + 1, e);
        for (int i = 0; i < m; i += 1) e.pop_back();
        for (int i = 0; i < n; i += 1) e.emplace_back(n * m, i * m);
        graph[2].init(n * m + 1, e);
        for (int i = 0; i < n; i += 1) e.pop_back();
        for (int i = 0; i < n; i += 1) e.emplace_back(n * m, i * m + m - 1);
        graph[3].init(n * m + 1, e);
        for (int i = 0; i < n; i += 1) e.pop_back();
        
        vector<int> d(n * m * 4, -1), done(n * m * 4);
        deque<int> q;
        for (int i = 0; i < 4; i += 1) {
            int bvx = bi + vx[i], bvy = bj + vy[i];
            if (check(bvx, bvy)) {
                if (graph[4].get(p, bvx * m + bvy, b) or graph[i].get(p, n * m, b)) {
                    int s = b * 4 + i;
                    d[s] = 0;
                    q.push_front(s);
                }
            }
        }
        auto print = [&](int u, int v) {
            cout << u / 4 / m << " " << u / 4 % m << " " << u % 4 << " --> ";
            cout << v / 4 / m << " " << v / 4 % m << " " << v % 4 << "\n";
        };
        while (not q.empty()) {
            int u = q.front();
            q.pop_front();
            if (done[u]) continue;
            done[u] = 1;
            int b = u / 4, k = u % 4, bi = b / m, bj = b % m;
            int pi = bi + vx[k], pj = bj + vy[k], p = pi * m + pj;
            for (int i = 0; i < 4; i += 1) {
                int bvx = bi + vx[i], bvy = bj + vy[i];
                if (not check(bvx, bvy)) continue;
                if (graph[4].get(p, bvx * m + bvy, b) or graph[i].get(p, n * m, b)) {
                    int v = b * 4 + i;
                    if (d[v] == -1 or d[v] > d[u]) {
                        d[v] = d[u];
                        q.push_front(v);
                    }
                }
            }
            int ppi = bi + vx[k ^ 1], ppj = bj + vy[k ^ 1];
            if (checkin(ppi, ppj)) {
                if (check(ppi, ppj)) {
                    int v = (ppi * m + ppj) * 4 + k;
                    if (d[v] == -1 or d[v] > d[u] + 1) {
                        d[v] = d[u] + 1;
                        q.push_back(v);
                    }
                }
                else if(check(wx[k ^ 1], wy[k ^ 1])) {
                    for (int i = 0; i < 4; i += 1) {
                        int bvx = bi + vx[i], bvy = bj + vy[i];
                        if (not check(bvx, bvy)) continue;
                        int w = wx[k ^ 1] * m + wy[k ^ 1];
                        if (graph[4].get(w, bvx * m + bvy, b) or graph[i].get(w, n * m, b)) {
                            int v = b * 4 + i;
                            if (d[v] == -1 or d[v] > d[u]) {
                                d[v] = d[u];
                                q.push_front(v);
                            }
                        }
                    }
                }
            }
        }
        int ans = -1;
        for (int i = 0; i < 4; i += 1) if (d[tb * 4 + i] != -1) {
            int bvx = tbi + vx[i], bvy = tbj + vy[i];
            if (graph[4].get(tp, bvx * m + bvy, tb)) {
                if (ans == -1 or d[tb * 4 + i] < ans)
                    ans = d[tb * 4 + i];
            }
            int ppi = tbi + vx[i ^ 1], ppj = tbj + vy[i ^ 1];
            if (checkin(ppi, ppj) and not check(ppi, ppj) and check(wx[i ^ 1], wy[i ^ 1])) {
                int w = wx[i ^ 1] * m + wy[i ^ 1];
                if (graph[4].get(w, tp, tb)) {
                if (ans == -1 or d[tb * 4 + i] < ans)
                    ans = d[tb * 4 + i];
                }
            }
        }
        cout << ans << "\n";
    }
}
