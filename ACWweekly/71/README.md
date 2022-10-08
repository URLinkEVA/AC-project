# AcWing 4621. 三个整数
给定四个整数 a,b,c,d，保证 a≤b≤c≤d。

请你找到三个整数 x,y,z，使得它们满足：
- a≤x≤b
- b≤y≤c
- c≤z≤d
- x+y>z

## 输入格式
共一行，四个整数 a,b,c,d。

## 输出格式
共一行，三个整数 x,y,z。

保证一定有解。

如果方案不唯一，则输出任意合理方案均可。

## 数据范围
所有测试点满足 1≤a≤b≤c≤d≤100。
```
输入样例1：
1 3 5 7
输出样例1：
3 4 5
输入样例2：
1 5 5 7
输出样例2：
5 5 5
```

# AcWing 4622. 整数拆分
我们规定 f(x)（x≥2）表示整数 x 的除本身之外的最大因数。

例如，f(6)=3，f(25)=5，f(2)=1。

现在，给定一个整数 n，请你将其拆分为 k 份 n1,n2,…,nk（也可以不拆分，即 k=1），要求：

- n1+n2+…+nk=n
- 对于 1≤i≤k，ni≥2 始终成立。
- f(n1)+f(n2)+…+f(nk) 的值应尽可能小。
- 输出 f(n1)+f(n2)+…+f(nk) 的最小可能值。

## 输入格式
一个整数 n。

## 输出格式
一个整数，表示 f(n1)+f(n2)+…+f(nk) 的最小可能值。

## 数据范围
前 4 个测试点满足 2≤n≤30。

所有测试点满足 2≤n≤2×10^9。

```
输入样例1：
4
输出样例1：
2
输入样例2：
27
输出样例2：
3
```

# AcWing 4623. 买糖果
n  个糖果店，围成一圈。

店铺按顺时针顺序从 1 到 n 编号，n 号店铺与 1 号店铺相邻。

第 i 号店铺的单个糖果售价为 ai 元。

李华拿着 T 元钱去购买糖果，具体购买过程如下：

- 初始时，他位于 1 号店铺。

- 如果他现有的钱足够在当前店铺购买一个糖果，他就会立即购买一个糖果，否则他将不会在当前店铺购买糖果。随后，不论他是否在当前店铺购买糖果，他都会按顺时针顺序前往下一个店铺。

- 他将不断重复过程 2，直到剩余的钱在所有店铺都买不起糖果为止。

请问，最终李华一共购买到多少个糖果。

## 输入格式
第一行包含两个整数 n,T。

第二行包含 n 个整数 a1,a2,…,an。

## 输出格式
一个整数，表示一共购买到的糖果数量。

## 数据范围
前 6 个测试点满足 1≤n≤10。

所有测试点满足 1≤n≤2×10^5，1≤T≤10^18，1≤ai≤10^9。

```
输入样例1：
3 38
5 2 5
输出样例1：
10
输入样例2：
5 21
2 4 100 2 6
输出样例2：
6
```