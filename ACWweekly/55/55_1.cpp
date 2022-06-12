#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 11;

int n, m;
int a[N];
bool st[N];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) 
	{
		int x;
		cin >> x;
		st[x] = true;
	}
	for (int i = 0; i < n; i++)
	{
		if (st[a[i]])
		{
			cout << a[i] << ' ';
		}
	}
	return 0;
}
