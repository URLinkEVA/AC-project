#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_set<string> hash;
    while (n -- )
    {
        string g[2], str;
        cin >> g[0] >> g[1] >> str;

        int dx[] = {0, 0, 1, 1}, dy[] = {0, 1, 1, 0};
        string s[4];
        for (int i = 0; i < 4; i ++ )
            for (int j = 0; j < 4; j ++ )
            {
                int k = (i + j) % 4;
                s[i] += g[dx[k]][dy[k]];
            }

        sort(s, s + 4);
        hash.insert(s[0]);
    }

    cout << hash.size() << endl;
    return 0;
}
