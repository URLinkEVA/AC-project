#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int q[N][N];

int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ )
            cin >> q[i][j];
            
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= m; j ++ )
            q[i][j] += q[i-1][j] + q[i][j-1] - q[i-1][j-1];
    
    while(t--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << q[x2][y2] - q[x1-1][y2] - q[x2][y1-1] + q[x1-1][y1-1] << endl;
    }
    
    return 0;
}
