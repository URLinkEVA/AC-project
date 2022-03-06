class Solution:
    def convertToTitle(self, n: int) -> str:
        res = ""
        while n:
            n, y = divmod(n, 26) 
            if y == 0:
                n -= 1
                y = 26
            res = chr(y + 64) + res
        return res
