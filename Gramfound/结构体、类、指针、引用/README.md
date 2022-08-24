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
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val; // 伪装成下一个点
        node->next = node->next->next; // 删除下一个点
    }
};
```
## AcWing 36. 合并两个排序的链表
```
新建头部的保护结点dummy，设置cur指针指向dummy。
若当前l1指针指向的结点的值val比l2指针指向的结点的值val小，则令cur的next指针指向l1，且l1后移；否则指向l2，且l2后移。
然后cur指针按照上一部设置好的位置后移。
循环以上步骤直到l1或l2为空。
将剩余的l1或l2接到cur指针后边。

两个链表各遍历一次，所以时间复杂度为O(n)
```
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dum = new ListNode(0);
        ListNode *cur = dum;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1 -> val < l2 -> val)
            {
                cur -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;
        }
        cur -> next = (l1 != NULL ? l1 : l2);
        return dum -> next;
    }
};
```

# 习题
## AcWing 78. 左旋转字符串
```
class Solution {
public:
    string leftRotateString(string str, int n) {
        return str.substr(n) + str.substr(0, n);
    }
};
```
## AcWing 87. 把字符串转换成整数
```
class Solution {
public:
    int strToInt(string str) {
        int i = 0;
        while(i < str.size() && str[i] == ' ') i++;
        long long res = 0;
        
        int sign = 1;
        if(i < str.size())
        {
            if(str[i] == '-') sign = -1, i++;
            else if (str[i] == '+') i++;
        }
        
        while(i < str.size() && str[i] >= '0' && str[i] <= '9')
        {
            res = res * 10 + str[i] - '0';
            if (res > 1e11) break;
            i ++ ;
        }
        
        res *= sign;
        if (res > INT_MAX) res = INT_MAX;
        if (res < INT_MIN) res = INT_MIN;

        return res;
    }
};
```

## AcWing 35. 反转链表
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        auto p= head, q = head->next;
        while(q)
        {
            auto o = q->next;
            q->next = p;
            p = q;
            q = o;
        }
        head->next = NULL;
        return p;
    }
};
```
### 翻转链表
https://leetcode.cn/problems/make-two-arrays-equal-by-reversing-sub-arrays/
```
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        return target == arr;
    }
};
```

## AcWing 66. 两个链表的第一个公共结点

## AcWing 29. 删除链表中重复的节点
