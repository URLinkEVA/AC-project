# 栈简介
栈(stack):也称为堆栈。一种线性表数据结构，是一种只允许在表的一端进行进行插入和删除操作的线性表。

我们把栈中允许插入和删除的一端称为栈顶（top），另一端称为栈底（bottom），当表中没有任何数据元素时，称之为空栈。

堆栈有两种基本操作：插入操作和删除操作

- 栈的插入操作又称为入栈或者进栈
- 栈的删除操作又称为出栈或者退栈

栈是一种后进先出的线性表，栈中元素具有前驱后继的线性关系。栈中元素按照a1、a2...an的次序依次进栈。栈顶元素为an

# 栈的顺序存储与链式存储
和线性表类似，栈有两种存储表示方法：
- 顺序栈：即堆栈的顺序存储结构。利用一组地址连续的存储单元依次存放自栈底到栈顶的元素，同时使用指针 top 指示栈顶元素在顺序栈中的位置。

- 链式栈：即堆栈的链式存储结构。利用单链表的方式来实现堆栈。栈中元素按照插入顺序依次插入到链表的第一个节点之前，并使用栈顶指针 top 指示栈顶元素， top 永远指向链表的头节点位置。

## 栈的基本操作
- 初始化空栈
- 判断栈是否为空
- 判断栈是否已满
- 获取栈顶元素
- 插入元素（进栈，入栈）
- 删除元素（出栈，退栈）

## 栈的顺序存储
栈最简单的实现方式就是借助于一个数组来描述堆栈的顺序存储结构。在python中可以借助列表list来实现。

这种采用顺序存储结构的堆栈也被称为顺序栈。

### 栈的顺序存储基本描述
我们约定self.top指向栈顶元素所在位置

#### 初始化空栈
使用列表创造一个空栈，定义栈的大小self.size，并令栈顶元素指针self.top指向-1，即self.top = -1

#### 判断栈是否为空
当self.top == -1时，说明堆栈为空，返回True，否则返回False

#### 判断栈是否已满
当self.top == self.size-1，说明堆栈已满，返回True，否则返回False

#### 获取栈顶元素
先判断堆栈是否为空，为空直接抛出异常。不为空则返回self.top指向的栈顶元素，即self.stack[self.top]

#### 插入元素（进栈，入栈）
先判断堆栈是否已满，已满直接抛出异常。如果堆栈未满，则在self.stack末尾插入新的数据元素，并令self.top向右移动一位

#### 删除元素（出栈，退栈）
先判断堆栈是否为空，为空直接抛出异常。如果堆栈不为空，则先让self.top向左移动 1 位，然后再删除当前堆栈元素

### 栈的顺序存储实现代码
```python
class Stack:
    # 初始化空栈
    def __init__(self, size = 100):
        self.stack = []
        self.size = size
        self.top = -1

    # 判断栈是否为空
    def is_empty(self):
        return self.top == -1

    # 判断栈是否已满
    def is_full(self):
        return self.top + 1 == self.size

    # 入栈操作
    def push(self, value):
        if self.is_full():
            raise Exception('Stack is full')
        else:
            self.stack.append(value)
            self.top += 1

    # 出栈操作
    def pop(self):
        if self.is_empty():
            raise Exception('Stack is empty')
        else:
            self.top -= 1
            self.stack.pop()

    # 获取栈顶元素
    def peek(self):
        if self.is_empty():
            raise Exception('Stack is empty')
        else:
            return self.stack(self.top)
```
## 栈的链式存储
堆栈的顺序存储结构保留着顺序存储分配空间的固有缺陷，即在栈满或者其他需要重新调整存储空间时需要移动大量元素。为此，堆栈可以使用链式存储方式来实现。在python中我们通过构造链表节点 Node 的方式来实现。这种采用链式存储结构的堆栈也被称为链式栈。

### 栈的顺序存储基本描述
我们约定 self.top 指向栈顶元素所在节点

#### 初始化空栈
使用链表创造一个空栈，并令栈顶元素指针 self.top 指向 None ,即 self.top = None

#### 判断栈是否为空
当 self.top == None 时，说明堆栈为空，返回True，否则返回False

#### 判断栈是否已满


#### 获取栈顶元素
先判断堆栈是否为空，为空直接抛出异常。不为空返回 self.top 指向的栈顶节点值，即 self.top.value.

#### 插入元素（进栈，入栈）
创建值为value的链表节点，插入到链表头节点之前，并令栈顶指针 self.top 指向新的头节点

#### 删除元素（出栈，退栈）
先判断队列是否为空，为空直接抛出异常。如果堆栈不为空，则令 self.top 链表移动1位，并返回 self.top.value。

