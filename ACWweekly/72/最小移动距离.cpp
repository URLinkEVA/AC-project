#include <bits/stdc++.h>

#define all(x) (x).begin() , x.end() 
// #define f first 
// #define s second 
using namespace std; 
typedef long long ll; 
typedef pair<int, int> pii; 
const int N = 1e6 + 10, M = 150 , mod = 998244353; 

int n , m , ne[N] , d[N] , st[N]; 
string s ; 

int solve(int tt) 
{
    cin >> n ; 
    for(int i = 1 ; i <= n ; i ++) cin >> ne[i] , d[ne[i]] ++ ; 

    queue<int> q ; 
    for(int i = 1 ; i <= n ; i ++)
        if(d[i] == 0)
        {
            cout << -1 << endl ;
            return 0 ; 
        }

    int ans = 2e9 ; 
    for(int i = 1 ; i <= n ; i ++)
        if(!st[i])
        {
            st[i] = 1 ; 
            int cnt = 1 , j = i;
            while(!st[ne[j]]) j = ne[j] , st[j] = 1 , cnt ++ ; 
            if(cnt%2 == 0) cnt /= 2 ; 

            if(ans == 2e9) ans = cnt ; 
            ans = ans * cnt /__gcd(ans , cnt) ; 
        }

    if(ans == 2e9) cout << -1 << endl ; 
    else cout << ans << endl ; 


    return 0 ; 
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt = 1;  //cin >> tt; 
    for(int i = 1 ; i <= tt ; i ++ )
    {
        solve(i) ;
        // cout << (solve()? "YES\n" : "NO\n" ) ; 
    }
    return 0;
}
