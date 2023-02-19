#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int n, m;
vector<int> g[N];
bool st[N];
bool check(int mid) {
    //这一层是对每一行进行初始化
    for (int i = 0; i < m; i ++ ) st[i] = false;//st代表每一行里面是不是至少有一个数据符合条件

    bool same = false;//一行中是否有两个或者是两个以上的数据符合条件
    for (int i = 0; i < n; i ++ ) {//这一层循环是对列循环
        bool success = false;//是否一列中是否有满足条件的
        for (int j = 0; j < m; j ++ )//对列循环
            if (g[j][i] >= mid) {//有一个数满足条件
                success = true;//见上面的解释
                if (st[j]) same = true;//如果一行中之前已经有一个满足条件的数，再加上这个，就有两个，那么这个mid可以
                st[j] = true;//这一行中存在满足的数
            }
        if (!success) return false;//有一列完全寄了，所以直接返回false吧，没寄的话继续循环
    }

    return same;//每一列中都有数满足条件，并且，有一行中有两个及以上的数满足条件，返回true（same的作用）
}
int main() {
    int T;
    scanf("%d", &T);

    while (T -- ) {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; i ++ ) {
            g[i].resize(n);//高级东西，是我不知道的
            for (int j = 0; j < n; j ++ )
                scanf("%d", &g[i][j]);//初始化啦啦啦
        }
        int l = 1, r = 1e9;
        while (l < r) {//二分啦
            int mid = l + r + 1 >> 1;
            if (check(mid)) l = mid;//大于等于mid的数都满足条件
            else r = mid - 1;//想一想
        }

        printf("%d\n", r);
    }

    return 0;
}
