#include <bits/stdc++.h>
using namespace std;
using LL = long long;
struct Node{
    int v, p, size, mv;
    Node *L, *R, *par;
    Node(int v, int p, Node* L = nullptr, Node* R = nullptr) : v(v), p(p), size(1), mv(v), L(L), R(R), par(nullptr) {}
    Node* copy(Node* L, Node* R) {
        this->L = L;
        this->R = R;
        return this;
    }
};
namespace Treap {
    mt19937 rng;
    Node* update(Node* p) {
        p->size = 1;
        p->mv = p->v;
        if (p->L) p->size += p->L->size, p->mv = min(p->mv, p->L->mv), p->L->par = p;
        if (p->R) p->size += p->R->size, p->mv = min(p->mv, p->R->mv), p->R->par = p;
        p->par = nullptr;
        return p;
    }
    Node* merge(Node*L, Node* R) {
        if (not L) return R;
        if (not R) return L;
        if (L->p < R->p) return update(L->copy(L->L, merge(L->R, R)));
        return update(R->copy(merge(L, R->L), R->R));
    }
    pair<Node*, Node*> split_rank(Node* p, int r) {
        if (not p) return {};
        int Lsize = p->L ? p->L->size : 0;
        if (Lsize + 1 <= r) {
            auto [L, R] = split_rank(p->R, r - Lsize - 1);
            return {update(p->copy(p->L, L)), R};
        }
        auto [L, R] = split_rank(p->L, r);
        return {L, update(p->copy(R, p->R))};
    }
    Node* find_root(Node* p) {
        while (p->par)
            p = p->par;
        return p;
    }
    int rank(Node* p) {
        int res = 1;
        if (p->L) res += p->L->size;
        while (p->par) {
            if (p->par->R == p) {
                res += 1;
                if (p->par->L) res += p->par->L->size;
            }
            p = p->par;
        }
        return res;
    }
    Node* kth(Node* p, int k) {
        int Lsize = p->L ? p->L->size : 0;
        if (Lsize + 1 == k) return p;
        if (k <= Lsize) return kth(p->L, k);
        return kth(p->R, k - Lsize - 1);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    for (cin >> T; T; T -= 1) {
        int n, q;
        cin >> n >> q;
        map<int, int> a;
        map<int, Node*> p;
        map<int, set<int>> ms;
        for (int qi = 0; qi < q; qi += 1) {
            string op;
            LL x, y;
            cin >> op >> x >> y;
            if (op == "swap_a" and x != y) {
                if (not a.count(x)) a[x] = x;
                if (not a.count(y)) a[y] = y;
                swap(a[x], a[y]);
            }
            if (op == "swap_p" and x != y) {
                if (not p.count(x)) {
                    p[x] = new Node(x, Treap::rng());
                    ms[1].insert(x);
                }
                if (not p.count(y)) {
                    p[y] = new Node(y, Treap::rng());
                    ms[1].insert(y);
                }
                Node *rtx = Treap::find_root(p[x]), *rty = Treap::find_root(p[y]);
                auto rx = Treap::rank(p[x]);
                auto ry = Treap::rank(p[y]);
                if (rtx == rty) {
                    ms[rtx->size].erase(rtx->mv);
                    if (ms[rtx->size].empty())
                        ms.erase(rtx->size);
                    if (rx > ry) {
                        swap(rx, ry);
                        swap(x, y);
                    }
                    auto [L, R] = Treap::split_rank(rtx, rx);
                    auto [RL, RR] = Treap::split_rank(R, ry - rx);
                    auto rt = Treap::merge(L, RR);
                    ms[rt->size].insert(rt->mv);
                    ms[RL->size].insert(RL->mv);
                }
                else {
                    ms[rtx->size].erase(rtx->mv);
                    if (ms[rtx->size].empty())
                        ms.erase(rtx->size);
                    ms[rty->size].erase(rty->mv);
                    if (ms[rty->size].empty())
                        ms.erase(rty->size);
                    auto [Lx, Rx] = Treap::split_rank(rtx, rx);
                    auto [Ly, Ry] = Treap::split_rank(rty, ry);
                    auto rt = Treap::merge(Treap::merge(Lx, Ry), Treap::merge(Ly, Rx));
                    ms[rt->size].insert(rt->mv);
                }
            }
            if (op == "cmp") {
                int cmp = 0;
                int k = n + 1;
                for (auto& [c, s] : ms)
                    if ((y - x) % c)
                        k = min(k, *s.begin());
                if (k <= n) {
                    auto rt = Treap::find_root(p[k]);
                    int rk = Treap::rank(p[k]);
                    int rx = (rk - 1 + x - 1) % rt->size + 1;
                    int ry = (rk - 1 + y - 1) % rt->size + 1;
                    int px = Treap::kth(rt, rx)->v;
                    int py = Treap::kth(rt, ry)->v;
                    if (not a.count(px)) a[px] = px;
                    if (not a.count(py)) a[py] = py;
                    if (a[px] < a[py]) cmp = -1;
                    else cmp = 1;
                }
                if (cmp == 1) cout << ">\n";
                else if (cmp == -1) cout << "<\n";
                else cout << "=\n";
            }
        }
    }
}
