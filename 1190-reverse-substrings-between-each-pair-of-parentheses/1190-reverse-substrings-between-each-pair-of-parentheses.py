class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []
        for ch in s:
            tmp = []
            if ch == ')':
                while stack and stack[-1] != '(':
                    tmp.append(stack.pop())
                stack.pop()
            else:            
                stack.append(ch)
            if tmp: stack.extend(tmp)
                
        return ''.join(stack)