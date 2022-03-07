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