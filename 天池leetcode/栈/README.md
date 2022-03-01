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

//15.40





# 课后习题
## 最小栈


## 比较含退格的字符串


## 基本计算器 II
