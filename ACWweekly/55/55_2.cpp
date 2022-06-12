//手写二分 O(nlogn)
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long LL;

const int N = 200010, INF = 2e9;

int c[N], a[N], b[N];
int n, m;
int ans[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n+m; i++) scanf("%d",&c[i]);
	for (int i = 0, j = 0, k = 0; i < n + m; i++)
	{
		int t;
		scanf("%d", &t);
		if (t) b[++j] = c[i];
		else a[++k] = c[i];
	}

	b[0] = -INF, b[m+1] = INF;

	for (int i = 1; i <= n; i++)
	{
		int l = 0, r = m + 1;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (b[mid] >= a[i]) r = mid;
			else l = mid + 1;
		}
		if ((LL)a[i] - b[r - 1] <= (LL)b[r] - a[i]) ans[r - 1]++;
		else ans[r]++;
	}

	for (int i = 1; i <= m; i++)
	{
		printf("%d ", ans[i]);
	}
	return 0;
}


//用库函数二分 O(nlogn)
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 200010, INF = 2e9;

int n, m;
int c[N], a[N], b[N];
int ans[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n + m; i ++ ) scanf("%d", &c[i]);
    for (int i = 0, j = 0, k = 0; i < n + m; i ++ )
    {
        int t;
        scanf("%d", &t);
        if (t) b[ ++ j] = c[i];
        else a[ ++ k] = c[i];
    }

    b[0] = -INF, b[m + 1] = INF;
    for (int i = 1; i <= n; i ++ )
    {
        int r = lower_bound(b, b + m + 2, a[i]) - b;
        if ((LL)a[i] - b[r - 1] <= (LL)b[r] - a[i]) ans[r - 1] ++ ;
        else ans[r] ++ ;
    }

    for (int i = 1; i <= m; i ++ )
        printf("%d ", ans[i]);

    return 0;
}



//双指针  O(n)
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 200010, INF = 2e9;

int n, m;
int c[N], a[N], b[N];
int ans[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n + m; i ++ ) scanf("%d", &c[i]);
    for (int i = 0, j = 0, k = 0; i < n + m; i ++ )
    {
        int t;
        scanf("%d", &t);
        if (t) b[ ++ j] = c[i];
        else a[ ++ k] = c[i];
    }

    b[0] = -INF, b[m + 1] = INF;
    for (int i = 1, j = 0; i <= n; i ++ )
    {
        while (b[j] < a[i]) j ++ ;
        int r = j;
        if ((LL)a[i] - b[r - 1] <= (LL)b[r] - a[i]) ans[r - 1] ++ ;
        else ans[r] ++ ;
    }

    for (int i = 1; i <= m; i ++ )
        printf("%d ", ans[i]);

    return 0;
}
