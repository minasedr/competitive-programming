class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack, rem = [], ""
        for i in range(len(s)):
            if s[i] != ')':
                stack.append(s[i])
            else:
                while stack[-1] != '(':
                    rem += stack.pop()
                stack.pop()
            for j in rem:
                stack.append(j)
            rem = ""
        return "".join(stack)
