# 一、软件环境
自己动手

# 二、编写一个简单的C++程序——手速练习
```
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    return 0;
}
```

# 三、语法基础
## 变量的定义

变量必须先定义，才可以使用。不能重名。

变量定义的方式：
```
#include <iostream>

using namespace std;

int main()
{
    int a = 5;
    int b, c = a, d = 10 / 2;

    return 0;
}
```


## 输入输出
整数的输入输出：
```
#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
    return 0;
}
```
字符串的输入输出：
```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    cout << str;
    return 0;
}
```
输入输出多个不同类型的变量：
```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b;
    string str;

    cin >> a;
    cin >> b >> str;

    cout << str << " !!! " << a + b << endl;

    return 0;
}
```

## 表达式
整数的加减乘除四则运算：
```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a = 6 + 3 * 4 / 2 - 2;

    cout << a << endl;

    int b = a * 10 + 5 / 2;

    cout << b << endl;

    cout << 23 * 56 - 78 / 3 << endl;

    return 0;
}
```

浮点数（小数）的运算：
```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    float x = 1.5, y = 3.2;

    cout << x * y << ' ' << x + y << endl;

    cout << x - y << ' ' << x / y << endl;

    return 0;
}
```

整型变量的自增、自减：
```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a = 1;
    int b = a ++ ;

    cout << a << ' ' << b << endl;

    int c = ++ a;

    cout << a << ' ' << c << endl;

    return 0;
}
```

变量的类型转换：
```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    float x = 123.12;

    int y = (int)x;

    cout << x << ' ' << y << endl;

    return 0;
}
```

## 顺序语句
(1) 输出第二个整数：
```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << b << endl;
    return 0;
}
```

(2) 计算 (a + b) * c的值
```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    cout << (a + b) * c << endl;

    return 0;
}
```
(3) 带余除法
```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;

    int c = a / b, d = a % b;

    cout << c << ' ' << d << endl;

    return 0;
}
```
(4) 求反三位数：
```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a = n % 10;
    n = n / 10;
    int b = n % 10;
    n = n / 10;
    int c = n;

    cout << a << b << c << endl;

    return 0;
}
```
(5) 交换两个整数
```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a = 3, b = 4;

    int t = a;
    a = b;
    b = t;

    cout << a << ' ' << b << endl;

    return 0;
}
```
(6) 输出菱形
```
#include <iostream>
#include <string>

using namespace std;

int main()
{
    char c;

    cin >> c;

    cout << "  " << c << endl;
    cout << " " << c << c << c << endl;
    cout << c << c << c << c << c << endl;
    cout << " " << c << c << c << endl;
    cout << "  " << c << endl;

    return 0;
}
```
