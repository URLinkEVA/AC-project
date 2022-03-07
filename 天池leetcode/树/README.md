# 数的定义与相关概念
## 从链表与图开始讲起
```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.next = next
        self.val = val
```
单链表：一个数据域+一个指针域

树：一个数据域+多个指针域

图：顶点集+边

树：无环连通图

## 数的定义
 树是N（N>=0）个节点的有限集合。N=0时为空树，N>0时应满足：
1. 有且仅有一个特定的称为根的节点
2. N>1时，其余节点可分为m(m>0)个互不相交的有限集合。其中，每一个有限集合自身也是一棵树。

## 树的相关概念
- 根节点：非空树处于最上层的唯一节点，其余节点都是它的子孙后代 
- 节点的度：节点具有的孩子节点个数
- 叶子节点：度为 0 的节点
- 父子节点：直接相连的一对节点， 处于上层的是父节点， 处于下层的是子节点
- 兄弟节点：由同一个父节点生出的不同节点互称兄弟节点
- 节点层次：由根开始记为1 层， 其子节点为2 层， 孙子节点为3 层“
- 节点深度：节点所在的层次数
- 树的深度/高度：树的最大层次数
- 节点高度：以节点为根的子树的深度/高度
- 有序树：以兄弟节点为根的子树交换位置得到的新树视作与原来的树不同的树
- 无序树：以兄弟节点为根的子树交换位置得到的新树视作与原来的树相同的树

## 简单又独特的树一一二叉树
### 定义
二叉树是一种每个节点度都不大于2的树。其中，每个节点的子节点有左右之分且左右子节点所在的子树不可以交换位置，即二叉树是一棵有序树

### 特殊的二叉树
#### 满二叉树
所有叶子节点全部在最底层，且所有非叶子节点度都是2的树

记满二叉树T高度为h，节点总数为n，n=2^h-1 ， 第k层节点总数为2^(k-1)

从1开始， 对T从上到下，从左到右进行编号。如果编号i的节点有父节点，则其父节点编号为[i/2], 如果有左子节点，则其左子节点编号为2i，如果有右子节点，则其右子节点编号为2i+1

#### 完全二叉树
记二叉树高度为h。从1开始，对二叉树从上到下，从左到右进行编号。对高度同为h的满二叉树做同样的编号处理。如果二叉树中所有节点的编号都能与满二叉树中同样位置的节点编号一致，则该二叉树是一棵完全二叉树。

完全二叉树的叶子节点只可能存在于最下面的两层中，且最下层的叶子节点全部是靠左紧密排列的

完全二叉树中父子节点之间的编号规律与满二叉树的规律完全相同，且编号大于[n/2]的节点必是叶子节点

如果n为奇数，则每个非叶子节点都有两个子节点；如果n为偶数，则第n/2个节点必为非叶子节点，且它只有左子结点而无右子节点，其余非叶子节点都有两个子节点

#### 二叉搜索树(BST) 
二叉搜索树要么是空树， 要么同时满足以下条件：
1. 左子树所有节点的关键字均小于根节点的关键字
2. 右子树所有节点的关键字均大于根节点的关键字
3. 左右子树也均为二叉搜索树

二叉搜索树经典的应用场景就是存放有序数据，提升查找效率

用同一个有序序列，可以构造出多个不同的二叉搜索树

#### 平衡二叉树(AVL)
如果二叉树中每个节点的左右子树高度差都不大于1，则这棵二叉树就是平衡二叉树

平衡二叉树经典的应用场景就是与二叉搜索树结合，形成平衡二叉搜索树。在构建二叉搜索树的同时借助调整策略使每个节点的左右子树高度差都不大于1，保证二叉搜素树中每个节点的左右子树都规模相当，整个树看起来更加“ 匀称“

# 树的基本操作
## 树的存储结构
### 顺序存储结构
| # | val | parent | children |
|---|-----|--------|----------|
| 0 | A   |  -1    |          |
| 1 | B   |   0    |          |

### 链式存储结构
```python
class Node:
    def __init__(self, val = None, children = None):
        self.val = val
        self.chhildren = children if children is not None else []
    
```
### 树的~~增删改查~~(查查查查)
查找/搜索/遍历是树的核心操作

遍历，按照某种规则" 访问" 树中的每个节点，保证每个节点都会被" 访问" 到且每个节点只会被" 访问" 一次

" 访问" ： 程序与节点产生交互或者在节点进行某些操作

" 进入" ： 程序来到了某个节点， 并未与该节点产生任何交互

不同规则下， 对同一个节点的“ 进入“ 次数可能有一次也可能有多次， 但对同一个节点的“ 访问" 只会发生一次

#### 二叉树的深度优先搜索(DFS)
在" 进入" 节点时有以下约定俗成的要求，
- 必须以根节点为搜索起始节点并" 进入"
- 优先" 进入" 当前节点的左子节点， 其次“ 进入“ 当前节点的右子节点
- 如果当前节点为空节点或者左右子节点都被" 进入" 过， 则再次" 进入' 父节点

" 进入“ 序列：1,2,4,null,4,null,4,2,5,null,5,null,5,2,1,3,null,3,6,null,6,null,6,3,1

