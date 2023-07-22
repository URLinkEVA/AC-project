#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    char q[3];
    char c = 'a';
    for (int i = 0; i < 3; i ++, c ++) q[i] = c;
    int T;
    cin >> T;
    while (T -- )
    {
        int n;
        cin >> n;
        if(n <= 3) for(int i = 0; i < n; i++) cout << q[i];
        else
        {
            int u = n / 3, v = n % 3;
            for (int i = 0; i < u; i ++ ) cout << "abc";
            for (int i = 0; i < v; i ++ ) cout << q[i];
        }
        cout << endl;
    }
    return 0;
}
