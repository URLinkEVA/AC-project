给定一个 n×m 的整数矩阵，其中第 i 行第 j 列的元素为 aij。

你可以进行任意多次如下操作：

选择矩阵中的两个相邻元素，将它们均乘以 −1。

同一个元素可以被选中多次。

你需要通过上述操作，使得矩阵中所有元素的和尽可能大。

计算并输出这个和的最大可能值。

输入格式

第一行包含整数 T，表示共有 T 组测试数据。

每组数据第一行包含两个整数 n,m。

接下来 n 行，每行包含 m 个整数，表示整个矩阵，其中第 i 行第 j 列的数为 aij。

输出格式

每组数据输出一行结果，表示矩阵的所有元素的最大可能和。

数据范围

1≤T≤100,

2≤n,m≤10,

−100≤aij≤100

输入样例：

2

2 2

-1 1

1 1

3 4

0 -1 -2 -3

-1 -2 -3 -4

-2 -3 -4 -5

输出样例：

2

30
