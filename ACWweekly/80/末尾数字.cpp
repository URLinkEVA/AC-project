#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<char> hash({'a', 'e', 'i', 'o', 'u', 'y'});
    char last, c;
    while(cin >> c)
    {
        c = tolower(c);
        if(c >= 'a' && c <= 'z')
            last = c;
    }
    
    if(hash.count(last)) cout << "YES";
    else cout << "NO";
    return 0;
}
