#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;
    string res;
    for(auto c: str)
    {
        if(res.size() && res.back() == c) res.pop_back();
        else res += c;
    }
    cout << res << endl;
    return 0;
}
