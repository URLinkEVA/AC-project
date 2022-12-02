#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;
int n;
bool col[N], dg[N], udg[N];
int path[N];

bool dfs(int u)
{
    if(u == 8)
    {
        if(--n == 0)
        {
            for (int i = 0; i < 8; i ++ ) 
                cout << path[i];
            cout << endl;
            return true;
        }
        return false;
    }
    
    for(int i = 0; i < 8; i++)
        if(!col[i] && !dg[u+i] && !udg[u-i+8])
        {
            col[i] = dg[u+i] = udg[u-i+8] = true;
            path[u] = i + 1;
            if(dfs(u+1)) return true;
            col[i] = dg[u+i] = udg[u-i+8] = false;
        }
    return false;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        memset(col, 0, sizeof col);
        memset(dg, 0, sizeof dg);
        memset(udg, 0, sizeof udg);
        dfs(0);
    }
    return 0;
}
