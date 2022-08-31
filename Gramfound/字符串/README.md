# 例题
AcWing 760. 字符串长度
```
for (int i = 0; str[i] && str[i] != '\n'; i ++ ) len ++ ;
```
AcWing 761. 字符串中的数字个数
```
fgets(str, 110, stdin);
```
AcWing 763. 循环相克令
```
if(x == (y+1)%3) cout << "Player1" << endl;
```
AcWing 765. 字符串加空格

AcWing 769. 替换字符

AcWing 773. 字符串插入
```
//substr从第一个参数开始到第二个参数结束
cout << str1.substr(0, p + 1) + str2 + str1.substr(p + 1) << endl;
```

AcWing 772. 只出现一次的字符


# 习题
AcWing 762. 字符串匹配
```
int cnt[26];
cnt[a[i]-'a']++;
```

AcWing 768. 忽略大小写比较字符串大小

AcWing 766. 去掉多余的空格
```
//双指针
int j = i;
while(j < s.size() && s[j] == ' ') j++;
i = j + 1;
```

AcWing 767. 信息加密
```
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    getline(cin ,s);
    for(auto &c : s)
    {
        if(c >= 'a' && c <= 'z') c = (c - 'a' + 1)%26 + 'a';
        else if(c >= 'A' && c <= 'Z') c = (c - 'A' + 1)%26 + 'A';
    }
    cout << s << endl;
    return 0;
}
```

AcWing 764. 输出字符串
```
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string a, b;
    getline(cin ,a);
    for(int i = 0; i < a.size(); i++) b += (a[i] + a[(i+1)% a.size()]);
    cout << b << endl;
    return 0;
}
```

AcWing 770. 单词替换
```
#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
    string s, a, b;
    getline(cin, s);
    cin >> a >> b;
    stringstream ssin(s);
    string str;
    while(ssin >> str)
        if(str == a) cout << b << ' ';
        else cout << str << ' ';
    
    return 0;
}
```

AcWing 771. 字符串中最长的连续出现的字符

AcWing 774. 最长单词

AcWing 775. 倒排单词

AcWing 776. 字符串移位包含问题

AcWing 777. 字符串乘方

AcWing 778. 字符串最大跨距

AcWing 779. 最长公共字符串后缀
