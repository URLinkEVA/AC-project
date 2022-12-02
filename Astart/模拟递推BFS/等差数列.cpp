// 存在2个非0,已知信息>= 2,此行(列)可恢复:知道a,d，每次恢复完需要重新判断是否>=两个不为0
// 动态迭代,满足此条件加入集合
#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = N * 2;

int n, m;
int row[N], col[N]; // 表示每行(列)有多少个非0元素
int q[M], hh, tt = -1;
bool st[M]; // 行:[0,n-1]，列:[n,n+m-1]
PII ans[N * N];
int top;
int g[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
        {
            scanf("%d", &g[i][j]);
            if (g[i][j]) // 对应行列,元素数量++
            {
                row[i] ++ ;
                col[j] ++ ;
            }
        }

    for (int i = 0; i < n; i ++ )
        if (row[i] >= 2 && row[i] < m) // 如果已经等于m，说明已经全部填满了，不用填了 
        {
            q[ ++ tt] = i;
            st[i] = true;
        }
    for (int i = 0; i < m; i ++ )
        if (col[i] >= 2 && col[i] < n)
        {
            q[ ++ tt] = i + n;
            st[i + n] = true;
        }

    while (hh <= tt)
    {
        auto t = q[hh ++ ];
        if (t < n)  // 行
        {
            PII p[2];
            int cnt = 0;
            for (int i = 0; i < m; i ++ )
                if (g[t][i]) // 行存在信息，若非0位数>=2，执行bfs
                {
                    p[cnt ++ ] = {i, g[t][i]}; // 存入t行i列 ，值g[t][i]
                    if (cnt == 2) break;
                }
            int d = (p[1].y - p[0].y) / (p[1].x - p[0].x); // 求公差
            int a = p[1].y - d * p[1].x; // 求首项

            for (int i = 0; i < m; i ++ )
                if (!g[t][i])
                {
                    g[t][i] = a + d * i;
                    ans[top ++ ] = {t, i};
                    col[i] ++ ; // 动态更新列的非0信息个数
                    if (col[i] >= 2 && col[i] < m && !st[i + n])
                    // 若有新的列已知信息非0位 >= 2 ，更新标记，加入答案队列
                    {
                        q[ ++ tt] = i + n; 
                        st[i + n] = true;
                    }
                }
        }
        else  // 列
        {
            t -= n; // 列：st中[n,n+m-1] 对应col中[0,m-1]
            PII p[2];
            int cnt = 0;
            for (int i = 0; i < n; i ++ ) //从行转列代码 ：换n、row、g[i][t]  第i列t行
                if (g[i][t])
                {
                    p[cnt ++ ] = {i, g[i][t]};
                    if (cnt == 2) break;
                }
            int d = (p[1].y - p[0].y) / (p[1].x - p[0].x);
            int a = p[1].y - d * p[1].x;
            for (int i = 0; i < n; i ++ )
                if (!g[i][t])
                {
                    g[i][t] = a + d * i;
                    ans[top ++ ] = {i, t};
                    row[i] ++ ;
                    if (row[i] >= 2 && row[i] < n && !st[i])
                    {
                        q[ ++ tt] = i;
                        st[i] = true;
                    }
                }
        }
    }

    sort(ans, ans + top); // pair默认按first排序
    for (int i = 0; i < top; i ++ )
    {
        auto& p = ans[i]; //；类似指针取地址，输出答案二元组 {x,y} 
        // 从0开始，答案输出:偏移p.x+1,p.y+1
        printf("%d %d %d\n", p.x + 1, p.y + 1, g[p.x][p.y]); // 对应值已经修改
    }

    return 0;
}
