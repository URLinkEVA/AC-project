#include <bits/stdc++.h>
using namespace std;
#define tm ((tl + tr) >> 1)
struct Node{
    Node *ls, *rs;
    int add, mn, sm[2];
    Node() {
        ls = rs = nullptr;
        add = mn = sm[0] = sm[1] = 0;
    }
};
struct Tree{
    int n;
    Node* root;
    Tree(int n) : n(n) {
        function<void(Node*&, int, int)> DFS = [&](Node*& v, int tl, int tr) {
            v = new Node();
            if (tl != tr) {
                DFS(v->ls, tl, tm);
                DFS(v->rs, tm + 1, tr);
            }
        };
        DFS(root, 0, n);
    }
    void output() {
        if (root->mn > 0) cout << "0 ";
        else {
            function<int(Node*, int, int)> DFS = [&](Node* v, int tl, int tr) {
                if (tl == tr) return tm;
                push_down(v);
                if (v->rs->mn == 0) return DFS(v->rs, tm + 1, tr);
                return DFS(v->ls, tl, tm);
            };
            int Last = DFS(root, 0, n);
            cout << query(0, Last, 0) << " ";
        }
        function<int(Node*, int, int)> DFS = [&](Node* v, int tl, int tr) {
            if (tl == tr) return tm;
            if (v->rs->sm[0]) return DFS(v->rs, tm + 1, tr);
            return DFS(v->ls, tl, tm);
        };
        int Last = 0;
        if (root->sm[0]) Last = DFS(root, 0, n);
        cout << query(Last, n, 1) << "\n";

    }
    void add(Node* v, int d) {
        v->add += d;
        v->mn += d;
    }
    void push_down(Node* v) {
        if (v->add) {
            add(v->ls, v->add);
            add(v->rs, v->add);
            v->add = 0;
        }
    }
    void add(int L, int R, int d) {
        function<void(Node*, int, int)> DFS = [&](Node* v, int tl, int tr) {
            if (tl >= L and tr <= R) add(v, d);
            else {
                push_down(v);
                if (L <= tm) DFS(v->ls, tl, tm);
                if (R > tm) DFS(v->rs, tm + 1, tr);
                v->mn = min(v->ls->mn, v->rs->mn);
            }
        };
        DFS(root, 0, n);
    }
    void update(int x, int d, int t) {
        function<void(Node*, int, int)> DFS = [&](Node* v, int tl, int tr) {
            v->sm[t] += d;
            if (tl < tr) {
                if (x <= tm) DFS(v->ls, tl, tm);
                if (x > tm) DFS(v->rs, tm + 1, tr);
            }
        };
        DFS(root, 0, n);
    }
    int query(int L, int R, int t) {
        function<int(Node*, int, int)> DFS = [&](Node* v, int tl, int tr) {
            if (tl >= L and tr <= R) return v->sm[t];
            int res = 0;
            if (L <= tm) res += DFS(v->ls, tl, tm);
            if (R > tm) res += DFS(v->rs, tm + 1, tr);
            return res;
        };
        return DFS(root, 0, n);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T; T -= 1) {
        int n, q;
        cin >> n >> q;
        Tree tree(q);
        map<int, int> mp;
        set<int> adds;
        tree.add(0, q, n);
        tree.update(0, n, 1);
        for (int i = 1; i <= q; i += 1) {
            string s;
            cin >> s;
            if (s == "add") {
                if (tree.root->sm[0] < n) {
                    adds.insert(i);
                    tree.add(i, q, -1);
                    tree.update(i, 1, 0);
                    tree.output();
                }
                else cout << "bug\n";
            }
            else {
                int ind, x;
                cin >> ind >> x;
                if (x == 0) {
                    if (not mp.count(ind)) mp[ind] = 0;
                    tree.add(mp[ind], q, -1);
                    tree.add(i, q, 1);
                    if (tree.root->mn < 0) {
                        cout << "bug\n";
                        tree.add(mp[ind], q, 1);
                        tree.add(i, q, -1);
                    }
                    else {
                        tree.update(mp[ind], -1, 1);
                        tree.update(i, 1, 1);
                        mp[ind] = i;
                        tree.output();
                    }
                }
                else {
                    if (not mp.count(ind)) mp[ind] = 0;
                    auto it = adds.lower_bound(mp[ind]);
                    if (it == adds.end())
                        cout << "bug\n";
                    else {
                        int x = *it;
                        adds.erase(x);
                        tree.add(x, q, 1);
                        tree.add(mp[ind], q, -1);
                        tree.add(i, q, 1);
                        tree.update(x, -1, 0);
                        tree.update(mp[ind], -1, 1);
                        tree.update(i, 1, 1);
                        mp[ind] = i;
                        tree.output();
                    }
                }
            }
        }
    }
}
