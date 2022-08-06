#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 500010;

int n, m;
int w[N];

int main()
{
    scanf("%d", &m);

    double res = 0, sum = 0;
    int k = 0;
    while (m -- )
    {
        int op, x;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &x);
            w[ ++ n] = x;
            while (k + 1 <= n && w[k + 1] <= (sum + w[n]) / (k + 1))
                sum += w[ ++ k];
            res = max(res, w[n] - (sum + w[n]) / (k + 1));
        }
        else
        {
            printf("%lf\n", res);
        }
    }

    return 0;
}
