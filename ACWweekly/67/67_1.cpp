#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t -- )
    {
        int n;
        cin >> n;
        if(n%2) cout << '7' + string(n/2 - 1, '1') << endl;
        else cout << string(n/2, '1') << endl;
    }
    return 0;
}
