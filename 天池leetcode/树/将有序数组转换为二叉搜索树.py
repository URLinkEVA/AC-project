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
