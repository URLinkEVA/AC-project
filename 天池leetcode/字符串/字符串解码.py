class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        for i in s:
            if i == ']':
                strs = ''
                repeat = ''
                while stack[-1] != '[':
                    strs = stack.pop() + strs
                stack.pop()
                while stack and stack[-1].isdigit():
                    repeat = stack.pop() + repeat
                stack.append(int(repeat) * strs)
                continue
            stack.append(i)
        return ''.join(stack)
