#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;
int n;
int path[N];
bool st[N];

void dfs(int u)
{
    if(u == n)
    {
        for (int i = 0; i < n; i ++ ) cout << path[i] << ' ';
        puts(""); // 每个方案后输出一个空行
        return; 
    }

    else
    {
        for (int i = 1; i <= n; i ++ )
            if(!st[i])
            {
                path[u] = i;
                st[i] = true;
                dfs(u + 1);
                st[i] = false;
            }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}
