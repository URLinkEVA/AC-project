#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int q[N];

void quick_sort(int l, int r)
{
    if(l >= r) return;
    int i = l-1, j = r+1, x = q[(l + r)/2];
    while(i < j)
    {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(l, j);
    quick_sort(j+1, r);
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i ++ ) cin >> q[i];
    quick_sort(0, n - 1);
    cout << q[n - k];
    return 0;
}
