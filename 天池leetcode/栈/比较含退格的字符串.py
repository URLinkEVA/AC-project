class Solution:
    
    def get_string(self, s: str) -> str :
        stack = []
        for i in range(len(s)) :
            c = s[i]
            if c != '#' :
                stack.append(c) # 模拟入栈
            elif len(stack) > 0: # 栈非空才能弹栈
                stack.pop() # 模拟弹栈
        return str(stack)

    def backspaceCompare(self, s: str, t: str) -> bool:
        return self.get_string(s) == self.get_string(t)
        pass
