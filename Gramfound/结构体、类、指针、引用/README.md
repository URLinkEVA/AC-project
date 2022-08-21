# 例题
## AcWing 21. 斐波那契数列
```
//通项公式
int Fibonacci(int n) {
        double c1 = (1.0 + sqrt(5)) / 2, c2 = (1.0 - sqrt(5)) / 2;
        return (int)((pow(c1, n) - pow(c2, n)) / sqrt(5));
    }
```
## AcWing 16. 替换空格

```
// 线性扫描
class Solution {
public:
    string replaceSpaces(string &str) {
        string res;
        for (int i = 0; str[i]; i ++ ) // for (auto x : str)更方便
        {
            if(str[i] == ' ') res += "%20";
            else res += str[i];
        }
        return res;
    }
};
```
```
// 双指针
class Solution {
public:
    string replaceSpaces(string &str) {
        string res;
        for (int i = 0; str[i]; i ++ )
        {
            int j = i;
            while(j < str.size() && str[j] != ' ') j++;
            res += str.substr(i, j - i);
            if(j < str.size()) res += "%20";
            i = j;
        }
        return res;
    }
};
```

## AcWing 84. 求1+2+…+n
```
class Solution {
public:
    int getSum(int n) {
        int res = n;
        n > 0 && (res += getSum(n-1));
        return res;
    }
};
```

## AcWing 28. 在O(1)时间删除链表结点

## AcWing 36. 合并两个排序的链表

# 习题
## AcWing 78. 左旋转字符串

## AcWing 87. 把字符串转换成整数

## AcWing 35. 反转链表

## AcWing 66. 两个链表的第一个公共结点

## AcWing 29. 删除链表中重复的节点
