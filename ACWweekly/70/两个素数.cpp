#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int is_prime(int n)
{
    for (int i = 2; i <= n / 2; i ++ )
    {
        if(n % i == 0) return 0;
    }
    return 1; // 返回代表for循环里判断数为素数
}

int main()
{
    int x;
    cin >> x;
    for (int i = 2; i <= x / 2; i ++ )
    {
        for (int j = 2; j <= x / 2; j ++ )
        {
            if(is_prime(i) && is_prime(j) && i * j == x && i <= j) cout << i << ' ' << j << endl;
        }
    }
    return 0;
}


// 更快的写法

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int x;
    cin >> x;
    for (int i = 2; i < x; i ++ )
    {
        if(x % i == 0)
        {
            cout << i << ' ' << x/i << endl;
            break;
        }
    }
    return 0;
}
