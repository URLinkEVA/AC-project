#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    cout << (n / k + 1) * k;
    return 0;
}
