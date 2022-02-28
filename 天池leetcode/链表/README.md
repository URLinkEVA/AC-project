# 知识点介绍
## 单链表的逻辑结构与存储结构
- 逻辑结构：数据元素之间的逻辑关系

    集合、线性结构（一对一）、树形结构（一对多）、图结构（多对多）

- 存储结构：
    
    顺序存储、链式存储、索引存储、散列存储

    顺序存储（顺序表）：逻辑上相邻的元素物理位置也相邻

    链式存储（单链表）: 逻辑上相邻的元素物理位置不一定相邻

## 单链表的定义
```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
```
带头结点的单链表（写代码简单）
```python
head = ListNode()
head.next = t1
t1.next = t2 ... t10.next = None

head.next = None
head = ListNode(10)
```

## 插入元素
### 带头节点的单链表
```python
# 在第i个位置插入elem
def Insert(head, i, elem):
    assert i >= 0
    cur = head
    while i != 0:
        i -= 1
        cur = cur.next
        if not cur:
            return False
    temp = cur.next
    cur.next = elem
    elem.next = temp
    return True
```
### 不带头节点的单链表
```python
# 在第i个位置插入elem
def Insert(i,elem):
    global head
    assert i >= 0
    if i == 0:
        elem.next = head
        head = elem
    cur = head
    while i > 1:
        i -= 1
        cur = cur.next
        if not cur:
            return False
    temp = cur.next
    cur.next = elem
    elem.next = temp
    return True
```
### 删除元素
```python
# 删除元素
def ListDelete(head,i):
    assert i >= 0
    cur = head
    while i != 0:
        i -= 1
        cur = cur.next
        if not cur.next:
            return False
    cur.next = cur.next.next
    return True
```
## 创建单链表
### 带头节点的单链表
```python
def BuildLink_Tail(l):
    head = ListNode()
    temp = head
    for elem in l:
        temp.next = ListNode(elem)
        temp = temp.next
    return head

head = BuildLink_Tail([1,2,3,4])
while head.next:
    head = head.next
    print(head.val)
```

### 不带头节点的单链表
```python
def BuildLink_Tail(l):
    if not l:
        return None
    head = ListNode(l[0])
    temp = head
    for elem in l[1:]:
        temp.next = ListNode(elem)
        temp = temp.next
    return head

head = BuildLink_Tail([1,2,3,4])
while head.next:
    print(head.val)
    head = head.next

```
### 头插法创造单链表
#### 带头节点的单链表
```python
def BuildLink_Head(l):
    head = ListNode()
    for elem in l:
        temp = head.next
        head.next = ListNode(elem,temp)
    return head
```
#### 不带头节点的单链表
```python
def BuildLink_Head(l):
    head = None
    for elem in l:
        head = ListNode(elem,head)
    return head
```
## 双链表
解决单链表无法逆向索引的问题
```pytohn
class DLinkNode:
    def __init__(self, val = 0, next = None, prior):
        self.val = val
        self.next = next
        self.prior = prior
```
## 循环链表
### 循环单链表
从一个节点出发可以找到其他任何节点

### 循环双链表
从头找到尾和从尾找到头时间复杂度都是O（1）

# 例题解析
## 移除链表元素
> 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

### 示例
```
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
```

```python
# class ListNode:
#     def __init__(self, val = 0, next = None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        head = ListNode(next = head)
        pre = head
        while pre.next:
            if pre.next.val == val:
                pre.next = pre.next.next

            else:
                pre = pre.next
        return head.next
```
## 旋转链表
> 给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

### 示例1
```
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
```

### 示例2
```
输入：head = [0,1,2], k = 4
输出：[2,0,1]
```

```python
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int):
        if not head:
            return None
        length = 0
        temp = head
        while temp.next:
            length += 1
            temp = temp.next
        temp.next = head
        k = k % (length + 1)
        temp = head
        for i in range(length - k):
            temp = temp.next
        head = temp.next
        temp.next = None
        return head
```

# 课后习题
## 合并两个有序链表
> 将两个升序链表合并为一个新的 **升序** 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

### 示例1
```
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
```

### 示例2
```
输入：l1 = [], l2 = []
输出：[]
```

## 相交链表
> 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。

### 示例1
```
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
输出：Intersected at '8'
解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,6,1,8,4,5]。
在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
```

### 示例2
```
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。
由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
这两个链表不相交，因此返回 null 。
```


## 删除排序链表中的重复元素 II
> 给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。

### 示例1
```
输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
```

### 示例2
```
输入：head = [1,1,1,2,3]
输出：[2,3]
```
