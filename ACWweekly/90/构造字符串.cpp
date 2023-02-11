#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    string str;
    cin >> n >> k >> str;
    int pos = 0;
    for(int i = 0; i < n; i++)  // 找出前缀和后缀相同的最大长度 
        if(str.substr(0,i) == str.substr(n-i,i)) pos = i;
    cout << str;
    for(int i = 1; i < k; i++)
        cout << str.substr(pos);
    cout << endl;
    return 0;
}
