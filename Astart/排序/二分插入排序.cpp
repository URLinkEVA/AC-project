#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int q[N];

void binary_search_insert_sort()
{
    for (int i = 1; i < n; i ++ )
    {
        if(q[i - 1] <= q[i]) continue;
        int t = q[i];
        int l = 0, r = i - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(q[mid] > t) r = mid;
            else l = mid + 1;
        }
        for (int j = i - 1; j >= r; j -- )
            q[j + 1] = q[j];
        q[r] = t;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) 
        cin >> q[i];
        
    binary_search_insert_sort();
    
    for (int i = 0; i < n; i ++ ) 
        cout << q[i] << ' ';
    
    return 0;
}
// 优化效果不明显
