#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int q[N];

void quick_sort(int l, int r)  // 快速排序
{
    if (l >= r) return;
    int i = l - 1, j = r + 1, x = q[(l + r) / 2];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(l, j);
    quick_sort(j + 1, r);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> q[i];

    quick_sort(0, n - 1);

    for (int i = 0; i < n; i ++ ) cout << q[i] << " ";
    cout << endl; 
    
    return 0;
}
