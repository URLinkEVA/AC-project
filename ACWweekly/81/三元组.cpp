#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int s = 0;
    while (n -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a + b + c >= 2) s++;
    }
    cout << s << endl;
    return 0;
}
