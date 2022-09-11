# 例题
## AcWing 67. 数字在排序数组中出现的次数
```
class Solution {
public:
    int getNumberOfK(vector<int>& nums, int k) {
        int cnt = 0;
        for (int x : nums)
            if (x == k)
                cnt ++ ;
        return cnt;
    }
};
```
## AcWing 68. 0到n-1中缺失的数字
```
class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        int l = 0, r = nums.size() - 1;
        while(l < r)
        {
            int mid = l + r >> 1;
            if(nums[mid] != mid) r = mid;
            else l = mid + 1;
        }
        
        if(nums[r] == r) r++;
        return r;
    }
};
```
```
class Solution {
public:
    int getMissingNumber(vector<int>& nums) {
        unordered_set<int> S;
        for(int i = 0; i <= nums.size(); i++) S.insert(i);
        for(auto x : nums) S.erase(x);
        return *S.begin();
    }
};
```
### 补充说明
l + r >> 1 是比特操作，可以看作除2

12的二进制表示是00001100,12>>1将00001100右移一位，变为00000110，即6

15的二进制表示是00001111,15>>1将00001111右移一位，变为00000111，即7

<<就是左移，相当于乘以2.


## AcWing 32. 调整数组顺序使奇数位于偶数前面
```
class Solution {
public:
    void reOrderArray(vector<int> &array) {
         int l =0, r = array.size() - 1;
         while(l < r)
         {
             while(l < r && array[l]%2 == 1) l++;
             while(l < r && array[r]%2 == 0) r--;
             swap(array[l], array[r]);
         }
    }
};
```

## AcWing 17. 从尾到头打印链表
```
// 法一：reverse 答案数组. 时间:O(n);空间:O(n). 4ms; 8.5MB
class Solution {
public:
    vector<int> printListReversingly(ListNode* head) {
        vector<int> res;
        while (head) {
            res.push_back(head->val);
            head = head->next;
        }
        // reverse(res.begin(), res.end());
        // return res;
        return vector<int>(res.rbegin(), res.rend());
    }
};

// 法二：递归. 时间:O(n);空间:栈空间O(n). 4ms; 10.8MB
class Solution {
public:
    vector<int> printListReversingly(ListNode* head) {
        if (!head) return {};
        auto res = printListReversingly(head->next);
        res.push_back(head->val);
        return res;
    }
};

// 法三：辅助栈法. 时间:O(n);空间:O(n). 4ms; 8.5MB
class Solution {
public:
    vector<int> printListReversingly(ListNode* head) {
        stack<int> s;
        while (head) {
            s.push(head->val); // 存的是 val
            head = head->next;
        }

        int n = s.size();
        vector<int> res(n);
        for (int i = 0; i < n; i ++ ) {
            res[i] = s.top();
            s.pop();
        }

        return res;
    }
};
```

## AcWing 20. 用两个栈实现队列
```
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> stk, cache;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk.push(x);
    }
    
    void copy(stack<int> &a, stack<int> &b)
    {
        while (a.size()) {
            b.push(a.top());
            a.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        copy(stk, cache);
        int res = cache.top();
        cache.pop();
        copy(cache, stk);
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        copy(stk, cache);
        int res = cache.top();
        copy(cache, stk);
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
```
# 习题
## AcWing 53. 最小的k个数
```
class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(), input.end());
        vector<int> res;
        for (int i = 0; i < k; i ++ ) res.push_back(input[i]);
        return res;
    }
};
```

```
class Solution {
public:
    vector<int> getLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(), input.end());
        input.resize(k);
        return input;
    }
};
```

## AcWing 75. 和为S的两个数字
```
class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        unordered_set<int> S;
        for(auto x: nums)
        {
            if(S.count(target - x)) return {x, target - x};
            S.insert(x);
        }
    }
};
```
```
class Solution {
public:
    vector<int> findNumbersWithSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(auto x : nums)
        {
            if(hash[target - x] == 0) hash[x]++;
            else return {x, target - x};
        }
        return {};
    }
};
```

## AcWing 51. 数字排列
```
class Solution {
public:
    vector<vector<int>> permutation(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do res.push_back(nums);
        while(next_permutation(nums.begin(), nums.end())); //调用的库函数，从小到大排

        return res;
    }
};
```
```
state >> i & 1 //判断第i位是否为1
```
## AcWing 26. 二进制中1的个数
```
class Solution {
public:
    int NumberOf1(int n) {
        int res = 0;
        for(int i = 0; i < 32; i++)
            if(n >> i & 1) res++;
            
        return res;
    }
};
```

## AcWing 862. 三元组排序
```
class Solution {
public:
    int NumberOf1(int n) {
        int res = 0;
        for(int i = 0; i < 32; i++)
            if(n >> i & 1) res++;
            
        return res;
    }
};
```
```
// lowbit写法
while (n) n -= n & -n, res ++ ;
```
