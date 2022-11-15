#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string,int> hash; 
    for (int i = 0; i < n; i ++ )
    {
        string str;
        cin >> str;
        hash[str] ++;
        if(hash[str] * 2 > n)
        {
            cout << str << endl;
            break;
        }
    }
    return 0;
}
