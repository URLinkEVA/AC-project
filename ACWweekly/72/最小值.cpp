#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        cout << min(min(a,b),(a+b)/3) << endl;
    }
    return 0;
}
