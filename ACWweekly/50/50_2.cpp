#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int INF = 1e9;

int main()
{
	int n, m;
	scanf("%d", &n);

	int a = INF, b = -INF;
	while (n--)
	{
		int l, r;
		scanf("%d%d",&l,&r);
		a = min(a, r);
		b = max(b, r);
	}
	scanf("%d", &m);
	
	int res = 0;
	while (m--)
	{
		int l, r;
		scanf("%d%d",&l,&r);
		if (b > a) res = max(res, b - r);
		if (a < l) res = max(res, l - a);
	}

	printf("%d\n", res);
	return 0;
}
