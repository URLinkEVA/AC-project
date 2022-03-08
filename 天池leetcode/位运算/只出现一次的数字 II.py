class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        bitMap, ans = [0 for _ in range(32)], 0
        
        for num in nums:
            for i in range(32):
                if (num >> i) & 1:
                    bitMap[31 - i] += 1
        
        for i in range(32):
            if bitMap[i] % 3:
                if i == 0: # sign bit
                    ans -= 1 << (31 - i)
                else:
                    ans |= 1 << (31 - i)

        return ans