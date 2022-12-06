#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string num;
string ans;

void dfs(string str, int u, int s4, int s7)
{
    if (u == num.size())
    {
        if (str >= num && (ans.empty() || ans > str))
            ans = str;
        return;
    }

    if (s4 < num.size() / 2) dfs(str + '4', u + 1, s4 + 1, s7);
    if (s7 < num.size() / 2) dfs(str + '7', u + 1, s4, s7 + 1);
}

int main()
{
    cin >> num;

    if (num.size() % 2) num = '0' + num;

    dfs("", 0, 0, 0);

    if (ans.empty())
    {
        num = "00" + num;
        dfs("", 0, 0, 0);
    }

    cout << ans << endl;

    return 0;
}
