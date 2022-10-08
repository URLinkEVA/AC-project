#include <iostream>
#include <cstring>
#include <algorithm>

#define all(x) (x).begin() , x.end() 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii; 
const int N = 1e6 + 10, M = 150 , mod = 998244353; 

int n , m , a[N] , b[N]; 
string s ; 

int solve(int tt) 
{
    ll sum = 0 ;
    cin >> n >> m ;
    vector<pii> v ; 
    for(int i = 1 ; i <= n ; i ++) 
    {
        cin >> a[i] >> b[i] ;
        sum += a[i] ; 
        v.push_back({a[i] - b[i] , i}); 
    }
    sort(all(v) , greater()) ;

    int j = 0 ; 
    while(j < n && sum > m)
    {
        sum -= v[j].first ; 
        j ++ ; 
    }

    if(sum > m) cout << -1 << endl ; 
    else cout << j << endl ; 

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
