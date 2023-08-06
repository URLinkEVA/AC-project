#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int val = 0;
    vector<int> vec(n);
    for (int i = 0; i < n; i ++ )
    {
        cin >> vec[i];
        val = val == 0 ? vec[i] : min(val, vec[i]);
    }
    cout << ((val ^ vec[2]) + 2) << endl;
    return 0;
}
