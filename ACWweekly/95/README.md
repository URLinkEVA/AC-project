# AcWing 4873. 简单计算

# AcWing 4874. 约数
如果一个正整数的约数个数恰好为 3，则称该数为美丽数。

给定 n 个正整数 a1,a2,…,an，请你依次判断每个数是否是美丽数。

## 输入格式
第一行包含整数 n。

第二行包含 n 个整数 a1,a2,…,an。

## 输出格式
共 n 行，其中第 i 行输出对 ai 的判断，如果 ai 是美丽数，则输出 YES，否则输出 NO。

## 数据范围
前 6 个测试点满足 1≤n≤10。

所有测试点满足 1≤n≤105，1≤ai≤1012。

```
输入样例：
3
4 5 6
输出样例：
YES
NO
NO
```

# AcWing 4875. 整数游戏
Alice 和 Bob 在玩一个游戏。

首先，给定一个长度为 n 的正整数数列 a1,a2,…,an。

随后，两人轮流展开行动，由 Alice 先手行动。

当轮到一人采取行动时，如果 a1=0，则该玩家输掉游戏，否则该玩家需要：

在 [2,n] 范围内选择一个整数 i。

将 a1 的值减少 1。

交换 a1 和 ai 的值。

假设双方都采取最优策略，请你判断谁将获胜。

## 输入格式
第一行包含整数 T，表示共有 T 组测试数据。

每组数据第一行包含整数 n。

第二行包含 n 个整数 a1,a2,…,an。

## 输出格式
每组数据输出一行结果，如果 Alice 获胜，则输出 Alice，如果 Bob 获胜，则输出 Bob。

## 数据范围
前 3 个测试点满足 1≤T≤10，2≤n≤3。

所有测试点满足 1≤T≤2×104，2≤n≤105，1≤ai≤109，一个测试点的所有的 n 相加之和不超过 2×105。

```
输入样例：
3
2
1 1
2
2 1
3
5 4 4
输出样例：
Bob
Alice
Alice
```