# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        self.map = {j:i for i, j in enumerate(inorder)}
        self.postorder = postorder
        return self.func(0, len(postorder) - 1)
    
    def func(self, left, right):
        if left > right:
            return None
        else:
            value = self.postorder.pop()
            index = self.map[value]
            right_node = self.func(index + 1, right)
            left_node = self.func(left, index - 1)
            return TreeNode(value, left_node, right_node)