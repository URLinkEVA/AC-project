#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string s[3];
string d[6];

string filter(string str)
{
    string res;
    for (auto c: str)
        if (isalpha(c))
            res += tolower(c);
    return res;
}

int main()
{
    for (int i = 0; i < 3; i ++ )
    {
        cin >> s[i];
        s[i] = filter(s[i]);
    }

    sort(s, s + 3);
    for (int i = 0; i < 6; i ++ )
    {
        d[i] = s[0] + s[1] + s[2];
        next_permutation(s, s + 3);
    }

    int n;
    cin >> n;

    while (n -- )
    {
        string q;
        cin >> q;
        q = filter(q);

        bool is_match = false;
        for (int i = 0; i < 6; i ++ )
            if (q == d[i])
            {
                is_match = true;
                break;
            }

        if (is_match) cout << "ACC" << endl;
        else cout << "WA" << endl;
    }

    return 0;
}
