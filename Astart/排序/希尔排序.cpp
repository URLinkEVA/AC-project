#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int q[N];

void shell_sort()
{
    for(int d = n/2; d; d/=2)
    {
        for(int start = 0; start < d; start++)
        {
            for(int i = start + d; i < n; i+=d)
            {
                int t = q[i], j = i;
                while(j > start && q[j - d] > t)
                {
                    q[j] = q[j - d];
                    j -= d;
                }
                q[j] = t;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) 
        cin >> q[i];
        
    shell_sort();
    
    for (int i = 0; i < n; i ++ ) 
        cout << q[i] << ' ';
    
    return 0;
}