### 栈的链式存储实现代码
```python
class Node:
    def __init__(self,value):
        self.value = value
        self.next = None

class Stack:
    # 初始化空栈
    def __init__(self):
        self.top = None

    # 判断栈是否为空
    def is_empty(self):
        return self.top == None

    # 入栈操作
    def push(self, value):
        cur = Node(value)
        cur.next = self.top
        self.top = cur

    # 出栈操作
    def pop(self):
        if self.is_empty():
            raise Exception('Stack is empty')
        else:
            cur = self.top
            self.top = self.top.next
            del cur

    # 获取栈顶元素
    def peek(self):
        if self.is_empty():
            raise Exception('Stack is empty')
        else:
            return self.top.value
```
## 栈的应用
- 使用栈可以很方便的保存和取用信息

    常被用做算法或程序中的辅助存储结构，临时保存信息，供后面操作使用。

    例如操作系统中的函数调用栈，浏览器的前进后退功能

- 堆栈的后进先出的规则，可以保证特定的存储顺序

    例如翻转一组元素的顺序、铁路列车车辆调度

# 例题解析
## 有效的括号
> 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

> 有效字符串需满足：

> 左括号必须用相同类型的右括号闭合。

> 左括号必须以正确的顺序闭合。

### 示例1
```
输入：s = "()[]{}"
输出：true
```
### 示例2
```
输入：s = "([)]"
输出：false
```
### 实现代码
```python
class Solution:
    def isValid(self, s:str) -> bool:
        if len(s) % 2 == 1:
            return False
        stack = list()
        for ch in s:
            if ch == '(' or ch == '[' or ch == '{':
                stack.append(ch)
            elif ch == ')':
                if len(stack) != 0 and stack[-1] == '(':
                    stack.pop()
                else:
                    return False
            elif ch == ']':
                if len(stack) != 0 and stack[-1] == '[':
                    stack.pop()
                else:
                    return False
            elif ch == '}':
                if len(stack) != 0 and stack[-1] == '{':
                    stack.pop()
                else:
                    return False
        if len(stack) == 0:
            return True
        else:
            return False
```
### 解题思路
根据字符串长度，筛选掉奇数长度的字符串。

然后遍历字符串s。当遇到左括号时，将其入栈，当遇到右括号时，先判断当前栈顶元素是否是相同类型的左括号，如果是则将左括号出栈，继续向下遍历；如果不是直接返回False。

最后遍历完，判断一下栈是否为空，如果栈为空就匹配成功，返回True，没有就返回False。

## 逆波兰表达式求值
> 根据 逆波兰表示法，求表达式的值。

> 有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

> 注意 两个整数之间的除法只保留整数部分。

> 可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

### 示例1
```
输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
```

### 示例2
```
输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
输出：22
解释：该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```


### 解题思路
也称为后缀表达式，我们平常见到的表达式都是中缀表达式，写为 A 运算符 B，而后缀表达式写为 A B 运算符。

逆波兰表达式的计算遵循从左到右的规律，可以使用一个栈来存放当前的操作数，从左到右依次遍历逆波兰表达式并计算相应的值，具体操作如下：

- 使用列表stack作为栈存放操作数，然后遍历表达式的字符串数组

- 如果当前字符为运算符，则取出栈顶两个元素，在进行对应的运算之后，再将运算结果入栈

- 如果当前字符为数字，则直接将数字入栈

- 当遍历结束后，栈中最后剩余的元素，就是最终的计算结果。

### 实现代码
```python
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token == '+':
                stack.append(stack.pop() + stack.pop())
            elif token == '-':
                stack.append(-stack.pop() + stack.pop())
            elif token == '*':
                stack.append(stack.pop() * stack.pop())
            elif token == '/':
                stack.append(int(1/stack.pop()*stack.pop()))
            else:
                stack.append(int(token))
        return stack.pop()
```



# 课后习题
## 最小栈
> 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

> 实现 MinStack 类:

- MinStack() 初始化堆栈对象。
- void push(int val) 将元素val推入堆栈。
- void pop() 删除堆栈顶部的元素。
- int top() 获取堆栈顶部的元素。
- int getMin() 获取堆栈中的最小元素。

### 示例
```
输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
```

## 比较含退格的字符串
> 给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。

> 注意：如果对空文本输入退格字符，文本继续为空。

### 示例1
```
输入：s = "ab#c", t = "ad#c"
输出：true
解释：s 和 t 都会变成 "ac"。
```
### 示例2
```
输入：s = "ab##", t = "c#d#"
输出：true
解释：s 和 t 都会变成 ""。
```

## 基本计算器 II
> 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

> 整数除法仅保留整数部分。

### 示例1
```
输入：s = "3+2*2"
输出：7
```

### 示例2
```
输入：s = " 3/2 "
输出：1
```
