class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        bucket = dict()

        for stone in stones:
            bucket[stone] = bucket.get(stone, 0) + 1
        
        return sum([bucket.get(jewel, 0) for jewel in jewels])

# 用一个哈希表记录石头每个有多少个个数
# 再对已有的宝石遍历，取出所有宝石个数的和，没有的用0填