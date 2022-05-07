class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        
        for ch in num:
            while stack and k and stack[-1] > ch:
                stack.pop()
                k -= 1
            stack.append(ch)
        for _ in range(k):
            stack.pop()
        
        return ''.join(stack).lstrip('0') or "0"