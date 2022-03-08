class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        s = set()
        for i in range(n):
            if i > k:
                s.remove(nums[i - k - 1])
            if nums[i] in s:
                return True
            s.add(nums[i])
        return False

# 是否存在长度不超过的 k + 1k+1 窗口，窗口内有相同元素。
# 从前往后遍历 numsnums，同时使用 Set 记录遍历当前滑窗内出现过的元素。
# 假设当前遍历的元素为 nums[i]nums[i]：
# 下标小于等于 kk（起始滑窗长度还不足 k + 1k+1）：直接往滑窗加数，即将当前元素加入 Set 中；
# 下标大于 kk：将上一滑窗的左端点元素 nums[i - k - 1]nums[i−k−1] 移除，判断当前滑窗的右端点元素 nums[i]nums[i] 是否存在 Set 中，若存在，返回 True，否则将当前元素 nums[i]nums[i] 加入 Set 中。
# 重复上述过程，若整个 numsnums 处理完后仍未找到，返回 False。
