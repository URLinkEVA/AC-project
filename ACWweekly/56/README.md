# 分组
给定一个长度为 n 的数组 a1,a2,…,an。

请你将这 n 个元素重新分组，要求每个组内的元素两两不等，且分组数量应尽可能少。

请你计算最少所需的分组数量。

例如，给定一个数组 a=[1,2,4,3,3,2]，我们至少需要将所有元素分为两组，一种可行分组方案为：[1,2,3] 和 [2,3,4]。

## 输入格式
第一行包含一个整数 n。

第二行包含 n 个整数 a1,a2,…,an。

## 输出格式
一个整数，表示最少所需的分组数量。

## 数据范围
前三个测试点满足 1≤n≤10。

所有测试点满足 1≤n≤100，1≤ai≤100。
```
输入样例1：
6
1 2 4 3 3 2
输出样例1：
2
输入样例2：
1
100
输出样例2：
1
```

# 格斗场
一个格斗场内有 n 个战士，其中第 i 个战士的战斗力为 ai。

作为格斗场内的经理人，你需要给战士们安排一对一的决斗。

这些决斗是一场接一场进行的，一场结束后才会安排下一场。

为了保证决斗的观赏性，在安排时需保证：
- 决斗双方的战斗力不能相同。
- 决斗双方的战斗力差距不能超过 K。

已知，在决斗中战斗力高的选手一定可以将战斗力低的选手击败，并且失败的选手会被赶出格斗场。

请你合理安排决斗，使得当剩余选手之间无法再安排任何决斗时，剩余选手的数量越少越好。

请你输出剩余选手的最小可能数量。

## 输入格式
第一行包含两个整数 n,K。

第二行包含 n 个整数 a1,a2,…,an。

## 输出格式
一个整数，表示剩余选手的最小可能数量。

## 数据范围
前四个测试点满足 1≤n≤10。

所有测试点满足 1≤n≤2×105，1≤K≤106，1≤ai≤106。

```
输入样例1：
7 1
101 53 42 102 101 55 54
输出样例1：
3
输入样例2：
6 5
20 15 10 15 20 25
输出样例2：
1
输入样例3：
7 1000000
1 1 1 1 1 1 1
输出样例3：
7
```

# 有限小数