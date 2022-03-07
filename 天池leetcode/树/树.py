# 链表
from asyncio import ReadTransport


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# 链式存储结构
class Node:
    def __init__(self, val = None, children = None):
        self.val = val
        self.chhildren = children if children is not None else []
    
# DFS
def dfs(TreeNode root):
    if not root: return # 当前节点为空，返回到父节点

    # 第一次进入当前节点
    print(root.val)
    dfs(root.left) # 优先进入左子节点
    # 第二次进入当前节点
    dfs(root.right) # 其次进入右子节点
    # 第三次进入当前节点
    return # 左右子节点全部进入过，返回到父节点

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
