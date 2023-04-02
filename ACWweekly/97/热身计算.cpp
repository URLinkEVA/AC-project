#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << min(a,b) << " " << int((abs(a-b))/2) << endl;
    return 0;
}
