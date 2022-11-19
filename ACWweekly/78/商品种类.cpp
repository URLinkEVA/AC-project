#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_set<string> st;
    for (int i = 0; i < n; i ++ )
    {
        string name, place;
        cin >> name >> place;
        while(name.size() < 10) name = name + ' ';
        while(place.size() < 10) place = place + ' ';
        st.insert(name + place);
    }
    cout << st.size() << endl;
    return 0;
}
