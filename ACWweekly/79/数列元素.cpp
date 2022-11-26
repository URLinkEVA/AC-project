#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;
int q[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        int a = (i+1)*(i+2)/2;
        q[i] = a;
    }
    bool find = false;
    for(int i = 0; i < N; i ++ )
    {
        if(n == q[i])
        {
            find = true;
            break;
        }
    }
    if (find) cout << "YES";
    else cout << "NO";
    return 0;
}
