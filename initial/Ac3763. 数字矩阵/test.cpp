#include <bits/stdc++.h>
using namespace std;

const int N=15;

void solve(){
    int n,m;
    cin>>n>>m;
    int cnt=0,sum=0;
    int mn=1e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int a;
            cin>>a;
            sum+=abs(a);
            if(a<0) cnt++;
            mn=min(abs(a),mn);
        }
    }
    sum-=mn*2*(cnt%2);
    cout<<sum<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
}
