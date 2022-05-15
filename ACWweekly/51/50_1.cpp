#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int res = 0;
	while (n--)
	{
		int p, q;
		cin >> p >> q;
		if (q - p >= 2) res++;
	}
	cout << res << endl;
	return 0;
}
