class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack, ans = [-1], 0
        
        for idx, ch in enumerate(s):
            if ch == '(':
                stack.append(idx)
            else:
                stack.pop()
                if not stack: stack.append(idx)
                else: ans = max(ans, idx - stack[-1])
        return ans