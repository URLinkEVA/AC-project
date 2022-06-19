#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 200010;

int n, k;
int cnt[N];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &cnt[i]);
	}
	sort(cnt, cnt + n);
	int res = n;
	for (int i = 0,j = 0; i < n; i++)
	{
		while (j < n&&cnt[j] - cnt[i] <= k)
		{
			j++;
		}
		if (cnt[j - 1] > cnt[i])
		{
			res--;
		}
	}
	printf("%d\n", res);
	return 0;
}
