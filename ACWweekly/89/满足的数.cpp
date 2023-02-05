#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i ++ ){
        int a;
        cin >> a;
        s += a;
    }
    int res = 0;
    for (int i = 1; i <= 5; i ++ )
        if ((s + i) % (n + 1) != 1)
            res ++ ;
            
    cout << res;
    return 0;
}
