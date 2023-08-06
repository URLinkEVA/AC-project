#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e6;

int l[N], r[N], l_id[N], r_id[N];
int a[N], q[N], p;
int s, e;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
        cin >> l[i] >> r[i], l_id[l[i]] = i, r_id[r[i]] = i;
    int k = l_id[0];
    while (1)
    {
        if (!r[k] || p > n) break;
        int j = r[k];
        p += 2;
        q[j] = 1;
        a[p] = j;
        k = l_id[j];
    }//先处理偶数位的
    if (n % 2 == 0)
    {
        k = r_id[0];
        p = n - 1;
        while (1)
        {
            if (!l[k] || !p) break;
            int j = l[k];
            a[p] = j;
            k = r_id[j];
            p -= 2;
        }
    }//若n为偶数，那剩下的就很好处理，一个一个处理就完了
    else
    {
        for (int i = 1; i <= n; i ++ )
            if (!q[r[i]] && r[i] && l[i])
            {
                k = i;
                break;
            }//随便找一个处于奇数位的数
        while (1)
        {
            if (!l[r_id[l[k]]]) break;
            int j = l[k];
            k = r_id[j];
        }//找到最左边的奇数位
        p = 1;
        a[1] = l[k];
        while (1)
        {
            if (!r[k] || p > n) break;
            int j = r[k];
            p += 2;
            a[p] = j;
            k = l_id[j];
        }
    }
    for (int i = 1; i <= n; i ++ ) cout << a[i] << ' ';
    return 0;
}
