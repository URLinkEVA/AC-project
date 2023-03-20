#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long LL;
const int N = 1000010;
int primes[N], cnt;
bool st[N];

void get_primes(int n){
    st[1] = true;
    for(int i = 2; i<=n; i++)
    {
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; j++)
        {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main()
{
    get_primes(N-1);
    int n;
    cin >> n;
    while (n -- ){
        LL a;
        cin >> a;
        LL r = sqrt(a);
        if(r * r == a && !st[r]) puts("YES");
        else puts("NO");
    }
    return 0;
}
