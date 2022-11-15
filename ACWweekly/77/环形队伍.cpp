#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string hat = "ROYGBIV";
    int n;
    cin >> n;
    string res;
    for (int i = 0; i < n - 3; i ++ ) 
        res += hat[i % 4];
        
    for (int i = 0; i < min(n, 3); i ++ ) 
        res += hat[i + 4];
    
    cout << res << endl;
    return 0;
}
