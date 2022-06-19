#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 110;

int n;
int cnt[N];

int main()
{
	cin >> n;
	int res = 0;
	while (n--)
	{
		int x;
		cin >> x;
		cnt[x]++;
		res = max(res,cnt[x]);
	}
	cout << res << endl;
	return 0;
}
