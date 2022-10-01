#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool is_prime(int x)  // 判定质数
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}


int main()
{
    int n;
    cin >> n;
    if(is_prime(n)) puts("1");
    else if (n % 2 == 0 || is_prime(n - 2)) puts("2");
    else puts("3");
    
    return 0;
}
