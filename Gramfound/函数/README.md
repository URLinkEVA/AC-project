# 例题
AcWing 804. n 的阶乘

AcWing 805. x和y的最大值

AcWing 808. 最大公约数
```
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
```

AcWing 811. 交换数值

AcWing 812. 打印数字

AcWing 813. 打印矩阵

AcWing 819. 递归求阶乘

AcWing 820. 递归求斐波那契数列


# 习题
AcWing 810. 绝对值

AcWing 806. 两个数的和

AcWing 807. 区间求和

AcWing 809. 最小公倍数
```
for (int i = 1; i <= a * b; i ++ )
    if(i%a==0&&i%b==0) return i;
```
AcWing 814. 复制数组
```
memcpy(b, a, size * 4);
```
AcWing 815. 打印字符串

AcWing 816. 数组翻转

AcWing 817. 数组去重

AcWing 818. 数组排序

AcWing 821. 跳台阶

AcWing 822. 走方格

AcWing 823. 排列
