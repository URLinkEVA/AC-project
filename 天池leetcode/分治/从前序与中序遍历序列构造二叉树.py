# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        """
            1. 遍历 前序列表，因为 根左右的顺序，每次都遍历出来一个根节点
            2. 通过 中序列表，判断出来该节点的左右子节点

            比较规则：
            当前节点的 右边第一个节点：
            1. 如果在 中序列表中当前节点的左边， 那么它就是当前节点的左子节点
            2. 如果在 中序列表中当前节点的右边， 那么就要分情况：
                （1）如果在根节点的右边，那它一定是根节点的右部分，也就是右节点
                （2）如果还在根节点的左边， 那么它就是左子树的某个节点的 右子节点，经过分析实践（是它左边第一个节点）
                这点是最难的，归纳当前两条规律，实际上，它都是当前节点的左边第一个节点的右子节点！

            有了这两点，通过跌带，遍历前序列表， 很容易一步步判断出每一个为 根的当前节点的左右子节点，从而完成二叉树的创建！

            根据上述规律， 使用迭代的方式，利用栈辅助
        """
        stack = list()
        # 1. 创建根节点，根据前序
        root = TreeNode(preorder[0])
        stack.append(root)
        # 2. 为何提升查找效率，判断一个节点在另一个的左侧还是右侧， 提前构建 中序遍历的hash结构，数组索引为大小比较左右
        idxMap = dict()
        for i in range(len(inorder)): 
            idxMap[inorder[i]] = i
        # 3. 开始遍历 前序列表，创建二叉树
        for i in range(1, len(preorder)):
            pre = stack[-1]
            # 判断它是在上一节点的左侧还是右侧
            if idxMap.get(preorder[i]) < idxMap.get(preorder[i - 1]): # 在左
                pre.left = TreeNode(preorder[i])
                stack.append(pre.left)
            else: # 在右
                # 找到当前遍历节点中，左边离它最近的， 也就是当前栈中的节点，看它是哪个节点的右子节点
                while stack and idxMap.get(stack[-1].val) < idxMap.get(preorder[i]):
                    pre = stack.pop()
                pre.right = TreeNode(preorder[i])
                stack.append(pre.right)

        return root            
        