# 排序
## AcWing 785. 快速排序
```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int q[N], sz, w[N];

void insert_sort()  // 直接插入排序
{
    for (int i = 1; i < n; i ++ )
    {
        int t = q[i], j = i;
        while (j && q[j - 1] > t)
        {
            q[j] = q[j - 1];
            j -- ;
        }
        q[j] = t;
    }
}

void binary_search_insert_sort()  // 折半插入排序
{
    for (int i = 1; i < n; i ++ )
    {
        if (q[i - 1] <= q[i]) continue;
        int t = q[i];
        int l = 0, r = i - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] > t) r = mid;
            else l = mid + 1;
        }
        for (int j = i - 1; j >= r; j -- )
            q[j + 1] = q[j];
        q[r] = t;
    }
}

void bubble_sort()  // 冒泡排序
{
    for (int i = 0; i < n - 1; i ++ )
    {
        bool has_swap = false;
        for (int j = n - 1; j > i; j -- )
            if (q[j] < q[j - 1])
            {
                swap(q[j], q[j - 1]);
                has_swap = true;
            }
        if (!has_swap) break;
    }
}

void select_sort()  // 简单选择排序
{
    for (int i = 0; i < n - 1; i ++ )
    {
        int k = i;
        for (int j = i + 1; j < n; j ++ )
            if (q[j] < q[k])
                k = j;
        swap(q[i], q[k]);
    }
}

void shell_sort()  // 希尔排序
{
    for (int d = n / 3; d; d = d == 2 ? 1 : d / 3)
    {
        for (int start = 0; start < d; start ++ )
        {
            for (int i = start + d; i < n; i += d)
            {
                int t = q[i], j = i;
                while (j > start && q[j - d] > t)
                {
                    q[j] = q[j - d];
                    j -= d;
                }
                q[j] = t;
            }
        }
    }
}

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

void down(int u)
{
    int t = u;
    if (u * 2 <= sz && q[u * 2] > q[t]) t = u * 2;
    if (u * 2 + 1 <= sz && q[u * 2 + 1] > q[t]) t = u * 2 + 1;

    if (u != t)
    {
        swap(q[u], q[t]);
        down(t);
    }
}

void heap_sort()  // 堆排序，下标一定要从1开始
{
    sz = n;
    for (int i = n / 2; i; i -- ) down(i);

    for (int i = 0; i < n - 1; i ++ )
    {
        swap(q[1], q[sz]);
        sz -- ;
        down(1);
    }
}

void merge_sort(int l, int r)
{
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(l, mid), merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) w[k ++ ] = q[i ++ ];
        else w[k ++ ] = q[j ++ ];
    while (i <= mid) w[k ++ ] = q[i ++ ];
    while (j <= r) w[k ++ ] = q[j ++ ];
    for (i = l, j = 0; j < k; i ++, j ++ ) q[i] = w[j];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

    // insert_sort();
    // binary_search_insert_sort();
    // bubble_sort();
    // select_sort();
    // shell_sort();
    // quick_sort(0, n - 1);
    // heap_sort();
    merge_sort(0, n - 1);


    for (int i = 0; i < n; i ++ ) printf("%d ", q[i]);
    return 0;
}

```
