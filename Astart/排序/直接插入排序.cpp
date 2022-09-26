#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int q[N];

void insert_sort()
{
    for(int i = 0; i < n; i++)
    {
        int t = q[i], j = i;
        while(j && q[j - 1] > t)
        {
            q[j] = q[j - 1];
            j--;
        }
        q[j] = t;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) 
        cin >> q[i];
        
    insert_sort();
    
    for (int i = 0; i < n; i ++ ) 
        cout << q[i] << ' ';
    
    return 0;
}
// 时间效率不高
