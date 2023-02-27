#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string ans;

bool dfs()
{
    char str[5];
    if(scanf("%s", str)==-1) return false;
    
    if(!strcmp(str, "pair"))
    {
        ans += str;
        ans += '<';
        if(!dfs()) return false;
        ans += ',';
        if(!dfs()) return false;
        ans += '>';
    }
    else ans += str;
    
    return true;
}

int main()
{
    scanf("%*d");
    if (dfs() && scanf("%*s") == -1) puts(ans.c_str());
    else puts("Error occurred");
    return 0;
}
