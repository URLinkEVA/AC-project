#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int q[N];

void bubble_sort()
{
    for (int i = 0; i < n - 1; i ++ )
    {
        bool has_swap = false;
        for(int j = n - 1; j > i; j -- )
        {
            if(q[j] < q[j - 1]) 
            {
                swap(q[j], q[j - 1]);
                has_swap = true;
            }
        }
        if(!has_swap) break;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) 
        cin >> q[i];
        
    bubble_sort();
    
    for (int i = 0; i < n; i ++ ) 
        cout << q[i] << ' ';
    
    return 0;
}
