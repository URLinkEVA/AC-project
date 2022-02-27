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

# 课后习题
## 合并两个有序链表


## 相交链表



## 删除排序链表中的重复元素 II
