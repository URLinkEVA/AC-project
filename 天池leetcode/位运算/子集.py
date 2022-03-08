class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []
        for i in range(1 << n):
            tmp = []
            for j in range(n):
                if (i >> j) & 1:
                    tmp.append(nums[j])
            res.append(tmp)
        return res
