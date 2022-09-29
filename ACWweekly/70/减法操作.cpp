#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n;
int q[N];

bool check()
{

    for (int i = 0; i < n - 1; i ++ )
        if(q[i] % 2)
            q[i]--, q[i + 1]--;
    
    for (int i = 0; i < n; i ++ )
        if(q[i] < 0 || q[i] % 2)
            return false;
        
    return true;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
        cin >> q[i];
    
    if(check()) cout << "YES" << endl;
    else cout << "NO" << endl;
        
    return 0;
}
