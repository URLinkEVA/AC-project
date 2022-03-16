class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        # dp[i] : i天买卖股票能获得的最大利润
        # 遇到↑时：当天最大利润=dp[前一天]+差价
        # 遇到↓=时：当天最大利润=前一天最大利润

        dp = [0]*n
        for i in range(1,n):
            if prices[i]<=prices[i-1]: # 跌
                dp[i] = dp[i-1]
            if prices[i]>prices[i-1]: # 涨
                dp[i] = dp[i-1] + prices[i]-prices[i-1] # 之前的dp+差价

        return dp[-1]
