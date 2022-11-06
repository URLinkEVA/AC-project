#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010,M = 2 * N;

int n;
string s;
int p[N];
int h[N],e[M],ne[M],idx;

void add (int a,int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int find (int x) {
    if (p[x] != x) p[x] = find (p[x]);
    return p[x];
}

int dfs (int x) {
    int ans = 0;
    for (int i = h[x];~i;i = ne[i]) {
        int j = e[i];
        ans = max (ans,dfs (j) + 1);
    }
    return ans;
}

int main () {
    memset (h,-1,sizeof (h));
    cin >> n >> s;
    for (int i = 1;i <= n;i++) p[i] = i;
    for (int i = 0;i < s.size ();i++) {
        if (s[i] == '=') {
            int ra = find (i + 1),rb = find (i + 2);
            if (ra != rb) p[ra] = rb;
        }
    }
    for (int i = 0;i < s.size ();i++) {
        if (s[i] == '<') add (find (i + 2),find (i + 1));
        else if (s[i] == '>') add (find (i + 1),find (i + 2));
    }
    for (int i = 1;i <= n;i++) cout << dfs (find (i)) + 1 << ' ';
    return 0;
}
