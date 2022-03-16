class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mini, maxProfit = prices[0], 0
        for i in range(1,len(prices)):
            maxProfit = max(maxProfit, prices[i] - mini)
            mini = min(mini, prices[i])
        return maxProfit
