> 学习语言最好的方式就是实践，每当掌握一个新功能时，就要立即将这个功能应用到实践中。——闫学灿

# printf输出格式
注意：使用printf时最好添加头文件 #include <cstdio>。
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    printf("Hello World!");

    return 0;
}
```

## Int、float、double、char等类型的输出格式：
(1) int：%d

(2) float: %f, 默认保留6位小数

(3) double: %lf， 默认保留6位小数

(4) char: %c, 回车也是一个字符，用'\n'表示

```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a = 3;
    float b = 3.12345678;
    double c = 3.12345678;
    char d = 'y';

    printf("%d\n", a);
    printf("%f\n", b);
    printf("%lf\n", c);
    printf("%c\n", d);

    return 0;
}
```

## 所有输出的变量均可包含在一个字符串中：
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a = 3;
    float b = 3.12345678;
    double c = 3.12345678;
    char d = 'y';

    printf("int a = %d, float b = %f\ndouble c = %lf, char d = %c\n", a, b, c, d);

    return 0;
}
```
练习：输入一个字符，用这个字符输出一个菱形：
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char c;
    cin >> c;

    printf("  %c\n", c);
    printf(" %c%c%c\n", c, c, c);
    printf("%c%c%c%c%c\n", c, c, c, c, c);
    printf(" %c%c%c\n", c, c, c);
    printf("  %c\n", c);

    return 0;
}
```
练习：输入一个整数，表示时间，单位是秒。输出一个字符串，用”时:分:秒”的形式表示这个时间。
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;

    cin >> t;

    int hours = t / 3600;
    int minutes = t % 3600 / 60;
    int seconds = t % 60;

    printf("%d:%d:%d\n", hours, minutes, seconds);

    return 0;
}
```

## 扩展功能
### float, double等输出保留若干位小数时用：%.4f, %.3lf
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    float b = 3.12345678;
    double c = 3.12345678;

    printf("%.4f\n", b);
    printf("%.3lf\n", c);

    return 0;
}
```
### 最小数字宽度

a. %8.3f, 表示这个浮点数的最小宽度为8，保留3位小数，当宽度不足时在前面补空格。
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a = 3;
    float b = 3.12345678;
    double c = 3.12345678;

    printf("%5d\n", a);
    printf("%8.4f\n", b);
    printf("%7.3lf\n", c);

    return 0;
}
```
b. %-8.3f，表示最小宽度为8，保留3位小数，当宽度不足时在后面补上空格
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a = 3;
    float b = 3.12345678;
    double c = 3.12345678;

    printf("%-5d!\n", a);
    printf("%-8.4f!\n", b);
    printf("%-7.3lf!\n", c);

    return 0;
}
```
c. %08.3f, 表示最小宽度为8，保留3位小数，当宽度不足时在前面补上0
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a = 3;
    float b = 3.12345678;
    double c = 3.12345678;

    printf("%05d\n", a);
    printf("%08.4f\n", b);
    printf("%07.3lf\n", c);

    return 0;
}
```
# if 语句
## 基本if-else语句
当条件成立时，执行某些语句；否则执行另一些语句。
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a;
    cin >> a;

    if (a > 5)
    {
        printf("%d is big!\n", a);
        printf("%d + 1 = %d\n", a, a + 1);
    }
    else
    {
        printf("%d is small!\n", a);
        printf("%d - 1 = %d\n", a, a - 1);
    }

    return 0;
}
```
else 语句可以省略：
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a;
    cin >> a;

    if (a > 5)
    {
        printf("%d is big!\n", a);
        printf("%d + 1 = %d\n", a, a + 1);
    }

    return 0;
}
```

当只有一条语句时，大括号可以省略：
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a;
    cin >> a;

    if (a > 5)
        printf("%d is big!\n", a);
    else
        printf("%d is small!\n", a);

    return 0;
}
```
练习：输入一个整数，输出这个数的绝对值。
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int x;

    cin >> x;

    if (x > 0) cout << x << endl;
    else cout << -x << endl;

    return 0;
}
```

练习：输入两个整数，输出两个数中较大的那个。
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if (a > b)
        cout << a << endl;
    else
        cout << b << endl;

    return 0;
}
```

if-else语句内部也可以是if-else语句。

练习：输入三个整数，输出三个数中最大的那个。
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a > b)
    {
        if (a > c) cout << a << endl;
        else cout << c << endl;
    }
    else
    {
        if (b > c) cout << b << endl;
        else cout << c << endl;
    }

    return 0;
}
```
## 常用比较运算符
(1) 大于 >

(2) 小于 <

(3) 大于等于 >=

(4) 小于等于 <=

(5) 等于 ==

(6) 不等于 !=

```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    if (a > b) printf("%d > %d\n", a, b);
    if (a >= b) printf("%d >= %d\n", a, b);
    if (a < b) printf("%d < %d\n", a, b);
    if (a <= b) printf("%d <= %d\n", a, b);
    if (a == b) printf("%d == %d\n", a, b);
    if (a != b) printf("%d != %d\n", a, b);

    return 0;
}。
```
## if-else连写：
```
输入一个0到100之间的分数，
如果大于等于85，输出A；
如果大于等于70并且小于85，输出B；
如果大于等于60并且小于70，输出C；
如果小于60，输出 D；
```
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int s;
    cin >> s;

    if (s >= 85)
    {
        printf("A");
    }
    else if (s >= 70)
    {
        printf("B");
    }
    else if (s >= 60)
    {
        printf("C");
    }
    else
    {
        printf("D");
    }

    return 0;
}
```

练习：

1.简单计算器输入两个数，以及一个运算符+, -, *, /，输出这两个数运算后的结果。

当运算符是/，且除数是0时，输出Divided by zero!; 当输入的字符不是+, -, *, /时，输出Invalid operator!。

```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a, b;
    char c;
    cin >> a >> b >> c;

    if (c == '+') cout << a + b << endl;
    else if (c == '-') cout << a - b << endl;
    else if (c == '*') cout << a * b << endl;
    else if (c == '/')
    {
        if (b != 0)
        {
            cout << a / b << endl;
        }
        else
        {
            cout << "Divided by zero!" << endl;
        }
    }
    else
    {
        cout << "Invalid operator!" << endl;
    }

    return 0;
}
```

2.判断闰年。闰年有两种情况：

(1) 能被100整除时，必须能被400整除；

(2) 不能被100整除时，被4整除即可。

输入一个年份，如果是闰年输出yes，否则输出no。
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int year;
    cin >> year;

    if (year % 100 == 0)
    {
        if (year % 400 == 0) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    else
    {
        if (year % 4 == 0) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}
```

# 条件表达式
(1) 与 &&

(2) 或 ||

(3) 非 !

例题：输入三个数，输出三个数中的最大值。
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a >= b && a >= c) cout << a << endl;
    else if (b >= a && b >= c) cout << b << endl;
    else cout << c << endl;

    return 0;
}
```
练习：用一条if语句，判断闰年。
```
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int year;

    cin >> year;

    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}
```
