# 缺少的数
给定一个长度为 n−1 的数列 a1,a2,…,an−1。

数列中的元素两两不同，且都在 1∼n 的范围内。

请你计算，1∼n 中的哪一个数没有在数列中出现过。
## 输入格式
第一行包含一个整数 n。

第二行包含 n−1 个整数 a1,a2,…,an−1。

## 输出格式
输出 1∼n 中没有在数列中出现过的数。

## 数据范围
前三个测试点满足 2≤n≤10。

所有测试点满足 2≤n≤105，1≤ai≤n。

```
输入样例：
10
3 8 10 1 7 9 6 5 2
输出样例：
4
```


# 选区间
给定 n 个一类区间 (l1,i,r1,i)。

给定 m 个二类区间 (l2,i,r2,i)。

请你从一类区间中挑选一个区间，从二类区间中挑选一个区间。

要求，选出的两个区间之间的距离尽可能大。

请你输出最大可能距离。

关于两区间 (l1,r1) 和 (l2,r2) 之间的距离，我们规定：

- 如果两区间存在交集，则区间距离为 0。
- 如果两区间不存在交集，则区间距离为 |i−j| 的最小可能值，其中 l1≤i≤r1,l2≤j≤r2。
## 输入格式
第一行包含一个整数 n。

接下来 n 行，每行包含两个整数 l1,i,r1,i。

再一行包含一个整数 m。

最后 m 行，每行包含两个整数 l2,i,r2,i。

## 输出格式
一个整数，表示最大可能距离。

## 数据范围
前三个测试点满足 1≤n,m≤10。

所有测试点满足 1≤n,m≤2×10^5，1≤l_1,i≤r_1,i≤10^9，1≤l_2,i≤r_2,i≤10^9。

## 输入样例1：
```
3
1 5
2 6
2 3
2
2 4
6 8
输出样例1：
3
```

# 选元素
给定一个长度为 n 的整数序列 a1,a2,…,an。

请你从中挑选 x 个元素，要求：

- 1.原序列中的每一个长度为 k 的连续子序列都至少包含一个被选中的元素。
- 2.满足条件 1 的前提下，所选 x 个元素的相加之和应尽可能大。

输出最大可能和。

## 输入格式
第一行包含三个整数 n,k,x。

第二行包含 n 个整数 a1,a2,…,an。

## 输出格式
如果无法满足题目要求，则输出 −1。

否则，输出一个整数，表示所选元素的最大可能和。

## 数据范围
前三个测试点满足 1≤k,x≤n≤6。

所有测试点满足 1≤k,x≤n≤200，1≤ai≤109。
```
输入样例1：
5 2 3
5 1 3 10 1
输出样例1：
18
输入样例2：
6 1 5
10 30 30 70 10 10
输出样例2：
-1
```
