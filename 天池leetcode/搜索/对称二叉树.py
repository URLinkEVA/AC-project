# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        q = deque()
        q.append(root)
        while q:
            n = len(q)
            s = ""
            for i in range(n):
                node = q.popleft()
                if not node:
                    s += " "
                else:
                    s += chr(node.val+150)
                    q.append(node.left)
                    q.append(node.right)
            if s != s[::-1]:
                return False
        return True

# 数字的范围是-100 -- 100，通过ASCII码转为单个字符。然后利用二叉树的层序遍历，
# 并且在每一层的时候，对这个字符串是否是回文字符串进行判断