```python
def dfs(TreeNode root):
    if not root: return # 当前节点为空，返回到父节点

    # 第一次进入当前节点
    dfs(root.left) # 优先进入左子节点
    # 第二次进入当前节点
    dfs(root.right) # 其次进入右子节点
    # 第三次进入当前节点
    return # 左右子节点全部进入过，返回到父节点
```
前中后序遍历
```python
# 先序遍历
def dfs(TreeNode root):
    if not root: return
    print(root.val)  # 访问
    dfs(root.left)
    dfs(root.right)
    return

# 中序遍历
def dfs(TreeNode root):
    if not root: return
    dfs(root.left)
    print(root.val)  # 访问
    dfs(root.right)
    return

# 后序遍历
def dfs(TreeNode root):
    if not root: return
    dfs(root.left)
    dfs(root.right)
    print(root.val)  # 访问
    return
```

#### 二叉树的广度优先搜索(BFS)
从根节点开始，按层次从上到下，同层次内从左到右"访问"每一个节点也叫做层次遍历

每个节点只会进入一次

要实现二叉树的广度有限搜索，需要借助一个特殊的数据结构一一队列

实现二叉树层次遍历的流程：
1. 初始化空队，将根节点入队
2. 当队列非空且队头元素非空时不断重复以下操作：

    - 队头节点出队并设置为当前节点
    - 对当前节点进行" 访问"
    - 如果当前节点左子节点存在则将左子节点入队
    - 如果当前节点右子节点存在则将右子节点入队

```python
# BFS
def bfs(self, root: Optional[TreeNode]):
    q = []    # 队列
    q.append(root)  # 队列初始化
    while len(q) and q[0]:
        cur = q.pop(0)
        print(cur.val) # 访问
        if root.left:
            q.append(root.left)
        if root.right:
            q.append(root.right)
    return

# 写法2
def bfs(self, root: Optional[TreeNode]):
    q = []    # 队列
    q.append(root)  # 队列初始化
    while len(q) and q[0]: # while内，for循环外负责控制层次级别操作
        size = len(q) # 记录当前层中节点的总数
        for i in range(size):  # for循环内部负责控制同一层内节点级别操作
            cur = q.pop(0)
            print(cur.val)  # 访问
            if root.left:
                q.append(root.left)
            if root.right:
                q.append(root.right)
    return
```

# 例题解析
## 二叉树的最大深度
> 给定一个二叉树，找出其最大深度。

> 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

> 说明: 叶子节点是指没有子节点的节点。

> 示例：给定二叉树 [3,9,20,null,null,15,7]，返回它的最大深度 3 。

### 思路
```python
class Solution:
    def dfs(self, root: Optional[TreeNode]):
        if not root:
            return
        self.dfs(root.left)
        self.dfs(root.right)
        return

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
```
### 实现代码
```pytohn
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root: Optional[TreeNode], temp: int,ansL:int):
        if not root:
            self.ans = max(self.ans, temp)
            return
        temp = temp + 1
        self.dfs(root.left, temp, self.ans)
        self.dfs(root.right, temp, self.ans)
        return

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        self.ans = 0
        temp = 0
        self.dfs(root, temp, self.ans)
        return self.ans
```
//52.00补


## 将有序数组转换为二叉搜索树
> 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。

> 高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

### 示例1
```
输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
```
### 示例2
```
输入：nums = [1,3]
输出：[3,1]
解释：[1,3] 和 [3,1] 都是高度平衡二叉搜索树。
```
 **二叉搜索树的中序遍历必有序** 

### 实现代码
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildBST(self, nums: List[int], lo: int, hi: int) -> TreeNode:
        if lo > hi:
            return None
        mid = int(lo + (hi - lo) / 2)
        root = TreeNode(nums[mid])
        root.left = self.buildBST(nums, lo, mid-1)
        root.right = self.buildBST(nums, mid+1, hi)
        return root

    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        lo, hi = 0, len(nums) - 1
        ans = self.buildBST(nums, lo ,hi)
        return ans
```

# 课后习题
## 二叉树的最小深度
> 给定一个二叉树，找出其最小深度。

> 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

> 说明：叶子节点是指没有子节点的节点。

### 示例1
```
输入：root = [3,9,20,null,null,15,7]
输出：2
```
### 示例2
```
输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
```

## 路径总和
> 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。

> 叶子节点 是指没有子节点的节点。

### 示例1
```
输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true
解释：等于目标和的根节点到叶节点路径存在。
```

### 示例2
```
输入：root = [1,2,3], targetSum = 5
输出：false
解释：树中存在两条根节点到叶子节点的路径：
(1 --> 2): 和为 3
(1 --> 3): 和为 4
不存在 sum = 5 的根节点到叶子节点的路径。
```

## 二叉搜索树迭代器
> 实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
- BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。
- boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
- int next()将指针向右移动，然后返回指针处的数字。
> 注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回 BST 中的最小元素。

> 你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。

### 示例
```
输入
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
输出
[null, 3, 7, true, 9, true, 15, true, 20, false]

解释
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // 返回 3
bSTIterator.next();    // 返回 7
bSTIterator.hasNext(); // 返回 True
bSTIterator.next();    // 返回 9
bSTIterator.hasNext(); // 返回 True
bSTIterator.next();    // 返回 15
bSTIterator.hasNext(); // 返回 True
bSTIterator.next();    // 返回 20
bSTIterator.hasNext(); // 返回 False
```

