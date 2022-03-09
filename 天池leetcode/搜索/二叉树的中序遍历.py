# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def inOrder(self, root:TreeNode, res):
        if root == None:
            return
        self.inOrder(root.left, res)
        res.append(root.val)
        self.inOrder(root.right, res)

    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        self.inOrder(root, res)
        return res


# 递归就是一种循环，一种自己调用自己的循环
# 一道题你看能不能用递归实现，需要具备两个条件：
# 1.问题可以分为多个重复的子问题，子问题仅存在数据规模的差距。
# 2.存在终止条件。
