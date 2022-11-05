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

# AcWing 4715. 构造数组
