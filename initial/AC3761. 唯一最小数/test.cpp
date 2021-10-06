#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 2e5 + 10;

int n,t;
int a[N],b[N];
int st[N];

int main()
{
    cin >> t;

     while (t -- )
   {
       cin >> n;
       int m = N;   //初始化m
       memset(st,-1,sizeof st); //初始化st[N]
       for (int i = 0; i < n; i ++ ) 
       {
           cin >> a[i];
           st[a[i]] ++ ;
           b[a[i]] = i + 1;
       }
       for (int i = 0; i < n; i ++ )
       {
           if (st[a[i]] == 0) 
           {
               m = min(m,a[i]);
           }
       }

       if (m == N) cout << -1 << endl;
       else cout << b[m]  << endl;
   }
}
