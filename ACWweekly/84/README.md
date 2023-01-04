# AcWing 4788. 最大数量

# AcWing 4789. 前缀和序列

# AcWing 4790. 买可乐
某商店目前库存可乐数量为 k 瓶。

可乐的进货价格如下：

- 整箱：c 元/箱。每箱有 n 瓶。
- 单瓶：d 元/瓶。

请问，为了使得库存可乐数量不低于 n×m 瓶，该商店至少需要花费多少元钱来购进可乐。

显然，当 k≥n×m 时，无需购进可乐。

## 输入格式
第一行包含两个整数 c,d。

第二行包含两个整数 n,m。

第三行包含整数 k。

## 输出格式
一个整数，表示最少花费的金额。

## 数据范围
前 4 个测试点满足 1≤c,d,n,m,k≤10。

所有测试点满足 1≤c,d,n,m,k≤100。

```
输入样例1：
1 10
7 2
1
输出样例1：
2
输入样例2：
2 2
2 1
2
输出样例2：
0
```

### o(n)暴力
```
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int c, d, n, m, k;
    cin >> c >> d;
    cin >> n >> m;
    cin >> k;

    if (k >= n * m) puts("0");
    else
    {
        int res = 1e8;
        for (int i = 0; i <= m; i ++ )
        {
            int t = c * i;
            if (k + n * i < n * m)
                t += (n * m - n * i - k) * d;
            res = min(res, t);
        }
        cout << res << endl;
    }

    return 0;
}
```

### o(1)贪心
```
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int c, d, n, m, k;
    cin >> c >> d >> n >> m >> k;
    int cnt = n * m - k;
    if (cnt <= 0) puts("0");
    else
        cout << min({cnt * d, cnt / n * c + cnt % n * d, (cnt + n - 1) / n * c}) << endl;

    return 0;
}
```
