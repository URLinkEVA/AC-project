# AcWing 4713. 反转字符串

## 使用algorithm中的reverse函数
```
string s = "hello";
reverse(s.begin(),s.end());
cout<<s<<endl;
```
## 自己编写
```
void Reverse(char *s, int n){
    for(int i = 0, j = n - 1; i < j; i++, j--){
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int main()
{
    char s[] = "hello";
    Reverse(s, 5);
    cout << s << endl;
    return 0;
}
```

# AcWing 4714. 数对
所有字符数量平方的相加
```
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long LL;
unordered_map <char,int> mp;
int main () {
    char ch;
    while (cin >> ch) mp[ch]++;
    LL ans = 0;
    for (char i = 'a';i <= 'z';i++) ans += (LL)mp[i] * mp[i];
    for (char i = '0';i <= '9';i++) ans += (LL)mp[i] * mp[i];
    cout << ans << endl;
    return 0;
}
```

# AcWing 4715. 构造数组
## 思路1并查集+图论
把所有的>,<>,<变成>>进行建边，然后每次求出最长路即可。

但这样会对8/10的，那该怎么办呢？

可以把所有相等的数合并成一个，也就是去除==，最后输出时直接输出他们的祖先的最长路。

这里可以用记忆化搜索，但是数据太水，直接过了。

## 两次遍历o(n)
```
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> a(n, 1);
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '<') a[i + 1] = a[i] + 1;
        else if (s[i] == '=') a[i + 1] = a[i];
    }
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] == '>') a[i] = max(a[i], a[i + 1] + 1);  // 狂wa7次
        else if (s[i] == '=') a[i] = a[i + 1];
    }

    for (const int& ai : a) { // 用ai去遍历a中元素，可以简单写为int ai : a
        cout << ai << ' ';
    }

    return 0;
}
```
### tips
'std::ios::sync_with_stdio(false);'在c++中之所以cin，cout效率低，是因为先把要输出的东西存入缓冲区，再输出，导致效率降低，而这段语句可以来打消iostream的输入和输出缓存，可节省时间，使效率与scanf与printf相差无几。

'cin.tie(nullptr);'在默认的情况下cin绑定的是cout，每次执行 << 操作符的时候都要调用flush，这样会增加IO负担。可以通过tie(0)（0表示NULL）来解除cin与cout的绑定，进一步加快执行效率。
