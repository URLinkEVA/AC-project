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
