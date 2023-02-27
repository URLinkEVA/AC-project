#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        int t;
        cin >> t;
        if(t%4==0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
