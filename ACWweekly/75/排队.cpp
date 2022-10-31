#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110;

struct Category
{
    int id, pr;
    string name;
    bool operator< (const Category& t) const
    {
        if(pr != t.pr) return pr < t.pr;
        else return id < t.id;
    }
    
}category[N];

int get_pr(string role)
{
    if(role == "rat") return 1;
    if(role == "woman" || role == "child") return 2;
    if(role == "man") return 3;
    if(role == "captain") return 4;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        string name, role;
        cin >> name >> role;
        category[i] = {i, get_pr(role), name};
    }
    sort(category + 1, category + n + 1);
    for (int i = 1; i <= n; i ++ ) cout << category[i].name << endl;
    return 0;
}
