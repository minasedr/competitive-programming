class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        
        for c in s:
            if c == ']':
                cur = ""
                while (stack and stack[-1] != '['):
                    cur = stack.pop() + cur
                stack.pop()
                n, st = 0, ""
                
                while stack and stack[-1].isdigit():
                    st += stack.pop()
                stack.append((cur * int(st[::-1])))
            else:
                stack.append(c)
                
        return ''.join(stack)