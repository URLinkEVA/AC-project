# AcWing 4978. 解方程
给定三个正整数 a,b,c。

请你判断，能否找到两个非负整数 x,y，使得 a×x+b×y=c 成立。

## 输入格式
第一行包含整数 T，表示共有 T 组测试数据。

每组数据占一行，包含三个正整数 a,b,c。

## 输出格式
每组数据输出一行结果，如果可以找到两个非负整数 x,y，使得 a×x+b×y=c 成立，则输出 Yes，否则输出 No。

## 数据范围
所有测试点满足 1≤T≤5，1≤a,b≤100，1≤c≤1000。

```
输入样例：
3
4 6 15
3 2 7
6 11 6
输出样例：
No
Yes
Yes
```

# AcWing 4979. 合适的环
给定一个 n 个点 m 条边的无向图。

图中不含重边和自环。

请你在图中选出一个由三个点组成的环。

设图中一共有 x 条边满足：不在选择的环内，且与选择的环内某个点相连。

我们希望通过合理选环，使得 x 的值尽可能小。

请你输出 x 的最小可能值。

## 输入格式
第一行包含两个整数 n,m。

接下来 m 行，每行包含两个整数 a,b，表示点 a 和点 b 之间存在一条无向边。

## 输出格式
如果存在满足条件的环，则输出 x 的最小可能值。

否则，输出 -1。

## 数据范围
前 3 个测试点满足 3≤n≤10，0≤m≤10。

所有测试点满足 3≤n≤4000，0≤m≤4000，1≤a,b≤n，a≠b。

```
输入样例1：
5 6
1 2
1 3
2 3
2 4
3 4
4 5
输出样例1：
2
样例1解释
给定图中，由三个点组成的环一共有两个，分别为点 1,2,3 组成的环以及点 2,3,4 组成的环。

对于点 1,2,3 组成的环，我们逐个分析每条边是否满足：不在环内，且与环内的某个点相连。

边 (1,2) 在环内。
边 (1,3) 在环内。
边 (2,3) 在环内。
边 (2,4) 不在环内，且与点 2 相连。
边 (3,4) 不在环内，且与点 3 相连。
边 (4,5) 不在环内，但是与点 1,2,3 均不相连。

因此，如果选择点 1,2,3 组成的环，则 x 的值为 2。

对于点 2,3,4 组成的环，我们逐个分析每条边是否满足：不在环内，且与环内的某个点相连。

边 (1,2) 不在环内，且与点 2 相连。
边 (1,3) 不在环内，且与点 3 相连。
边 (2,3) 在环内。
边 (2,4) 在环内。
边 (3,4) 在环内。
边 (4,5) 不在环内，且与点 4 相连。

因此，如果选择点 2,3,4 组成的环，则 x 的值为 3。

综上，x 的最小可能值为 2。

输入样例2：
7 4
2 1
3 6
5 1
1 7
输出样例2：
-1
```

# AcWing 4980. 猜数字
小红和小明正在玩一个猜数字游戏。

由小红指定一个正整数 x，小明并不知道 x 的具体值，只知道 x 的取值范围是 [1,n]。

为了猜出 x 的具体值，小明可以向小红问这样的问题：“x 是否可以被整数 y 整除？”。

小明可以询问的次数不限（也可以不进行任何询问），但是询问次数越少越好。

对于小明的每次询问，小红需要如实回答小明是或否。

在小明进行完所有询问后，他需要根据小红的所有回答，确定 x 的具体值。

为了做到万无一失，小明希望无论 x 取什么值，在进行完所有询问后，都能根据小红的回答将其唯一确定。

请计算小明所需要的最少询问次数，并给出一种具体询问方案。

例如，当 n=4 时，最少需要进行 3 次询问，一种可能方案是 3 次询问的 y 值依次为 2,4,3，下面进行分析：

如果 x=1，则小红的回答依次为：否、否、否。

如果 x=2，则小红的回答依次为：是、否、否。

如果 x=3，则小红的回答依次为：否、否、是。

如果 x=4，则小红的回答依次为：是、是、否。

可以发现，x 取不同值时，小红的回答各不相同，所以小明可以根据小红的回答来唯一确定 x 的值。

当询问次数小于 3 时，无法保证小明能够根据小红的回答来唯一确定 x 的值。

例如，对于我们之前给出的可能方案，如果不进行第 3 次询问，那么：

如果 x=1，则小红的回答依次为：否、否。

如果 x=2，则小红的回答依次为：是、否。

如果 x=3，则小红的回答依次为：否、否。

如果 x=4，则小红的回答依次为：是、是。

可以发现，当 x 的取值为 1 或 3 时，小红的回答均为：否、否，小明无法根据小红的回答来唯一确定 x 的值。

## 输入格式
一个整数 n。

## 输出格式
第一行输出一个整数 k，表示所需要的最少询问次数。

第二行输出 k 个数，表示每次询问的 y 值。

注意，当 k=0 时，第二行必须输出空行，否则会判为错误。

如果方案不唯一，输出任意合理方案均可。

## 数据范围
前 3 个测试点满足 1≤n≤10。

所有测试点满足 1≤n≤1000。

```
输入样例1：
4
输出样例1：
3
2 4 3
输入样例2：
6
输出样例2：
4
2 4 3 5
```
