class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        # for i in range(len(nums)):
        #     nums[i] = nums[i]**2
        # nums.sort()
        # return nums
        return sorted(num * num for num in nums)
