#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
int w[N];

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i ++ ) cin >> w[i];
    while(q--)
    {
        int k;
        cin >> k;
        int l = 0, r = n-1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(w[mid] >= k) r = mid;
            else l = mid + 1;
        }
        if (w[l] != k) cout << "-1 -1" << endl;
        else
        {
            cout << l << ' ';

            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (w[mid] <= k) l = mid;
                else r = mid - 1;
            }
            cout << l << endl;
        }
    }
    return 0;
}
