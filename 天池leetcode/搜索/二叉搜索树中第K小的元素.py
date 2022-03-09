class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        count = 1
        stack = [root]
        while stack:
            i = stack.pop()
            if isinstance(i, TreeNode):
                stack.append(i.right)
                stack.append(i.val)
                stack.append(i.left)
            if isinstance(i, int):
                if count == k:
                    return i
                count += 1

# 中序遍历二叉搜索树的第K个元素即为第K小的元素
# 用count进行计数，相当于做了一次中序遍历