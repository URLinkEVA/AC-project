# 例题
AcWing 708. 偶数

AcWing 709. 奇数

AcWing 712. 正数

AcWing 714. 连续奇数的和

AcWing 716. 最大数和它的位置

AcWing 721. 递增序列

AcWing 720. 连续整数相加

while (cin >> n, n <= 0);

AcWing 724. 约数

a%i == 0说明i是a的因数

AcWing 723. PUM
```
输入样例：
7 4
输出样例：
1 2 3 PUM
5 6 7 PUM
9 10 11 PUM
13 14 15 PUM
17 18 19 PUM
21 22 23 PUM
25 26 27 PUM
```
```
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    for(int i = 0,k = 1;i < a;i++)
    {
        for(int j = 0;j < b-1;j++)
        {
            cout << k << ' ';
            k++;
        }
        cout << "PUM" << endl;
        k++;
    }
    return 0;
}
```
# 习题
AcWing 715. 余数

AcWing 710. 六个奇数

AcWing 711. 乘法表

AcWing 718. 实验

AcWing 713. 区间 2

AcWing 719. 连续奇数的和 2

AcWing 717. 简单斐波那契

AcWing 722. 数字序列和它的和

AcWing 725. 完全数

AcWing 726. 质数

AcWing 727. 菱形
