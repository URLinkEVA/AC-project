#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    string str;
    cin >> str;
    set<char> hash(str.begin(), str.end());
    if(hash.size()%2) cout << "odd" << endl;
    else cout << "even" << endl;
    return 0;
}
