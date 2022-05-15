# 上车
有 n 辆客车，其中第 i 辆车的已载客数为 pi，最大载客数为 qi。

现在，来了两个人想要乘坐同一辆车前去旅行。

请问，一共有多少辆客车可供他们选择。

## 输入格式
第一行包含整数 n。

接下来 n 行，每行包含两个整数 pi,qi。

## 输出格式
一个整数，表示可供选择的客车数量。

## 数据范围
前三个测试点满足 1≤n≤3。

所有测试点满足 1≤n≤100，0≤pi≤qi≤100。

```
输入样例2：
3
1 10
0 10
10 10
输出样例2：
2
```

## 一份参考
```
// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

int n, c;

int main() {
    cin >> n;
    while (n--) {
        int p, q; cin >> p >> q;
        if (q - p >= 2) c++;
    }
    cout << c;
    return 0;
}
```

# 连通分量
给定一个 n×m 的方格矩阵，每个方格要么是空格（用 . 表示），要么是障碍物（用 * 表示）。

如果两个空格存在公共边，则两空格视为相邻。

我们称一个不可扩展的空格集合为连通分量，如果集合中的任意两个空格都能通过相邻空格的路径连接。

这其实是一个典型的众所周知的关于连通分量（Connected Component ）的定义。

现在，我们的问题如下：

对于每个包含障碍物的单元格 (x,y)，假设它是一个空格（所有其他单元格保持不变）的前提下，请你计算包含 (x,y) 的连通分量所包含的单元格数量。

注意，所有假设求解操作之间都是相互独立的，互不影响。

## 输入格式
第一行包含两个整数 n,m。

接下来 n 行，每行包含 m 个字符：. 表示空格，* 表示障碍物。

## 输出格式
输出一个 n 行 m 列的字符矩阵，其中第 i 行第 j 列的字符对应给定矩阵中第 i 行第 j 列的单元格。

如果该单元格为空格，则输出字符为 .，如果该单元格为障碍物，则输出字符为假设该单元格为空格的前提下，包含该单元格的连通分量所包含的单元格数量对 10 取模后的结果。

具体格式可参照输出样例。

## 数据范围
前 5 个测试点满足 1≤n,m≤10。

所有测试点满足 1≤n,m≤1000。

```
输入样例1：
3 3
*.*
.*.
*.*
输出样例1：
3.3
.5.
3.3
输入样例2：
4 5
**..*
..***
.*.*.
*.*.*
输出样例2：
46..3
..732
.6.4.
5.4.3
```

## dfs
```
int n;
int xa, ya, xb, yb;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
bool st[N][N];

bool dfs(int x, int y)
{
	if (g[x][y] == '#') return false;
	if (x == xb && y == yb) return true;
	
	st[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int a = x + dx[i], b = y + dy[i];
		if (a < 0 || a >= n || b < 0 || b >= n) continue;
		if (st[a][b]) continue;
		if (dfs(a, b)) return true;
	}
	return false;
}
```

